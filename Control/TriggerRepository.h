#ifndef TRIGGER_REPOSITORY_H
#define TRIGGER_REPOSITORY_H

// #include <unordered_set>
#include <map>
#include "ITriggerRepository.h"
// #include "Trigger.h"

using std::move;
// using std::unordered_set;
using std::multimap;

class TriggerRepository : public ITriggerRepository
{
public:
    TriggerRepository() {}
    ~TriggerRepository() override {}

    void addTrigger(Trigger &trigger) override
    {
        // m_triggerSet.insert(move(trigger));
        // m_theMap.insert(trigger.get)
    }

private:
    // unordered_set<Trigger> m_triggerSet;
    // multimap<IComponent, DeviceValue> m_theMap;
};

#endif // TRIGGER_REPOSITORY_H