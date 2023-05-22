#ifndef MOCK_COMPONENT_CC
#define MOCK_COMPONENT_CC

#include <gmock/gmock.h>
#include "IComponent.h"
#include "DeviceValue.h"

class MockComponent : public IComponent
{
public:
    MockComponent() {}
    ~MockComponent() {}

    MOCK_METHOD(const DeviceValue, read, (), (const));
    MOCK_METHOD(IComponent *, copy, (), (const));

    bool operator==(const IComponent &rhs)
    {
        const MockComponent *pRhs =
            dynamic_cast<const MockComponent *>(&rhs);
        return nullptr != pRhs;
    }
};

// bool operator==(const IComponent &lhs, const IComponent &rhs)
// {
//     return &lhs == &rhs;
// }

#endif // MOCK_COMPONENT_CC
