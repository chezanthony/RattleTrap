#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "DummyControlClass.h"

using std::make_unique;
using std::unique_ptr;
using std::vector;

class DummyControlClassTest : public testing::Test
{
public:
    DummyControlClassTest() : m_dummyControlClass(make_unique<DummyControlClass>())
    {
    }

    ~DummyControlClassTest() override {}

protected:
    void SetUp(void) override
    {
        const vector<int> m_theIntList = {
            0,
            5,
            23,
            INT_MAX,
            INT_MIN,
        };
    }

    vector<int> m_theIntList;
    unique_ptr<DummyControlClass> m_dummyControlClass;
};

TEST_F(DummyControlClassTest, TestConstructorVerifyIntMemberIsZero)
{
    DummyControlClass dummyControlClass = DummyControlClass();
    const int nExpected = 0;
    ASSERT_EQ(nExpected, dummyControlClass.getIntMember());
}

TEST_F(DummyControlClassTest, TestConstructorVerifyStringMemberIsEmpty)
{
    DummyControlClass dummyControlClass = DummyControlClass();
    const string sExpected = "";
    ASSERT_EQ(sExpected, dummyControlClass.getStringMember());
}

TEST_F(DummyControlClassTest, TestDoSomethingNoThrow)
{
    ASSERT_NO_THROW(m_dummyControlClass->doSomething());
}

TEST_F(DummyControlClassTest, TestDoSomethingInt)
{
    for (const auto &nCurrentInt : m_theIntList)
    {
        ASSERT_NO_THROW(m_dummyControlClass->doSomething(nCurrentInt));
    }
}

TEST_F(DummyControlClassTest, TestIntMemberSetterGetterVerifyStorageAndRetrieval)
{
    for (const auto &nCurrentInt : m_theIntList)
    {
        m_dummyControlClass->setIntMember(nCurrentInt);
        ASSERT_EQ(nCurrentInt, m_dummyControlClass->getIntMember());
    }
}

TEST_F(DummyControlClassTest, TestStringMemberSetterGetterVerifyStorageAndRetrieval)
{
    vector<string> stheStringList = {
        "These",
        "are",
        "test strings.",
        "You can add yours here!",
    };

    for (const auto &sCurrentString : stheStringList)
    {
        m_dummyControlClass->setStringMember(sCurrentString);
        ASSERT_EQ(sCurrentString, m_dummyControlClass->getStringMember());
    }
}
