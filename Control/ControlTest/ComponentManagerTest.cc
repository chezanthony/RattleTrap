#include <gtest/gtest.h>
#include <memory>
#include "BaseTest.cc"
#include "ComponentManager.h"
#include "MockComponentRepository.cc"

using std::make_unique;
using std::move;
using std::unique_ptr;
using ::testing::_;

class ComponentManagerTest : public BaseTest
{
public:
    ComponentManagerTest() : m_pMockComponentRepository(make_unique<MockComponentRepository>())
    {
    }

    ~ComponentManagerTest() override {}

protected:
    unique_ptr<MockComponentRepository> m_pMockComponentRepository;
    MockComponentRepository m_mockComponentRepository;
    ComponentManager m_componentManager;
};

TEST_F(ComponentManagerTest, TestAdd)
{
    EXPECT_CALL(*m_pMockComponentRepository, addComponent(_)).Times(1);
    m_componentManager.setComponentRepository(move(m_pMockComponentRepository));
    m_componentManager.addComponent(m_mockComponent);
}
