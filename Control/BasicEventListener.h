#ifndef BASIC_EVENT_LISTENER_H
#define BASIC_EVENT_LISTENER_H

#include "IEventListener.h"
#include "IOutputComponent.h"
#include "EventStatement.h"
#include "Event.h"

class BasicEventListener : public IEventListener
{
public:
    BasicEventListener(EventStatement &eventStatement) : m_event(eventStatement.getInputComponent(),
                                                                 eventStatement.getReading()),
                                                         m_pOutputComponent(&eventStatement.getOutputComponent()),
                                                         m_deviceValue(eventStatement.getOutput())
    {
    }

    BasicEventListener(const BasicEventListener &rhs) : m_event(rhs.m_event),
                                                        m_pOutputComponent(rhs.m_pOutputComponent),
                                                        m_deviceValue(rhs.m_deviceValue)
    {
    }

    ~BasicEventListener() override {}

    void operator=(const BasicEventListener &rhs)
    {
        m_event = rhs.m_event;
        m_pOutputComponent = rhs.m_pOutputComponent;
        m_deviceValue = rhs.m_deviceValue;
    }

    bool operator==(const BasicEventListener &rhs)
    {
        return (m_event == rhs.m_event &&
                m_pOutputComponent == rhs.m_pOutputComponent &&
                m_deviceValue == rhs.m_deviceValue);
    }

    void notify(Event &event) override
    {
        if (event == m_event)
            m_pOutputComponent->write(m_deviceValue);
    }

    IEventListener *copy(void) const override
    {
        return new BasicEventListener(*this);
    }

    Event getEvent(void) const
    {
        return m_event;
    }

    IOutputComponent &getOutputComponent(void) const
    {
        return *m_pOutputComponent;
    }

    DeviceValue getDeviceValue(void) const
    {
        return m_deviceValue;
    }

    Event m_event;
    IOutputComponent *m_pOutputComponent;
    DeviceValue m_deviceValue;
};

#endif BASIC_EVENT_LISTENER_H
