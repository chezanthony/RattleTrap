#ifndef EVENT_STATEMENT_H
#define EVENT_STATEMENT_H

#include <memory>
#include <string>
#include "DeviceValue.h"

using std::string;
using std::unique_ptr;

// class IPhysical;
class IComponent;
class IOutputComponent;

// Used to declaratively define device readings
//  and corresponding device output.
class EventStatement final
{
public:
    EventStatement(IComponent &inputComponent) : m_pInputComponent(&inputComponent)
    {
    }

    EventStatement(
        IComponent &inputComponent,
        IOutputComponent &outputComponent) : m_pInputComponent(&inputComponent),
                                             m_pOutputComponent(&outputComponent)
    {
    }

    EventStatement(
        IComponent &inputComponent,
        IOutputComponent &outputComponent,
        DeviceValue &deviceReading,
        DeviceValue &deviceOutput) : m_pInputComponent(&inputComponent),
                                     m_pOutputComponent(&outputComponent),
                                     m_deviceReading(deviceReading),
                                     m_deviceOutput(deviceOutput)
    {
    }

    EventStatement(const EventStatement &rhs) : m_pInputComponent(rhs.m_pInputComponent),
                                                m_pOutputComponent(rhs.m_pOutputComponent),
                                                m_deviceReading(rhs.m_deviceReading),
                                                m_deviceOutput(rhs.m_deviceOutput)
    {
    }

    ~EventStatement() {}

    EventStatement &isLow(void)
    {
        m_deviceReading = DeviceValue(false);
        return *this;
    }

    EventStatement &isHigh(void)
    {
        m_deviceReading = DeviceValue(true);
        return *this;
    }

    EventStatement &reads(const DeviceValue &deviceInput)
    {
        m_deviceReading = deviceInput;
        return *this;
    }

    void then(const DeviceValue &deviceOutput)
    {
        m_deviceOutput = deviceOutput;
    }

    DeviceValue getReading(void) const
    {
        return m_deviceReading;
    }

    DeviceValue getOutput(void) const
    {
        return m_deviceOutput;
    }

    IComponent &getInputComponent(void) const
    {
        return *m_pInputComponent;
    }

    IOutputComponent &getOutputComponent(void) const
    {
        return *m_pOutputComponent;
    }

private:
    IComponent *m_pInputComponent;
    IOutputComponent *m_pOutputComponent;
    DeviceValue m_deviceReading;
    DeviceValue m_deviceOutput;
};

#endif // EVENT_STATEMENT_H
