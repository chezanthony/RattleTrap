#ifndef MOCK_COMPONENT_REPOSITORY_CC
#define MOCK_COMPONENT_REPOSITORY_CC

#include <gmock/gmock.h>
#include "IComponentRepository.h"
#include "IComponent.h"

class MockComponentRepository : public IComponentRepository
{
public:
    MockComponentRepository() {}
    MockComponentRepository(const MockComponentRepository &rhs) {}
    ~MockComponentRepository() override {}

    MOCK_METHOD(void, addComponent, (IComponent &));
};

#endif // MOCK_COMPONENT_REPOSITORY_CC
