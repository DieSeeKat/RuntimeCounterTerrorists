#include "RequestAlliance.h"

RequestAlliance::RequestAlliance(Empire *_sender)
{
    sender = _sender;
}

void RequestAlliance::handleAlliance(Empire * empire)
{
    empire->considerAlliance(sender);
}
