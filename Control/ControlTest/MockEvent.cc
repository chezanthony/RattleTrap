#ifndef MOCK_EVENT_CC
#define MOCK_EVENT_CC

#include <gmock/gmock.h>
#include "Event.h"
#include "IPhysical.h"
#include "DeviceValue.h"

class MockEvent : public Event
{
public:
    MockEvent() {}

    MOCK_METHOD(const IPhysical &, getComponent, ());
    MOCK_METHOD(const DeviceValue, getDeviceValue, ());
};

#endif // MOCK_EVENT_CC
