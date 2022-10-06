#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

class Subject
{

  private:
  Observer *observer_list;

  public:
  void attach(Observer *observer);

  void detach(Observer *observer);

  void notify();
};

#endif
