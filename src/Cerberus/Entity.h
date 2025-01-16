#pragma once // Header only included once 

#include <memory> //    Include memory management 
#include <vector> //    Include vector 
#include "Component.h" //   Include the component class

class Core; //  Declare the core class

//  Sharable entity class to manage components 
class Entity : public std::enable_shared_from_this<Entity> {
public:

    //  Template method 
    //  T is the type of the component, Args are the arguments passed to the components constructor 
    template <typename T, typename... Args>
    std::shared_ptr<T> addComponent(Args&&... args) {
        auto component = std::make_shared<T>(std::forward<Args>(args)...); // Create a new component 
        component->entity = shared_from_this(); //  Set the entity pointer of the component 
        components.push_back(component); // Add the component to the list 
        return component; //    Return newly created component 
    }

    //Template Method 
    //  T is the type of the component 
    template <typename T>
    std::shared_ptr<T> getComponent() {
        for (const auto& component : components) { //   Iterate over all components
            auto casted = std::dynamic_pointer_cast<T>(component); // Try tp cast the component to the requested type 
            if (casted) {
                return casted; //   return component if cast is successful 
            }
        }
        return nullptr; //  Return nullptr if requested component type not found 
    }

    //  Method called on each update cycle 
    void tick();

    // Method called during the rendering phase 
    void render();

private:
    std::vector<std::shared_ptr<Component>> components; //  List of components added to the entity  
    std::weak_ptr<Core> core; //    Weak ptr to the core to allow core to access this member 
    friend class Core; //   Allow core to access private members of Entity 
};





