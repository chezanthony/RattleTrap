#ifndef IMULTI_PIN_PHYSICAL_H
#define IMULTI_PIN_PHYSICAL_H

// brief:
// Interface for all physical components with more than one pin.
class IMultiPinPhysical
{
public:
    IMultiPinPhysical() {}
    virtual ~IMultiPinPhysical() {}

    virtual void setPin(const unsigned short nPinNumber,
                        const unsigned short nPin) = 0;
    virtual const unsigned short getPin(const unsigned short nPinNumber) const = 0;
};

#endif // IMULTI_PIN_PHYSICAL_H
