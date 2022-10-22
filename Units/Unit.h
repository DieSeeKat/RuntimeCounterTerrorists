#ifndef UNIT_H
#define UNIT_H

#include <map>

class Unit
{

  protected:
  int damage;
  int health;

  public:
  virtual Unit* clone(std::map<void*, void*> &objmap);
};

#endif
