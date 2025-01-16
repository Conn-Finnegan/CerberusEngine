#pragma once // This ensures that the header file is only included once in the program

#include <memory> //Included for the use of smart pointers such as std::weak_ptr

class Entity;

class Component {

public:

    virtual void onInit() {}    // called during the initiallisation of component 
    virtual void onTick() {}    // called during each update cycle
    virtual void onRender() {}  // called during the rendering phase of the program
    virtual ~Component() = default; // ensures the proper cleanup of derived classes

protected:

    std::weak_ptr<Entity> entity;   // weak pointer the the parent entity to protect against memory leaks.
    friend class Entity;          // provides the entity class with access to component's private and protected members
};

