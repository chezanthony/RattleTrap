#ifndef IEVENT_MANAGER_H
#define IEVENT_MANAGER_H

class Event;
class IEventListener;

// Manages Events.
class IEventManager
{
public:
    IEventManager() {}
    virtual ~IEventManager() {}

    // Notify the system of the Event.
    virtual void notify(Event &event) = 0;

    // Register the event listener to the EventListenerRegistry.
    virtual void registerListener(
        Event &event, IEventListener &eventListener) = 0;
};

#endif // IEVENT_MANAGER_H
