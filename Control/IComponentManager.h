#ifndef ICOMPONENT_MANAGER_H
#define ICOMPONENT_MANAGER_H

#include <utility>
#include "DeviceValue.h"

using std::pair;

class IComponent;

typedef std::pair<IComponent &, DeviceValue> componentValuePair;

// Interface for ComponentManager.
// Serves as Component interface to the main Machine.
class IComponentManager
{
public:
    IComponentManager() {}
    virtual ~IComponentManager() {}

    // Add the Component to the ComponentRepository.
    virtual void addComponent(IComponent &component) = 0;

    // // Update the input Component readings.
    // virtual void updateReadings(void) = 0;

    // // Return the reading for the corresponding Component.
    // virtual DeviceValue getReading(IComponent &component) = 0;
};

#endif // ICOMPONENT_MANAGER_H
