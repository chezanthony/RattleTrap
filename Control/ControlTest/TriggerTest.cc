#include <gtest/gtest.h>
#include "BaseTest.cc"
#include "Trigger.h"

class TriggerTest : public BaseTest
{
public:
    TriggerTest() : m_trigger(m_mockComponent, m_boolDeviceValue)
    {
    }

    ~TriggerTest() override {}

protected:
    Trigger m_trigger;
};

TEST_F(TriggerTest, TestConstructorVerifyComponentInitialized)
{
    ASSERT_TRUE(m_mockComponent == m_trigger.getComponent());
}

TEST_F(TriggerTest, TestConstructorVerifyDeviceValueInitialized)
{
    ASSERT_TRUE(m_boolDeviceValue == m_trigger.getDeviceValue());
}

TEST_F(TriggerTest, TestCopyConstructorVerifyComponentEqual)
{
    Trigger copiedTrigger(m_trigger);

    ASSERT_TRUE(m_mockComponent == copiedTrigger.getComponent());
}

TEST_F(TriggerTest, TestCopyConstructorVerifyDeviceValueEqual)
{
    Trigger copiedTrigger(m_trigger);

    ASSERT_TRUE(m_boolDeviceValue == copiedTrigger.getDeviceValue());
}
