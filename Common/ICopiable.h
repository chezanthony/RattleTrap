#ifndef ICOPIABLE_H
#define ICOPIABLE_H

template <typename T>
class ICopiable
{
public:
    ICopiable() {}
    virtual ~ICopiable() {}

    virtual T *copy(void) const = 0;
};

#endif // ICOPIABLE_H
