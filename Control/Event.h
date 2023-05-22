#ifndef EVENT_H
#define EVENT_H

#include "IComponent.h"
#include "DeviceValue.h"

// Events are device readings from specific components
//  that can trigger component outputs.
class Event
{
public:
    Event() {}

    Event(
        IComponent &component,
        DeviceValue deviceValue) : m_pComponent(&component),
                                   m_deviceValue(deviceValue)
    {
    }

    Event(const Event &rhs) : m_pComponent(rhs.m_pComponent),
                              m_deviceValue(rhs.m_deviceValue)
    {
    }

    ~Event()
    {
        m_pComponent = nullptr;
    }

    bool operator==(const Event &rhs) const
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

#endif // EVENT_H
