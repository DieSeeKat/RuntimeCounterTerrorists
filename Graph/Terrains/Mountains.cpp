#include "Mountains.h"
#include "../Terrain.h"
#include <iostream>
using namespace std;

Mountains::Mountains() : Terrain()
{
}
Mountains::~Mountains()
{
}
int Mountains::determineNeededResources(int army_size)
{
  int min_range = 20, max_range = 80;

  int random_num = rand() % (max_range - min_range) + min_range;

  return (random_num / 100) * army_size;
}
int Mountains::determineNumDeaths(int army_size)
{
  int min_range = 20, max_range = 80;

  int random_num = rand() % (max_range - min_range) + min_range;

  int min_num     = 10;

  return (random_num / 100) * army_size + min_num;
}

Terrain* Mountains::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (Terrain*)((*objmap.find(this)).second);
  }
  else{
    Mountains* temp = new Mountains();
    objmap.insert(std::pair<void*,void*>(this, temp));
    return temp;
  }
}