#include "Snow.h"
#include "../Terrain.h"
#include <iostream>
Snow::Snow() : Terrain()
{
}
Snow::~Snow()
{
}
int Snow::determineNeededResources(int army_size)
{
  int min_range = 15, max_range = 50;

  int random_num = rand() % (max_range - min_range) + min_range;

  return (random_num / 100) * army_size;
}
int Snow::determineNumDeaths(int army_size)
{
  int min_range = 15, max_range = 50;

  int random_num = rand() % (max_range - min_range) + min_range;

  int min_num     = 7;

  return (random_num / 100) * army_size + min_num;
}

Terrain* Snow::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (Terrain*)((*objmap.find(this)).second);
  }
  else{
    Snow* temp = new Snow();
    objmap.insert(std::pair<void*,void*>(this, temp));
    return temp;
  }
}