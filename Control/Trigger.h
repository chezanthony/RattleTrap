#ifndef TRIGGER_H
#define TRIGGER_H

#include "IComponent.h"
#include "DeviceValue.h"

class Trigger
{
public:
    Trigger() {}

    Trigger(IComponent &component, DeviceValue &deviceValue) : m_pComponent(&component),
                                                               m_deviceValue(deviceValue)
    {
    }

    Trigger(const Trigger &rhs) : m_pComponent(rhs.m_pComponent),
                                  m_deviceValue(rhs.m_deviceValue)
    {
    }

    ~Trigger() {}

    bool operator==(const Trigger &rhs) const
    {
        return (m_pComponent == rhs.m_pComponent &&
                m_deviceValue == rhs.m_deviceValue);
    }

    const IComponent &getComponent(void)
    {
        return *m_pComponent;
    }

    DeviceValue getDeviceValue(void)
    {
        return m_deviceValue;
    }

private:
    IComponent *m_pComponent;
    DeviceValue m_deviceValue;
};

#endif // TRIGGER_H
