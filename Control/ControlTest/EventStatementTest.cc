#include <gtest/gtest.h>
#include <memory>
#include "EventStatement.h"
#include "BaseTest.cc"
#include "MockOutputComponent.cc"
#include "DeviceValue.h"

using std::make_unique;
using std::pair;
using std::unique_ptr;

class EventStatementTest : public BaseTest
{
public:
    EventStatementTest() : m_eventStatement(m_mockComponent,
                                            m_mockOutputComponent)
    {
    }

    ~EventStatementTest() override {}

protected:
    MockOutputComponent m_mockOutputComponent;
    EventStatement m_eventStatement;
};

TEST_F(EventStatementTest, TestInputConstructorVerifyInputComponentInitialized)
{
    EventStatement testEventStatement(m_mockComponent);

    ASSERT_TRUE(m_mockComponent == testEventStatement.getInputComponent());
}

TEST_F(EventStatementTest, TestComponentConstructorVerifyComponentsInitialized)
{
    ASSERT_TRUE(m_mockComponent == m_eventStatement.getInputComponent());
    ASSERT_TRUE(m_mockOutputComponent == m_eventStatement.getOutputComponent());
}

TEST_F(EventStatementTest, TestFullConstructorVerifyComponentsInitialized)
{
    EventStatement testEventStatement(
        m_mockComponent,
        m_mockOutputComponent,
        m_boolDeviceValue,
        m_intDeviceValue);

    ASSERT_TRUE(m_mockComponent == testEventStatement.getInputComponent());
    ASSERT_TRUE(m_mockOutputComponent == testEventStatement.getOutputComponent());
}

TEST_F(EventStatementTest, TestFullConstructorVerifyDeviceValuesInitialized)
{
    EventStatement testEventStatement(
        m_mockComponent,
        m_mockOutputComponent,
        m_boolDeviceValue,
        m_intDeviceValue);

    ASSERT_EQ(m_boolDeviceValue, testEventStatement.getReading());
    ASSERT_EQ(m_intDeviceValue, testEventStatement.getOutput());
}

TEST_F(EventStatementTest, TestCopyConstructorVerifyComponentsInitialized)
{
    EventStatement testEventStatement(m_eventStatement);

    ASSERT_TRUE(m_mockComponent == testEventStatement.getInputComponent());
    ASSERT_TRUE(m_mockOutputComponent == testEventStatement.getOutputComponent());
}

TEST_F(EventStatementTest, TestCopyConstructorVerifyValuesInitialized)
{
    (void)m_eventStatement.reads(m_boolDeviceValue).then(m_intDeviceValue);
    EventStatement testEventStatement(m_eventStatement);

    ASSERT_EQ(m_boolDeviceValue, testEventStatement.getReading());
}

TEST_F(EventStatementTest, TestIsLowVerifyReading)
{
    m_eventStatement.isLow();

    DeviceValue expectedValue(false);

    ASSERT_EQ(expectedValue, m_eventStatement.getReading());
}

TEST_F(EventStatementTest, TestIsLowVerifyReadingType)
{
    m_eventStatement.isLow();

    DeviceValueType expectedValueType = DeviceValueType::BOOL;

    ASSERT_EQ(
        expectedValueType,
        m_eventStatement.getReading().getValueType());
}

TEST_F(EventStatementTest, TestIsHighVerifyReading)
{
    m_eventStatement.isHigh();

    DeviceValue expectedValue(true);

    ASSERT_EQ(expectedValue, m_eventStatement.getReading());
}

TEST_F(EventStatementTest, TestIsHighVerifyReadingType)
{
    m_eventStatement.isLow();

    DeviceValueType expectedValueType = DeviceValueType::BOOL;

    ASSERT_EQ(
        expectedValueType,
        m_eventStatement.getReading().getValueType());
}

TEST_F(EventStatementTest, TestReadsVerifyReading)
{
    for (const auto &deviceValue : m_theDeviceValues)
    {
        m_eventStatement.reads(deviceValue);

        ASSERT_EQ(deviceValue, m_eventStatement.getReading());
    }
}

TEST_F(EventStatementTest, TestReadsBoolVerifyReading)
{
    (void)m_eventStatement.reads(m_boolDeviceValue);

    ASSERT_EQ(m_boolDeviceValue, m_eventStatement.getReading());
}

TEST_F(EventStatementTest, TestReadsIntVerifyReading)
{
    (void)m_eventStatement.reads(m_intDeviceValue);

    ASSERT_EQ(m_intDeviceValue, m_eventStatement.getReading());
}

TEST_F(EventStatementTest, TestReadsCharVerifyReading)
{
    (void)m_eventStatement.reads(m_charDeviceValue);

    ASSERT_EQ(m_charDeviceValue, m_eventStatement.getReading());
}

TEST_F(EventStatementTest, TestReadsStringVerifyReading)
{
    (void)m_eventStatement.reads(m_stringDeviceValue);

    ASSERT_EQ(m_stringDeviceValue, m_eventStatement.getReading());
}

TEST_F(EventStatementTest, TestThenVerifyReading)
{
    (void)m_eventStatement.reads(m_defaultDeviceValue);

    for (const auto &deviceValue : m_theDeviceValues)
    {
        m_eventStatement.then(deviceValue);

        ASSERT_EQ(deviceValue, m_eventStatement.getOutput());
    }
}
