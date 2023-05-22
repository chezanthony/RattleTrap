#ifndef BASE_TEST_H
#define BASE_TEST_H

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>
#include "DeviceValue.h"
#include "MockComponent.cc"
#include "Event.h"
#include "Trigger.h"

using std::make_unique;
using std::string;
using std::unique_ptr;
using std::vector;
using ::testing::Return;

class BaseTest : public testing::Test
{
public:
    BaseTest() : m_bTestBool(false),
                 m_nTestInt(7),
                 m_cTestChar('a'),
                 m_sTestString("This is a test string."),
                 m_boolDeviceValue(m_bTestBool),
                 m_intDeviceValue(m_nTestInt),
                 m_charDeviceValue(m_cTestChar),
                 m_stringDeviceValue(m_sTestString),
                 m_pMockComponent(make_unique<MockComponent>()),
                 m_boolEvent(m_mockComponent, m_boolDeviceValue),
                 m_intEvent(m_mockComponent, m_intDeviceValue),
                 m_charEvent(m_mockComponent, m_charDeviceValue),
                 m_stringEvent(m_mockComponent, m_stringDeviceValue),
                 m_boolTrigger(m_mockComponent, m_boolDeviceValue),
                 m_intTrigger(m_mockComponent, m_intDeviceValue)
    {
    }

    ~BaseTest() override {}

protected:
    void SetUp(void) override
    {
        m_theDeviceValues = {
            m_defaultDeviceValue,
            m_boolDeviceValue,
            m_intDeviceValue,
            m_charDeviceValue,
            m_stringDeviceValue,
        };

        ON_CALL(m_mockComponent, copy())
            .WillByDefault(Return(m_pMockComponent.get()));
    }

    void TearDown(void) override
    {
    }

    const bool m_bTestBool;
    const int m_nTestInt;
    const char m_cTestChar;
    const string m_sTestString;
    DeviceValue m_defaultDeviceValue;
    DeviceValue m_boolDeviceValue;
    DeviceValue m_intDeviceValue;
    DeviceValue m_charDeviceValue;
    DeviceValue m_stringDeviceValue;
    MockComponent m_mockComponent;
    unique_ptr<IComponent> m_pMockComponent;
    Event m_defaultEvent;
    Event m_boolEvent;
    Event m_intEvent;
    Event m_charEvent;
    Event m_stringEvent;
    Trigger m_defaultTrigger;
    Trigger m_boolTrigger;
    Trigger m_intTrigger;
    Trigger m_charTrigger;
    Trigger m_stringTrigger;
    vector<DeviceValue> m_theDeviceValues;
};

#endif // BASE_TEST_H
