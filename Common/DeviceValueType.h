#ifndef DEVICE_VALUE_TYPE_H
#define DEVICE_VALUE_TYPE_H

// Describes the value that the DeviceValueType is storing.
// Used to recover the value from string.
enum class DeviceValueType
{
    INT,
    BOOL,
    CHAR,
    STRING,
    UNDEFINED_TYPE = 9999,
};

#endif // DEVICE_VALUE_TYPE_H
