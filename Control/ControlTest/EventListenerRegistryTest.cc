// #include <gtest/gtest.h>
// #include <memory>
// #include <vector>
// #include "BaseTest.cc"
// #include "EventListenerRegistry.h"
// #include "MockEventListener.cc"

// using std::make_unique;
// using std::vector;
// using ::testing::Return;

// class EventListenerRegistryTest : public BaseTest
// {
// public:
//     // EventListenerRegistryTest() : m_pMockDefaultEventListener(make_unique<MockEventListener>()),
//     //                               m_pMockBoolEventListener(make_unique<MockEventListener>()),
//     //                               m_pMockIntEventListener(make_unique<MockEventListener>()),
//     //                               m_pMockCharEventListener(make_unique<MockEventListener>()),
//     //                               m_pMockStringEventListener(make_unique<MockEventListener>())
//     EventListenerRegistryTest()
//     {
//     }

//     ~EventListenerRegistryTest() override {}

// protected:
//     // void SetUp(void) override
//     // {
//     //     BaseTest::SetUp();

//     //     // ON_CALL(m_mockDefaultEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockDefaultEventListener.get()));
//     //     // ON_CALL(m_mockBoolEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockBoolEventListener.get()));
//     //     // ON_CALL(m_mockIntEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockIntEventListener.get()));
//     //     // ON_CALL(m_mockCharEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockCharEventListener.get()));
//     //     // ON_CALL(m_mockStringEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockStringEventListener.get()));

//     //     // ON_CALL(*m_pMockDefaultEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockDefaultEventListener.get()));
//     //     // ON_CALL(*m_pMockBoolEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockBoolEventListener.get()));
//     //     // ON_CALL(*m_pMockIntEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockIntEventListener.get()));
//     //     // ON_CALL(*m_pMockCharEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockCharEventListener.get()));
//     //     // ON_CALL(*m_pMockStringEventListener, copy())
//     //     //     .WillByDefault(Return(m_pMockStringEventListener.get()));

//     //     // ON_CALL(*m_pMockDefaultEventListener, copy())
//     //     //     .WillByDefault(Return(&m_mockDefaultEventListener));
//     //     // ON_CALL(*m_pMockBoolEventListener, copy())
//     //     //     .WillByDefault(Return(&m_mockBoolEventListener));
//     //     // ON_CALL(*m_pMockIntEventListener, copy())
//     //     //     .WillByDefault(Return(&m_mockIntEventListener));
//     //     // ON_CALL(*m_pMockCharEventListener, copy())
//     //     //     .WillByDefault(Return(&m_mockCharEventListener));
//     //     // ON_CALL(*m_pMockStringEventListener, copy())
//     //     //     .WillByDefault(Return(&m_mockStringEventListener));

//     //     m_theEvents.push_back(m_defaultEvent);
//     //     m_theEvents.push_back(m_boolEvent);
//     //     m_theEvents.push_back(m_intEvent);
//     //     m_theEvents.push_back(m_charEvent);
//     //     m_theEvents.push_back(m_stringEvent);

//     //     // m_theEventListeners.push_back(*(m_pMockDefaultEventListener.get()));
//     //     // m_theEventListeners.push_back(*(m_pMockBoolEventListener.get()));
//     //     // m_theEventListeners.push_back(*(m_pMockIntEventListener.get()));
//     //     // m_theEventListeners.push_back(*(m_pMockCharEventListener.get()));
//     //     // m_theEventListeners.push_back(*(m_pMockStringEventListener.get()));
//     // }

//     // void TearDown(void)
//     // {

//     //     // m_pMockDefaultEventListener.release();
//     //     // m_pMockBoolEventListener.release();
//     //     // m_pMockIntEventListener.release();
//     //     // m_pMockCharEventListener.release();
//     //     // m_pMockStringEventListener.release();
//     // }

//     MockEventListener m_mockDefaultEventListener;
//     MockEventListener m_mockBoolEventListener;
//     MockEventListener m_mockIntEventListener;
//     MockEventListener m_mockCharEventListener;
//     MockEventListener m_mockStringEventListener;
//     // unique_ptr<MockEventListener> m_pMockDefaultEventListener;
//     // unique_ptr<MockEventListener> m_pMockBoolEventListener;
//     // unique_ptr<MockEventListener> m_pMockIntEventListener;
//     // unique_ptr<MockEventListener> m_pMockCharEventListener;
//     // unique_ptr<MockEventListener> m_pMockStringEventListener;
//     // vector<MockEventListener> m_theEventListeners;
//     // vector<ICopiable<IEventListener>> m_theEventListeners;
//     vector<Event> m_theEvents;
//     EventListenerRegistry m_eventListenerRegistry;
// };

// TEST_F(EventListenerRegistryTest, TestVerifySizeZero)
// {
//     const unsigned int nExpected = 0;
//     const unsigned int nActual = m_eventListenerRegistry.getSize();

//     ASSERT_EQ(nExpected, nActual);
// }

// TEST_F(EventListenerRegistryTest, TestRegisterListenerIncreasesContainerSize)
// {
//     m_eventListenerRegistry.registerListener(m_defaultEvent, m_mockDefaultEventListener);

//     const unsigned int nExpectedSize = 1;
//     const unsigned int nActualSize = m_eventListenerRegistry.getSize();

//     ASSERT_EQ(nExpectedSize, nActualSize);
// }

// TEST_F(EventListenerRegistryTest, TestGetListener)
// {
//     m_eventListenerRegistry.registerListener(m_defaultEvent, m_mockDefaultEventListener);

//     const MockEventListener &actualEventListener =
//         dynamic_cast<const MockEventListener &>(m_eventListenerRegistry.getListener(m_defaultEvent));

//     ASSERT_EQ(m_mockDefaultEventListener, actualEventListener);
// }

// // TEST_F(EventListenerRegistryTest, TestMultipleListeners)
// // {
// //     ASSERT_EQ(m_theEventListeners.size(), m_theEvents.size());

// //     for (int i = 0; i < m_theEventListeners.size(); ++i)
// //     {
// //         m_eventListenerRegistry
// //             .registerListener(m_theEvents[i],
// //                               m_theEventListeners[i]);

// //         const int nExpectedSize = i + 1;

// //         ASSERT_EQ(nExpectedSize, m_eventListenerRegistry.getSize());
// //     }

// //     for (int i = 0; i < m_theEventListeners.size(); ++i)
// //     {
// //         IEventListener &expectedEventListener = m_theEventListeners[i];
// //         IEventListener &actualEventListener =
// //             m_eventListenerRegistry.getListener(m_theEvents[i]);

// //         ASSERT_EQ(&expectedEventListener, &actualEventListener);
// //     }
// // }
