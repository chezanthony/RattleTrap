#ifndef IEVENT_LISTENER_REGISTRY_H
#define IEVENT_LISTENER_REGISTRY_H

#include <memory>

using std::unique_ptr;

class Event;
class IEventListener;

// Container for EventListeners.
class IEventListenerRegistry
{
public:
    IEventListenerRegistry() {}
    virtual ~IEventListenerRegistry() {}

    // Store the EventListener and corresponding Event to the registry.
    // Increases the container size by 1.
    virtual void registerListener(
        Event &event, IEventListener &eventListener) = 0;

    // Return the size of the container.
    virtual unsigned int getSize(void) const = 0;

    // Retrieve the EventListener that corresponds to the Event.
    virtual IEventListener &getListener(Event &event) const = 0;
};

#endif // IEVENT_LISTENER_REGISTRY_H
