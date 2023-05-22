#ifndef IEVENT_LISTENER_H
#define IEVENT_LISTENER_H

#include "ICopiable.h"

class Event;

// EventListener interface.
// Gets notified when a specified Event is generated.
// Performs corresponding actions once specified Event is received.
class IEventListener : public ICopiable<IEventListener>
{
public:
    IEventListener() {}
    virtual ~IEventListener() {}

    virtual void notify(Event &event) = 0;
};

#endif // IEVENT_LISTENER_H
