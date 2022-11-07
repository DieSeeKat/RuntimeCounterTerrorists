#ifndef UNIT_H
#define UNIT_H

#include <map>

class Unit
{

  protected:
  int damage = 0;
  int health = 0;

  public:
  /**
   * @brief Virtual clone method for Unit. Can be overridden by subclasses.
   * 
   * @param objmap map<void*,void*>
   * @return Unit* of the cloned unit.
   */
  virtual Unit* clone(std::map<void*, void*> &objmap);
    Unit(int damage,int health);
    Unit();

};

#endif
