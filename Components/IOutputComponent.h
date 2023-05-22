#ifndef IOUTPUT_COMPONENT_H
#define IOUTPUT_COMPONENT_H

#include "IComponent.h"
#include "DeviceValue.h"

// class DeviceValue;

class IOutputComponent : public IComponent
// class IOutputComponent
{
public:
    IOutputComponent() {}
    virtual ~IOutputComponent() {}

    // Write the device value to the output component.
    virtual void write(const DeviceValue &rhs) = 0;
};

#endif // IOUTPUT_COMPONENT_H
