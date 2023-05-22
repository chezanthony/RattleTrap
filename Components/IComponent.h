#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include "ICopiable.h"

class DeviceValue;

// Interface for components.
class IComponent : public ICopiable<IComponent>
{
public:
    IComponent() {}
    virtual ~IComponent() {}

    // Read the component reading (for input components)
    //  or the last value written to the component (for output components).
    virtual const DeviceValue read(void) const = 0;
};

#endif // ICOMPONENT_H
