#include "Forest.h"
#include "../Terrain.h"
#include <iostream>
Forest::Forest() : Terrain()
{
}
Forest::~Forest()
{
}
int Forest::determineNeededResources(int army_size)
{
  int min_range = 2, max_range = 20;

  int random_num = rand() % (max_range - min_range) + min_range;

  return (random_num / 100) * army_size;
}
int Forest::determineNumDeaths(int army_size)
{
  int min_range = 2, max_range = 20;

  int random_num = rand() % (max_range - min_range) + min_range;

  int min_num     = 4;

  return (random_num / 100) * army_size + min_num;
}

Terrain* Forest::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (Terrain*)((*objmap.find(this)).second);
  }
  else{
    Forest* temp = new Forest();
    objmap.insert(std::pair<void*,void*>(this, temp));
    return temp;
  }
}