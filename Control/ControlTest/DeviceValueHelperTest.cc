#include <gtest/gtest.h>
#include "BaseTest.cc"
#include "DeviceValueHelper.h"

class DeviceValueHelperTest : public BaseTest
{
public:
    DeviceValueHelperTest() {}
    ~DeviceValueHelperTest() override {}
};

TEST_F(DeviceValueHelperTest, TestToBool)
{
    const bool bTestValue = false;
    DeviceValue deviceValue(bTestValue);

    const bool bActualValue = DeviceValueHelper::toBool(deviceValue);

    ASSERT_EQ(bTestValue, bActualValue);
}

TEST_F(DeviceValueHelperTest, TestToBoolIncorrectType)
{
    for (const auto &deviceValue : m_theDeviceValues)
    {
        if (DeviceValueType::BOOL == deviceValue.getValueType())
            continue;

        const bool bExpectedValue = false;
        const bool bActualValue = DeviceValueHelper::toBool(deviceValue);

        ASSERT_EQ(bExpectedValue, bActualValue);
    }
}

TEST_F(DeviceValueHelperTest, TestToInt)
{
    const int nTestValue = 7;
    DeviceValue deviceValue(nTestValue);

    const int nActualValue = DeviceValueHelper::toInt(deviceValue);

    ASSERT_EQ(nTestValue, nActualValue);
}

TEST_F(DeviceValueHelperTest, TestToIntIncorrectType)
{
    for (const auto &deviceValue : m_theDeviceValues)
    {
        if (DeviceValueType::INT == deviceValue.getValueType())
            continue;

        const int nExpectedValue = 0;
        const int nActualValue = DeviceValueHelper::toInt(deviceValue);

        ASSERT_EQ(nExpectedValue, nExpectedValue);
    }
}

TEST_F(DeviceValueHelperTest, TestToChar)
{
    const char cTestValue = 'a';
    DeviceValue deviceValue(cTestValue);

    const char cActualValue = DeviceValueHelper::toChar(deviceValue);

    ASSERT_EQ(cTestValue, cActualValue);
}

TEST_F(DeviceValueHelperTest, TestToCharIncorrectType)
{
    for (const auto &deviceValue : m_theDeviceValues)
    {
        if (DeviceValueType::CHAR == deviceValue.getValueType())
            continue;

        const char cExpectedValue = '\0';
        const char cActualValue = DeviceValueHelper::toChar(deviceValue);

        ASSERT_EQ(cExpectedValue, cActualValue);
    }
}

TEST_F(DeviceValueHelperTest, TestToString)
{
    const string sTestValue = "This is a test string.";
    DeviceValue deviceValue(sTestValue);

    const string sActualValue = DeviceValueHelper::toString(deviceValue);

    ASSERT_EQ(sTestValue, sActualValue);
}

TEST_F(DeviceValueHelperTest, TestToStringIncorrectType)
{
    for (const auto &deviceValue : m_theDeviceValues)
    {
        if (DeviceValueType::STRING == deviceValue.getValueType())
            continue;

        const string sExpectedValue = "";
        const string sActualValue = DeviceValueHelper::toString(deviceValue);

        ASSERT_EQ(sExpectedValue, sActualValue);
    }
}
