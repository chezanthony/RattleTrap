#ifndef SIMPLE_MACHINE_H
#define SIMPLE_MACHINE_H

#include <memory>
#include "IMachine.h"
#include "IEventManager.h"
#include "EventManager.h"
#include "TriggerExecutionStatement.h"
#include "IComponentManager.h"
#include "ComponentManager.h"

using std::make_unique;
using std::move;
using std::unique_ptr;

class SimpleMachine : public IMachine
{
public:
    SimpleMachine() : // m_pEventManager(make_unique<EventManager>()),
                      //   m_pComponentManager(make_unique<ComponentManager>())
                      m_pComponentManager(make_unique<ComponentManager>())
    {
    }

    ~SimpleMachine() override {}

    void run(void) override
    {
    }

    void addPhysicalComponent(IPhysical &physicalCOmponent)
    {
        // TODO: Add implementation.
    }

    void addPhysicalComponent(IMultiPinPhysical &physicalComponent)
    {
        // TODO: Add implementation.
    }

    void addComponent(IComponent &component)
    {
        // TODO: Add implementation.
        m_pComponentManager->addComponent(component);
    }

    // void addEventListener(IEventListener &EventListener)
    // {
    //     // TODO: Add implementation.
    // }

    TriggerExecutionStatement when(IComponent &component) override
    {
        return TriggerExecutionStatement(component);
    }

    // For testing only.
    void setComponentManager(unique_ptr<IComponentManager> pComponentManager)
    {
        m_pComponentManager = move(pComponentManager);
    }

private:
    // unique_ptr<IEventManager> m_pEventManager;
    unique_ptr<IComponentManager> m_pComponentManager;
};

#endif // SIMPLE_MACHINE_H
