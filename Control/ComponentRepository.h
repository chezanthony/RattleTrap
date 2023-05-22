#ifndef COMPONENT_REPOSITORY_H
#define COMPONENT_REPOSITORY_H

#include "IComponentRepository.h"
#include "IComponent.h"
#include <unordered_set>
#include <memory>

using std::make_unique;
using std::move;
using std::unique_ptr;
using std::unordered_set;

class ComponentRepository : public IComponentRepository
{
public:
    ComponentRepository() {}
    ~ComponentRepository() override {}

    void addComponent(IComponent &component) override
    {
        unique_ptr<IComponent> pComponent(component.copy());
        m_componentSet.insert(move(pComponent));
    }

    const size_t getSize(void)
    {
        return m_componentSet.size();
    }

    const bool exists(IComponent &component)
    {
        unique_ptr<IComponent> pComponent(component.copy());
        return m_componentSet.count(pComponent);
    }

private:
    unordered_set<unique_ptr<IComponent>> m_componentSet;
};

#endif // COMPONENT_REPOSITORY_H
