#ifndef TYPE_MISMATCH_EXCEPTION_H
#define TYPE_MISMATCH_EXCEPTION_H

#include <exception>
#include <string>
#include "DeviceValueType.h"
#include "ValueTypeStringifier.h"

using std::exception;
using std::string;

class TypeMismatchException : public exception
{
public:
    TypeMismatchException(DeviceValueType lhs, DeviceValueType rhs) : m_lhs(lhs),
                                                                      m_rhs(rhs)
    {
    }

    const char *what() const noexcept override
    {
        string sReturn =
            "Device Value Type Mismatch: lhs is " +
            ValueTypeStringifier::toString(m_lhs) +
            "while" +
            ValueTypeStringifier::toString(m_rhs);

        return sReturn.c_str();
    }

private:
    DeviceValueType m_lhs;
    DeviceValueType m_rhs;
};

#endif // TYPE_MISMATCH_EXCEPTION_H