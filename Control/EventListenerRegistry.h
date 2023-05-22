#ifndef EVENT_LISTENER_REGISTRY_H
#define EVENT_LISTENER_REGISTRY_H

#include <unordered_map>
#include <memory>
#include <stdexcept>
#include "IEventListenerRegistry.h"
#include "EventListener.h"
#include "Event.h"

using std::move;
using std::out_of_range;
using std::unique_ptr;
using std::unordered_map;

// typedef unordered_map<Event, unique_ptr<IEventListener>>
//     eventListenerRegistry;

// class EventListenerRegistry : public IEventListenerRegistry
// {
// public:
//     EventListenerRegistry() {}

//     ~EventListenerRegistry() override
//     {

//         // for (auto &entry : m_eventListenerRegistry)
//         // {
//         //     // entry.first.release();
//         //     entry.second.release();
//         // }

//         // m_eventListenerRegistry.clear();
//     }

//     void registerListener(Event &event, IEventListener &eventListener) override
//     {
//         // unique_ptr<Event> pEvent(event.copy());
//         unique_ptr<IEventListener> pEventListener(eventListener.copy());

//         m_eventListenerRegistry.emplace(event, move(pEventListener));
//         // m_eventListenerRegistry.emplace(move(pEvent), move(pEventListener));
//     }

//     unsigned int getSize(void) const override
//     {
//         return unsigned int(m_eventListenerRegistry.size());
//     }

//     IEventListener &getListener(Event &event) const override
//     {
//         IEventListener *pReturn = nullptr;

//         // unique_ptr<Event> localEvent(event.copy());
//         // const auto &entry = m_eventListenerRegistry.find(localEvent);
//         const auto &entry = m_eventListenerRegistry.find(event);

//         if (m_eventListenerRegistry.end() != entry)
//         {
//             pReturn = entry->second->copy();
//         }

//         return *pReturn;
//     }

// private:
//     unordered_map<Event, unique_ptr<IEventListener>> m_eventListenerRegistry;
// };

#endif // EVENT_LISTENER_REGISTRY_H
