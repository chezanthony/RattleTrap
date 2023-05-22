#include <gtest/gtest.h>
#include "TriggerExecutionStatement.h"
#include "BaseTest.cc"
#include "MockOutputComponent.cc"

class TriggerExecutionStatementTest : public BaseTest
{
public:
    TriggerExecutionStatementTest() : m_statement(m_mockComponent)
    {
    }

    ~TriggerExecutionStatementTest() override {}

protected:
    MockOutputComponent m_mockOutputComponent;
    TriggerExecutionStatement m_statement;
};

TEST_F(TriggerExecutionStatementTest, TestInputConstructorVerifyInputComponentInitialized)
{
    ASSERT_TRUE(m_mockComponent == m_statement.getInputComponent());
}

TEST_F(TriggerExecutionStatementTest, TestFullConstructorVerifyComponentsInitialized)
{
    TriggerExecutionStatement testStatement(
        m_mockComponent,
        m_mockOutputComponent,
        m_boolDeviceValue,
        m_intDeviceValue);

    ASSERT_TRUE(m_mockComponent == testStatement.getInputComponent());
    ASSERT_TRUE(m_mockOutputComponent == testStatement.getOutputComponent());
}

TEST_F(TriggerExecutionStatementTest, TestFullConstructorVerifyDeviceValuesInitialized)
{
    TriggerExecutionStatement testStatement(
        m_mockComponent,
        m_mockOutputComponent,
        m_boolDeviceValue,
        m_intDeviceValue);

    ASSERT_EQ(m_boolDeviceValue, testStatement.getReading());
    ASSERT_EQ(m_intDeviceValue, testStatement.getOutput());
}

TEST_F(TriggerExecutionStatementTest, TestCopyConstructorVerifyComponentsInitialized)
{
    TriggerExecutionStatement testStatement(
        m_mockComponent,
        m_mockOutputComponent,
        m_boolDeviceValue,
        m_intDeviceValue);

    TriggerExecutionStatement testStatementCopy(testStatement);

    ASSERT_TRUE(m_mockComponent == testStatementCopy.getInputComponent());
    ASSERT_TRUE(m_mockOutputComponent == testStatementCopy.getOutputComponent());
}

TEST_F(TriggerExecutionStatementTest, TestCopyConstructorVerifyValuesInitialized)
{
    m_statement
        .reads(m_boolDeviceValue)
        .then(m_mockOutputComponent)
        .writes(m_intDeviceValue);

    TriggerExecutionStatement testStatement(m_statement);

    ASSERT_EQ(m_boolDeviceValue, testStatement.getReading());
    ASSERT_EQ(m_intDeviceValue, testStatement.getOutput());
}

TEST_F(TriggerExecutionStatementTest, TestIsLowVerifyReading)
{
    m_statement.isLow();

    DeviceValue expectedValue(false);

    ASSERT_EQ(expectedValue, m_statement.getReading());
}

TEST_F(TriggerExecutionStatementTest, TestIsHighVerifyReading)
{
    m_statement.isHigh();

    DeviceValue expectedValue(true);

    ASSERT_EQ(expectedValue, m_statement.getReading());
}

TEST_F(TriggerExecutionStatementTest, TestReadsVerifyReading)
{
    for (const auto &deviceValue : m_theDeviceValues)
    {
        m_statement.reads(deviceValue);

        ASSERT_EQ(deviceValue, m_statement.getReading());
    }
}

TEST_F(TriggerExecutionStatementTest, TestThenVerifyOutputComponent)
{
    (void)m_statement.then(m_mockOutputComponent);

    ASSERT_TRUE(m_mockOutputComponent == m_statement.getOutputComponent());
}

TEST_F(TriggerExecutionStatementTest, TestWritesVerifyOutput)
{
    for (const auto &deviceValue : m_theDeviceValues)
    {
        m_statement.writes(deviceValue);

        ASSERT_EQ(deviceValue, m_statement.getOutput());
    }
}
