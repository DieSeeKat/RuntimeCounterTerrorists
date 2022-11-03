#include "Subject.h"
#include "Observer.h"

void Subject::attach(Observer *observer)
{
  this->observers.push_back(observer);
}

void Subject::detach(Observer *observer)
{
  vector<Observer *>::iterator it = this->observers.begin();
  while ((it != this->observers.end()))
  {
    if (*it == observer)
    {
      this->observers.erase(it);
      return;
    }
    ++it;
  }
}

void Subject::notify()
{
  for (auto army : observers)
  {
    army->update();
  }
}

std::vector<Observer *> Subject::getObserverList()
{
  return observers;
}
