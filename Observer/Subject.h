#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

#include <vector>
#include <iostream>

using namespace std;

class Subject
{

  private:
  vector<Observer*> observer;

  public:
  void attach(Observer *observer);

  void detach(Observer *observer);

  void notify();

  std::vector<Observer* > getObserverList();

};

#endif
