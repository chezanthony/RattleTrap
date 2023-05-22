#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "DummyComponentClass.h"

using std::make_unique;
using std::unique_ptr;
using std::vector;

class DummyComponentClassTest : public testing::Test
{
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

        m_dummyComponentClass = make_unique<DummyComponentClass>();
    }

    vector<int> m_theIntList;
    unique_ptr<DummyComponentClass> m_dummyComponentClass;
};

TEST_F(DummyComponentClassTest, TestConstructorVerifyIntMemberIsZero)
{
    DummyComponentClass dummyComponentClass = DummyComponentClass();
    const int nExpected = 0;
    ASSERT_EQ(nExpected, dummyComponentClass.getIntMember());
}

TEST_F(DummyComponentClassTest, TestConstructorVerifyStringMemberIsEmpty)
{
    DummyComponentClass dummyComponentClass = DummyComponentClass();
    const string sExpected = "";
    ASSERT_EQ(sExpected, dummyComponentClass.getStringMember());
}

TEST_F(DummyComponentClassTest, TestDoSomethingNoThrow)
{
    ASSERT_NO_THROW(m_dummyComponentClass->doSomething());
}

TEST_F(DummyComponentClassTest, TestDoSomethingInt)
{
    for (const auto &nCurrentInt : m_theIntList)
    {
        ASSERT_NO_THROW(m_dummyComponentClass->doSomething(nCurrentInt));
    }
}

TEST_F(DummyComponentClassTest, TestIntMemberSetterGetterVerifyStorageAndRetrieval)
{
    for (const auto &nCurrentInt : m_theIntList)
    {
        m_dummyComponentClass->setIntMember(nCurrentInt);
        ASSERT_EQ(nCurrentInt, m_dummyComponentClass->getIntMember());
    }
}

TEST_F(DummyComponentClassTest, TestStringMemberSetterGetterVerifyStorageAndRetrieval)
{
    vector<string> stheStringList = {
        "These",
        "are",
        "test strings.",
        "You can add yours here!",
    };

    for (const auto &sCurrentString : stheStringList)
    {
        m_dummyComponentClass->setStringMember(sCurrentString);
        ASSERT_EQ(sCurrentString, m_dummyComponentClass->getStringMember());
    }
}
