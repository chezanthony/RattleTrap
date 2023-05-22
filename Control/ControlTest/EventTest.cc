#include <gtest/gtest.h>
#include <memory>
#include "Event.h"
#include "BaseTest.cc"
#include "DeviceValue.h"
#include "DeviceValueHelper.h"

using std::make_unique;
using std::unique_ptr;

class EventTest : public BaseTest
{
public:
    EventTest() : m_event(m_mockComponent, m_boolDeviceValue)
    {
    }

    ~EventTest() {}

protected:
    Event m_event;
};

TEST_F(EventTest, TestConstructorVerifyComponentIsInitialized)
{
    ASSERT_TRUE(m_mockComponent == m_event.getComponent());
}

TEST_F(EventTest, TestConstructorVerifyDeviceValueIsInitialized)
{
    ASSERT_TRUE(m_boolDeviceValue == m_event.getDeviceValue());
}

TEST_F(EventTest, TestCopyConstructorVerifyComponentIsEqual)
{
    Event copiedEvent(m_event);

    ASSERT_TRUE(m_mockComponent == copiedEvent.getComponent());
}

TEST_F(EventTest, TestCopyConstructorVerifyDeviceValueIsEqual)
{
    Event copiedEvent(m_event);

    ASSERT_EQ(m_boolDeviceValue, copiedEvent.getDeviceValue());
}
