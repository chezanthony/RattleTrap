#include <gtest/gtest.h>
#include "BaseTest.cc"
#include "DeviceValueType.h"
#include "DeviceValueHelper.h"

using std::make_unique;
using std::unique_ptr;

class DeviceValueTest : public BaseTest
{
public:
    DeviceValueTest() {}
    ~DeviceValueTest() override {}
};

TEST_F(DeviceValueTest, TestDefaultConstructorVerifyValueEmpty)
{
    const size_t actualSize = m_defaultDeviceValue.getValue().size();

    ASSERT_TRUE(m_defaultDeviceValue.getValue().empty());
}

TEST_F(DeviceValueTest, TestDefaultConstructorVerifyValueType)
{
    ASSERT_EQ(
        DeviceValueType::UNDEFINED_TYPE,
        m_defaultDeviceValue.getValueType());
}

TEST_F(DeviceValueTest, TestBoolConstructorVerifyValue)
{
    const bool bActual = DeviceValueHelper::toBool(m_boolDeviceValue);

    ASSERT_EQ(m_bTestBool, bActual);
}

TEST_F(DeviceValueTest, TestBoolConstructorVerifyValueType)
{
    ASSERT_EQ(DeviceValueType::BOOL, m_boolDeviceValue.getValueType());
}

TEST_F(DeviceValueTest, TestIntConstructorVerifyValue)
{
    const int nActual = DeviceValueHelper::toInt(m_intDeviceValue);

    ASSERT_EQ(m_nTestInt, nActual);
}

TEST_F(DeviceValueTest, TestIntConstructorVerifyValueType)
{
    ASSERT_EQ(DeviceValueType::INT, m_intDeviceValue.getValueType());
}

TEST_F(DeviceValueTest, TestCharConstructorVerifyValue)
{
    const char cActual = DeviceValueHelper::toChar(m_charDeviceValue);

    ASSERT_EQ(m_cTestChar, cActual);
}

TEST_F(DeviceValueTest, TestCharConstructorVerifyValueType)
{
    ASSERT_EQ(DeviceValueType::CHAR, m_charDeviceValue.getValueType());
}

TEST_F(DeviceValueTest, TestStringConstructorVerifyValue)
{
    ASSERT_EQ(m_sTestString, m_stringDeviceValue.getValue());
}

TEST_F(DeviceValueTest, TestStringConstructorVerifyValueType)
{
    ASSERT_EQ(DeviceValueType::STRING, m_stringDeviceValue.getValueType());
}

TEST_F(DeviceValueTest, TestCopyConstructor)
{
    for (const auto &testDeviceValue : m_theDeviceValues)
    {
        DeviceValue anotherTestDeviceValue(testDeviceValue);

        ASSERT_EQ(testDeviceValue, anotherTestDeviceValue);
    }
}

TEST_F(DeviceValueTest, TestCopyConstructorVerifySameValueType)
{
    for (const auto &testDeviceValue : m_theDeviceValues)
    {
        DeviceValue anotherTestDeviceValue(testDeviceValue);

        ASSERT_EQ(
            testDeviceValue.getValueType(),
            anotherTestDeviceValue.getValueType());
    }
}

TEST_F(DeviceValueTest, TestCopyConstructorVerifySameValue)
{
    for (const auto &testDeviceValue : m_theDeviceValues)
    {
        DeviceValue anotherTestDeviceValue(testDeviceValue);

        ASSERT_EQ(
            testDeviceValue.getValue(),
            anotherTestDeviceValue.getValue());
    }
}

TEST_F(DeviceValueTest, TestEquality)
{
    const int nTestValue = 3;

    DeviceValue testDeviceValue(nTestValue);
    DeviceValue otherTestDeviceValue(nTestValue);

    ASSERT_EQ(testDeviceValue, otherTestDeviceValue);
}

TEST_F(DeviceValueTest, TestInequalityDifferentValue)
{
    const int nTestValue = 3;
    const int nTestOtherValue = 4;

    DeviceValue testDeviceValue(nTestValue);
    DeviceValue otherTestDeviceValue(nTestOtherValue);

    ASSERT_NE(testDeviceValue, otherTestDeviceValue);
}

TEST_F(DeviceValueTest, TestInequalityDifferentValueType)
{
    const int nTestValue = 3;
    const bool bTestOtherValue = false;

    DeviceValue testDeviceValue(nTestValue);
    DeviceValue otherTestDeviceValue(bTestOtherValue);

    ASSERT_NE(testDeviceValue, otherTestDeviceValue);
}

TEST_F(DeviceValueTest, TestAssignmentOperator)
{
    for (const auto &testDeviceValue : m_theDeviceValues)
    {
        DeviceValue anotherTestDeviceValue = testDeviceValue;

        ASSERT_EQ(anotherTestDeviceValue, testDeviceValue);
    }
}

TEST_F(DeviceValueTest, TestAssignmentOperatorVerifySameValue)
{
    for (const auto &testDeviceValue : m_theDeviceValues)
    {
        DeviceValue anotherTestDeviceValue = testDeviceValue;

        ASSERT_EQ(
            anotherTestDeviceValue.getValue(),
            testDeviceValue.getValue());
    }
}

TEST_F(DeviceValueTest, TestAssignmentOperatorVerifySameValueType)
{
    for (const auto &testDeviceValue : m_theDeviceValues)
    {
        DeviceValue anotherTestDeviceValue = testDeviceValue;

        ASSERT_EQ(
            anotherTestDeviceValue.getValueType(),
            testDeviceValue.getValueType());
    }
}
