#ifndef IPHYSICAL_H
#define IPHYSICAL_H

// Interface for all Physical components.
class IPhysical
{
public:
    IPhysical() {}
    virtual ~IPhysical() {}

    // Specify which Arduino pin the component is connected to.
    virtual void setPin(const unsigned short nPin) = 0;

    // Retrieve the pin the component is connected to.
    virtual const unsigned short getPin(void) const = 0;

    virtual bool operator==(const IPhysical &rhs) const = 0;
};

#endif // IPHYSICAL_H
