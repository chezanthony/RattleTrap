#ifndef TRIGGER_EXECUTION_STATEMENT_H
#define TRIGGER_EXECUTION_STATEMENT_H

#include "DeviceValue.h"

class IComponent;
class IOutputComponent;

// Used to declaratively define device readings
//  and corresponding device output.
class TriggerExecutionStatement final
{
public:
    TriggerExecutionStatement(IComponent &inputComponent) : m_pInputComponent(&inputComponent)
    {
    }

    TriggerExecutionStatement(
        IComponent &inputComponent,
        IOutputComponent &outputComponent,
        DeviceValue &deviceReading,
        DeviceValue &deviceOutput) : m_pInputComponent(&inputComponent),
                                     m_pOutputComponent(&outputComponent),
                                     m_deviceReading(deviceReading),
                                     m_deviceOutput(deviceOutput)
    {
    }

    TriggerExecutionStatement(const TriggerExecutionStatement &rhs) : m_pInputComponent(rhs.m_pInputComponent),
                                                                      m_pOutputComponent(rhs.m_pOutputComponent),
                                                                      m_deviceReading(rhs.m_deviceReading),
                                                                      m_deviceOutput(rhs.m_deviceOutput)
    {
    }

    ~TriggerExecutionStatement() {}

    TriggerExecutionStatement &isLow(void)
    {
        m_deviceReading = DeviceValue(false);
        return *this;
    }

    TriggerExecutionStatement &isHigh(void)
    {
        m_deviceReading = DeviceValue(true);
        return *this;
    }

    TriggerExecutionStatement &reads(const DeviceValue &deviceInput)
    {
        m_deviceReading = deviceInput;
        return *this;
    }

    TriggerExecutionStatement &then(IOutputComponent &outputComponent)
    {
        m_pOutputComponent = &outputComponent;
        return *this;
    }

    void writes(const DeviceValue &deviceOutput)
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

#endif // TRIGGER_EXECUTION_STATEMENT_H
