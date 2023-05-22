#ifndef DUMMY_CONTROL_CLASS_H
#define DUMMY_CONTROL_CLASS_H

#include <string>

using std::string;

class DummyControlClass
{
public:
    DummyControlClass() : m_nIntMember(0),
                          m_sStringMember("")
    {
    }

    ~DummyControlClass()
    {
    }

    void doSomething(void)
    {
    }

    void doSomething(int nInput)
    {
    }

    void setIntMember(int nInput)
    {
        m_nIntMember = nInput;
    }
    void setStringMember(string sInput)
    {
        m_sStringMember = sInput;
    }

    int getIntMember(void) const
    {
        return m_nIntMember;
    }

    string getStringMember(void) const
    {
        return m_sStringMember;
    }

private:
    int m_nIntMember;
    string m_sStringMember;
};

#endif // DUMMY_CONTROL_CLASS_H
