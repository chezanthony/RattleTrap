#ifndef IEXECUTION_H
#define IEXECUTION_H

#include "ICopiable.h"

// Execution interface.
// Gets executed when a corresponding trigger is satisfied.
class IExecution : public ICopiable<IExecution>
{
public:
    IExecution() {}
    virtual ~IExecution() {}

    // Called to perform executions.
    virtual void execute(void) = 0;
};

#endif // IEXECUTION_H
