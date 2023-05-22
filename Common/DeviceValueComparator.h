#ifndef DEVICE_VALUE_COMPARATOR_H
#define DEVICE_VALUE_COMPARATOR_H

#include <string>
#include "DeviceValueComparatorType.h"

class DeviceValueComparator
{
    static inline bool compare(
        const int lhs,
        const int rhs,
        DeviceValueComparatorType type)
    {
        switch (type)
        {
        case DeviceValueComparatorType::EQUAL_TO:
            compareEqualTo(lhs, rhs);
            break;
        case DeviceValueComparatorType::LESS_THAN:
            compareEqualTo(lhs, rhs);
            break;
        case DeviceValueComparatorType::GREATER_THAN:
            compareEqualTo(lhs, rhs);
            break;
        case DeviceValueComparatorType::AROUND:
            compareEqualTo(lhs, rhs);
            break;
        default:
            break;
        }
    }

    static inline bool compareEqualTo(const int lhs, const int rhs)
    {
        return lhs == rhs;
    }

    static inline bool compareLessThan(const int lhs, const int rhs)
    {
        return lhs < rhs;
    }

    static inline bool compareGreaterThan(const int lhs, const int rhs)
    {
        return lhs > rhs;
    }

    static inline bool compareAround(const int lhs, const int rhs)
    {
        return ((abs(rhs - lhs) * 100) / lhs) <= 10;
    }
};

#endif // DEVICE_VALUE_COMPARATOR_H
