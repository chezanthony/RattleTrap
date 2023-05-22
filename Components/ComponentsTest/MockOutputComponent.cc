#ifndef MOCK_OUTPUT_COMPONENT_CC
#define MOCK_OUTPUT_COMPONENT_CC

#include <gmock/gmock.h>
#include "IOutputComponent.h"

class DeviceValue;

class MockOutputComponent : public IOutputComponent
{
public:
    MockOutputComponent() {}
    ~MockOutputComponent() {}

    MOCK_METHOD(const DeviceValue, read, (), (const));
    MOCK_METHOD(void, write, (const DeviceValue &rhs));
    MOCK_METHOD(IComponent *, copy, (), (const));

    bool operator==(const IOutputComponent &rhs)
    {
        const MockOutputComponent *pRhs = dynamic_cast<const MockOutputComponent *>(&rhs);
        return nullptr != pRhs;
    }
};

// bool operator==(const IOutputComponent &lhs, const IOutputComponent &rhs)
// {
//     return &lhs == &rhs;
// }

#endif // MOCK_OUTPUT_COMPONENT_CC
