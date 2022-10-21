#include "Observer.h"


void Observer::registerSubject(Subject* subject)
{
  this->subject = subject;
}