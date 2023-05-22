#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <memory>
#include "IComponentManager.h"
#include "IComponent.h"
#include "IComponentRepository.h"
#include "ComponentRepository.h"

using std::make_unique;
using std::move;
using std::unique_ptr;

class ComponentManager : public IComponentManager
{
public:
    ComponentManager() : m_pComponentRepository(make_unique<ComponentRepository>())
    {
    }

    ~ComponentManager() override {}

    void addComponent(IComponent &component) override
    {
        m_pComponentRepository->addComponent(component);
    }

    // For testing only.
    void setComponentRepository(unique_ptr<IComponentRepository> pComponentRepository)
    {
        m_pComponentRepository = move(pComponentRepository);
    }

private:
    unique_ptr<IComponentRepository> m_pComponentRepository;
};

#endif // COMPONENT_MANAGER_H
