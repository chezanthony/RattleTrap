#ifndef MOCK_COMPONENT_MANAGER_CC
#define MOCK_COMPONENT_MANAGER_CC

#include <gmock/gmock.h>
#include "IComponentManager.h"

class IComponent;

class MockComponentManager : public IComponentManager
{
public:
    MockComponentManager() {}
    MockComponentManager(const MockComponentManager &rhs) {}
    ~MockComponentManager() override {}

    MOCK_METHOD(void, addComponent, (IComponent &));
};

#endif // MOCK_COMPONENT_MANAGER_CC
