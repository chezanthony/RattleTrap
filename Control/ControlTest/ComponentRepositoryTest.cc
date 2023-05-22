#include <gtest/gtest.h>
#include "BaseTest.cc"
#include "ComponentRepository.h"

using std::make_unique;
using std::unique_ptr;
using ::testing::Return;

class ComponentRepositoryTest : public BaseTest
{
public:
    ComponentRepositoryTest() {}
    ~ComponentRepositoryTest() override {}

protected:
    ComponentRepository m_componentRepository;
};

TEST_F(ComponentRepositoryTest, TestAddComponentVerifySizeIncreased)
{
    EXPECT_CALL(m_mockComponent, copy());

    m_componentRepository.addComponent(m_mockComponent);

    const size_t nExpectedSize = 1;
    const size_t nActualSize = m_componentRepository.getSize();

    ASSERT_EQ(nExpectedSize, nActualSize);

    m_pMockComponent.release();
}

TEST_F(ComponentRepositoryTest, TestAddComponentVerifyComponentAdded)
{
    m_componentRepository.addComponent(m_mockComponent);

    ASSERT_TRUE(m_componentRepository.exists(m_mockComponent));
}
