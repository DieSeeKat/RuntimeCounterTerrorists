#include "Plains.h"
#include "../Terrain.h"
#include <iostream>
using namespace std;


Plains::Plains() : Terrain()
{
}
Plains::~Plains()
{
}
int Plains::determineNeededResources(int army_size)
{
  int min_range = 1, max_range = 20;

  int random_num = rand() % (max_range - min_range) + min_range;

  return (random_num / 100) * army_size;
}
int Plains::determineNumDeaths(int army_size)
{
  int min_range = 1, max_range = 20;

  int random_num = rand() % (max_range - min_range) + min_range;

  int min_num     = 5;

  return (random_num / 100) * army_size + min_num;
}

Terrain* Plains::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (Terrain*)((*objmap.find(this)).second);
  }
  else{
    Plains* temp = new Plains();
    objmap.insert(std::pair<void*,void*>(this, temp));
    return temp;
  }
}