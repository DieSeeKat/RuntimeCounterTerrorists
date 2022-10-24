#include "AcceptAlliance.h"

AcceptAlliance::AcceptAlliance(Empire *_sender)
{
    sender = _sender;
}

void AcceptAlliance::handleAlliance(Empire * empire)
{
    sender->joinAlliance(empire);
}
