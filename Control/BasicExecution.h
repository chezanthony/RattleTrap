#ifndef EXECUTION_H
#define EXECUTION_H

#include "IExecution.h"
#include "EventStatement.h"
#include "Trigger.h"
#include "IOutputComponent.h"
#include "DeviceValue.h"

// Ordinary implementation of IExecution.
class BasicExecution : public IExecution
{
public:
    BasicExecution(EventStatement &eventStatement) : m_trigger(eventStatement.getInputComponent(),
                                                               eventStatement.getReading()),
                                                     m_pOutputComponent(&eventStatement.getOutputComponent()),
                                                     m_deviceValue(eventStatement.getOutput())
    {
    }

    BasicExecution(const BasicExecution &rhs) : m_trigger(rhs.m_trigger),
                                                m_pOutputComponent(rhs.m_pOutputComponent),
                                                m_deviceValue(rhs.m_deviceValue)
    {
    }

    ~BasicExecution() override {}

    void operator=(const BasicExecution &rhs)
    {
        m_trigger = rhs.m_trigger;
        m_pOutputComponent = rhs.m_pOutputComponent;
        m_deviceValue = rhs.m_deviceValue;
    }

    bool operator==(const BasicExecution &rhs)
    {
        return (m_trigger == rhs.m_trigger);
    }

    void execute(void)
    {
        m_pOutputComponent->write(m_deviceValue);
    }

    IExecution *copy(void) const override
    {
        return new BasicExecution(*this);
    }

    Trigger getTrigger(void) const
    {
        return m_trigger;
    }

    IOutputComponent &getOutputComponent(void) const
    {
        return *m_pOutputComponent;
    }

    DeviceValue getDeviceValue(void) const
    {
        return m_deviceValue;
    }

private:
    Trigger m_trigger;
    IOutputComponent *m_pOutputComponent;
    DeviceValue m_deviceValue;
};

#endif // EXECUTION_H
