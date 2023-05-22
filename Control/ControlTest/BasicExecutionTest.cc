#include <gtest/gtest.h>
#include "BaseTest.cc"
#include "BasicExecution.h"
#include "MockOutputComponent.cc"

class BasicExecutionTest : public BaseTest
{
public:
    BasicExecutionTest() : m_eventStatement(m_mockComponent,
                                            m_mockOutputComponent,
                                            m_boolDeviceValue,
                                            m_intDeviceValue),
                           m_trigger(m_mockComponent, m_boolDeviceValue),
                           m_basicExecution(m_eventStatement)
    {
    }

    ~BasicExecutionTest() override {}

protected:
    MockOutputComponent m_mockOutputComponent;
    EventStatement m_eventStatement;
    Trigger m_trigger;
    BasicExecution m_basicExecution;
};

TEST_F(BasicExecutionTest, TestConstructorVerifyTrigger)
{
    const Trigger actualTrigger = m_basicExecution.getTrigger();
}

TEST_F(BasicExecutionTest, TestConstructorVerifyOutputComponent)
{
    const IOutputComponent &actualOutputCOmponent =
        m_basicExecution.getOutputComponent();

    ASSERT_TRUE(m_mockOutputComponent == actualOutputCOmponent);
}

TEST_F(BasicExecutionTest, TestConstructorVerifyDeviceValue)
{
    const DeviceValue actualDeviceValue =
        m_basicExecution.getDeviceValue();

    ASSERT_EQ(m_intDeviceValue, actualDeviceValue);
}

TEST_F(BasicExecutionTest, TestCopyConstructorVerifyTrigger)
{
    BasicExecution basicExecutionCopy(m_basicExecution);

    const Trigger &actualTrigger = basicExecutionCopy.getTrigger();

    ASSERT_EQ(m_trigger, actualTrigger);
}

TEST_F(BasicExecutionTest, TestCopyConstructorVerifyOutputComponent)
{
    BasicExecution basicExecutionCopy(m_basicExecution);

    const IOutputComponent &actualOutputComponent =
        basicExecutionCopy.getOutputComponent();

    ASSERT_TRUE(m_mockOutputComponent == actualOutputComponent);
}

TEST_F(BasicExecutionTest, TestCopyConstructorVerifyDeviceValue)
{
    BasicExecution basicExecutionCopy(m_basicExecution);

    const DeviceValue actualDeviceValue =
        basicExecutionCopy.getDeviceValue();

    ASSERT_EQ(m_intDeviceValue, actualDeviceValue);
}

TEST_F(BasicExecutionTest, TestExecuteVerifyDeviceValueWrittenToComponent)
{
    EXPECT_CALL(m_mockOutputComponent, write(m_intDeviceValue)).Times(1);

    m_basicExecution.execute();
}
