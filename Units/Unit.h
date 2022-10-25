#ifndef UNIT_H
#define UNIT_H

#include <map>

class Unit
{

  protected:
  int damage = 0;
  int health = 0;

  public:
  virtual Unit* clone(std::map<void*, void*> &objmap);
    Unit(int damage,int health);

};

#endif
