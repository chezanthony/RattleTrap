#ifndef VALUE_TYPE_STRINGIFIER_H
#define VALUE_TYPE_STRINGIFIER_H

#include <string>
#include "DeviceValueType.h"

using std::string;

class ValueTypeStringifier
{
public:
    static string toString(DeviceValueType type)
    {
        string sReturn = "Undefined";

        switch (type)
        {
        case DeviceValueType::BOOL:
            sReturn = "Bool";
            break;
        case DeviceValueType::CHAR:
            sReturn = "Char";
            break;
        case DeviceValueType::INT:
            sReturn = "Int";
            break;
        case DeviceValueType::STRING:
            sReturn = "String";
            break;
        default:
            break;
        }
    }
};

#endif // VALUE_TYPE_STRINGIFIER_H