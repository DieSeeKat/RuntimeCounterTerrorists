#include "Cavalry.h"

Unit *Cavalry::clone(std::map<void *, void *> &objmap)
{
  if (objmap.find(this) != objmap.end())
  {
    return (Unit *) ((*objmap.find(this)).second);
  }
  else
  {
    Cavalry *temp = new Cavalry();
    objmap.insert(std::pair<void *, void *>(this, temp));

    temp->health = health;
    temp->damage = damage;
    return temp;
  }
}

Cavalry::Cavalry() : Unit(4, 4)
{
}