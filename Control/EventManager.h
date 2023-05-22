#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <memory>
#include "IEventManager.h"
#include "IEventListenerRegistry.h"
#include "EventListenerRegistry.h"
#include "IEventListener.h"

using std::make_unique;
using std::unique_ptr;

// class EventManager : public IEventManager
// {
// public:
//     EventManager() : m_pEventListenerRegistry(make_unique<EventListenerRegistry>())
//     {
//     }

//     ~EventManager() override {}

//     void notify(Event &event) override
//     {
//         IEventListener &eventListener =
//             m_pEventListenerRegistry->getListener(event);

//         eventListener.notify(event);
//     }

//     void registerListener(
//         Event &event, IEventListener &eventListener) override
//     {
//         m_pEventListenerRegistry->registerListener(event, eventListener);
//     }

// private:
//     unique_ptr<IEventListenerRegistry> m_pEventListenerRegistry;
// };

#endif // IEVENT_MANAGER_H
