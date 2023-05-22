#ifndef DEVICE_VALUE_HELPER_H
#define DEVICE_VALUE_HELPER_H

#include <string>
#include "DeviceValue.h"
#include "DeviceValueType.h"

using std::stoi;

class DeviceValueHelper
{
public:
    static inline bool toBool(const DeviceValue &value)
    {
        return (DeviceValueType::BOOL == value.getValueType() &&
                value.getValue() == STRING_TRUE)
                   ? true
                   : false;
    }

    static inline int toInt(const DeviceValue &value)
    {
        return DeviceValueType::INT == value.getValueType()
                   ? stoi(value.getValue())
                   : 0;
    }

    static inline char toChar(const DeviceValue &value)
    {
        string sValue = value.getValue();

        return (DeviceValueType::CHAR == value.getValueType() &&
                !sValue.empty())
                   ? sValue.front()
                   : '\0';
    }

    static inline string toString(const DeviceValue &value)
    {
        return (DeviceValueType::STRING == value.getValueType())
                   ? value.getValue()
                   : "";
    }
};

#endif // DEVICE_VALUE_HELPER_H
