#ifndef ICOMPONENT_REPOSITORY_H
#define ICOMPONENT_REPOSITORY_H

#include "DeviceValue.h"

class IComponent;

// Storage for all declared Components.
// Takes ownership of the Components and handles their memory management.
class IComponentRepository
{
public:
    IComponentRepository() {}
    virtual ~IComponentRepository() {}

    // Store the Component.
    virtual void addComponent(IComponent &component) = 0;
};

#endif // ICOMPONENT_REPOSITORY_H
