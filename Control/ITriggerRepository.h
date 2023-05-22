#ifndef ITRIGGER_REPOSITORY_H
#define ITRIGGER_REPOSITORY_H

class Trigger;

// Storage for all declared Triggers.
// Takes ownership of the Triggers and handles their memory management.
class ITriggerRepository
{
public:
    ITriggerRepository() {}
    virtual ~ITriggerRepository() {}

    // Store the Trigger.
    virtual void addTrigger(Trigger &trigger) = 0;
};

#endif // ITRIGGER_REPOSITORY_H