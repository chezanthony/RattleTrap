#include <gtest/gtest.h>
#include "BaseTest.cc"
#include "BasicEventListener.h"
#include "MockOutputComponent.cc"
#include "EventStatement.h"

class BasicEventListenerTest : public BaseTest
{
public:
    BasicEventListenerTest() : m_eventStatement(m_mockComponent,
                                                m_mockOutputComponent,
                                                m_boolDeviceValue,
                                                m_intDeviceValue),
                               m_event(m_mockComponent, m_boolDeviceValue),
                               m_basicEventListener(m_eventStatement)
    {
    }

    ~BasicEventListenerTest() override {}

protected:
    MockOutputComponent m_mockOutputComponent;
    EventStatement m_eventStatement;
    Event m_event;
    BasicEventListener m_basicEventListener;
};

TEST_F(BasicEventListenerTest, TestConstructorVerifyEvent)
{
    const Event actualEvent = m_basicEventListener.getEvent();

    ASSERT_EQ(m_event, actualEvent);
}

TEST_F(BasicEventListenerTest, TestConstructorVerifyOutputComponent)
{
    const IOutputComponent &actualOutputComponent =
        m_basicEventListener.getOutputComponent();

    ASSERT_TRUE(m_mockOutputComponent == actualOutputComponent);
}

TEST_F(BasicEventListenerTest, TestConstructorVerifyDeviceValue)
{
    const DeviceValue actualDeviceValue =
        m_basicEventListener.getDeviceValue();

    ASSERT_EQ(m_intDeviceValue, actualDeviceValue);
}

TEST_F(BasicEventListenerTest, TestCopyConstructorVerifyEvent)
{
    BasicEventListener basicEventListenerCopy(m_basicEventListener);

    const Event &actualEvent = basicEventListenerCopy.getEvent();

    ASSERT_EQ(m_event, actualEvent);
}

TEST_F(BasicEventListenerTest, TestCopyConstructorVerifyOutputComponent)
{
    BasicEventListener basicEventListenerCopy(m_basicEventListener);

    const IOutputComponent &actualOutputComponent =
        basicEventListenerCopy.getOutputComponent();

    ASSERT_TRUE(m_mockOutputComponent == actualOutputComponent);
}

TEST_F(BasicEventListenerTest, TestCopyConstructorVerifyDeviceValue)
{
    BasicEventListener basicEventListenerCopy(m_basicEventListener);

    const DeviceValue actualDeviceValue =
        basicEventListenerCopy.getDeviceValue();

    ASSERT_EQ(m_intDeviceValue, actualDeviceValue);
}

TEST_F(BasicEventListenerTest, TestNotifyVerifyDeviceValueWrittenToComponent)
{
    EXPECT_CALL(m_mockOutputComponent, write(m_intDeviceValue)).Times(1);

    m_basicEventListener.notify(m_boolEvent);
}

TEST_F(BasicEventListenerTest, TestNotifyIncorrectEventVerifyValuesNotWrittenToComponent)
{
    EXPECT_CALL(m_mockOutputComponent, write(m_intDeviceValue)).Times(0);

    m_basicEventListener.notify(m_intEvent);
}

TEST_F(BasicEventListenerTest, TestCopy)
{
    unique_ptr<IEventListener> pCopy(m_basicEventListener.copy());
    const BasicEventListener &copy =
        dynamic_cast<const BasicEventListener &>(*pCopy);

    ASSERT_TRUE(m_basicEventListener == copy);
}
