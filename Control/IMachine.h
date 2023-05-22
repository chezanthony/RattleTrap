#ifndef IMACHINE_H
#define IMACHINE_H

class IPhysical;
class IMultiPinPhysical;
class IComponent;
class IEventListener;
class TriggerExecutionStatement;

// Base interface for all machine classes.
// Machine classes are the concrete classes that are used by users to
//  to represent their machines.
class IMachine
{
public:
    IMachine() {}
    virtual ~IMachine() {}

    // Run the machine.
    // Should be called in loop().
    virtual void run(void) = 0;

    // Add the Physical component to the PhysicalComponentRegistry.
    virtual void addPhysicalComponent(IPhysical &physicalComponent) = 0;

    // Add the MultiPinPhysical component to the PhysicalComponentRegistry.
    virtual void addPhysicalComponent(IMultiPinPhysical &physicalComponent) = 0;

    // Add the Component to the ComponentRepository.
    virtual void addComponent(IComponent &component) = 0;

    // Add the EventListener to the EventListenerRegistry.
    // virtual void addEventListener(IEventListener &eventListener) = 0;

    // Create a TriggerExecutionStatement from a component.
    virtual TriggerExecutionStatement when(IComponent &component) = 0;
};

#endif // IMACHINE_H
