#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include "IEventListener.h"
#include "DeviceValue.h"

class IEventListener;
class IPhysical;

class EventListener : public IEventListener
{
public:
    EventListener(IPhysical &component, DeviceValue value) : m_pComponent(&component),
                                                             m_value(value)
    {
    }

    EventListener(const EventListener &rhs) : m_pComponent(rhs.m_pComponent),
                                              m_value(rhs.m_value)
    {
    }

    ~EventListener() override {}

    void notify(Event &event) override
    {
    }

    IEventListener *copy(void) const
    {
        return new EventListener(*this);
    }

private:
    IPhysical *m_pComponent;
    DeviceValue m_value;
};

#endif // EVENT_LISTENER_H