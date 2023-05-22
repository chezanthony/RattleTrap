#ifndef DEVICE_VALUE_H
#define DEVICE_VALUE_H

#include <string>
#include <vector>
#include "DeviceValueType.h"
#include "TypeMismatchException.h"

using std::string;
using std::to_string;
using std::vector;

const string STRING_FALSE("FALSE");
const string STRING_TRUE("TRUE");

// Container for values either read from or written to components.
class DeviceValue final
{
public:
    DeviceValue() : m_value(""),
                    m_valueType(DeviceValueType::UNDEFINED_TYPE)
    {
    }

    DeviceValue(const bool bValue) : m_value(bValue ? STRING_TRUE : STRING_FALSE),
                                     m_valueType(DeviceValueType::BOOL)
    {
    }

    DeviceValue(const int nValue) : m_value(to_string(nValue)),
                                    m_valueType(DeviceValueType::INT)
    {
    }

    DeviceValue(const char cValue) : m_value(string(1, cValue)),
                                     m_valueType(DeviceValueType::CHAR)
    {
    }

    DeviceValue(const string sValue) : m_value(sValue),
                                       m_valueType(DeviceValueType::STRING)
    {
    }

    DeviceValue(const DeviceValue &rhs) : m_value(rhs.m_value),
                                          m_valueType(rhs.m_valueType)
    {
    }

    ~DeviceValue()
    {
        m_value.clear();
        m_valueType = DeviceValueType::UNDEFINED_TYPE;
    }

    bool operator==(const DeviceValue &rhs) const
    {
        return (m_valueType == rhs.m_valueType &&
                m_value == rhs.m_value);
    }

    bool operator!=(const DeviceValue &rhs) const
    {
        return (m_valueType != rhs.m_valueType ||
                m_value != rhs.m_value);
    }

    bool operator<(const DeviceValue &rhs) const
    {
        verifyDeviceValueType(rhs.m_valueType);

        return m_value < rhs.m_value;
    }

    bool operator>(const DeviceValue &rhs) const
    {
        verifyDeviceValueType(rhs.m_valueType);

        return m_value > rhs.m_value;
    }

    DeviceValue &operator=(const DeviceValue &rhs)
    {
        m_valueType = rhs.m_valueType;
        m_value = rhs.m_value;
        return *this;
    }

    string getValue(void) const
    {
        return m_value;
    }

    DeviceValueType getValueType(void) const
    {
        return m_valueType;
    }

private:
    string m_value;
    DeviceValueType m_valueType;

    void verifyDeviceValueType(DeviceValueType otherValueType) const
    {
        if (m_valueType != otherValueType)
        {
            throw TypeMismatchException(m_valueType, otherValueType);
        }
    }
};

#endif // DEVICE_VALUE_H
