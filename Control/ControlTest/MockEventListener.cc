#ifndef MOCK_EVENT_LISTENER_CC
#define MOCK_EVENT_LISTENER_CC

#include <gmock/gmock.h>
#include "IEventListener.h"

class MockEventListener : public IEventListener
{
public:
    MockEventListener() {}
    MockEventListener(const MockEventListener &rhs) {}
    ~MockEventListener() override {}

    MOCK_METHOD(void, notify, (Event &));
    MOCK_METHOD(IEventListener *, copy, (), (const));

    bool operator==(const IEventListener &rhs) const
    {
        const MockEventListener *pRhs =
            dynamic_cast<const MockEventListener *>(&rhs);
        return nullptr != pRhs;
    }
};

#endif // MOCK_EVENT_LISTENER_CC
