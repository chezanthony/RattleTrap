#include <gtest/gtest.h>
#include <memory>
#include "BaseTest.cc"
#include "SimpleMachine.h"
#include "MockComponentManager.cc"

using std::make_unique;
using std::move;
using std::unique_ptr;
using ::testing::_;

class SimpleMachineTest : public BaseTest
{
public:
    SimpleMachineTest() : m_pMockComponentManager(make_unique<MockComponentManager>()),
                          m_simpleMachine()
    {
    }

    ~SimpleMachineTest() override {}

protected:
    // MockComponentManager m_mockComponentManager;
    unique_ptr<MockComponentManager> m_pMockComponentManager;
    SimpleMachine m_simpleMachine;
};

TEST_F(SimpleMachineTest, TestAddComponentVerifyComponentAddedToComponentManager)
{
    EXPECT_CALL(*m_pMockComponentManager, addComponent(_)).Times(1);
    m_simpleMachine.setComponentManager(move(m_pMockComponentManager));
    m_simpleMachine.addComponent(m_mockComponent);
}

// TEST_F(SimpleMachineTest, Test)
// {
// }
