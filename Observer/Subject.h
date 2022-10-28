#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

#include <vector>
#include <iostream>

using namespace std;

class Subject
{

  private:
  /// A vector holding the list of armies
  vector<Observer*> observers;

  public:
  /**
   * @brief Adds an army to the Observer vector
   * @param observer gets pushed back into the observer vector
   */
  void attach(Observer *observer);
  /**
   * @brief Removes an army to the Observer vector
   * @param observer is used to find the element in the Observer vector and is then removed
   */
  void detach(Observer *observer);
  /**
   * @brief Iterates through the Observer vector and updates each army in the Observer vector
   */
  void notify();
  /**
   * @brief A getter for the Observer vector
   * @return Returns a Observer vector
   */
  std::vector<Observer* > getObserverList();

};

#endif
