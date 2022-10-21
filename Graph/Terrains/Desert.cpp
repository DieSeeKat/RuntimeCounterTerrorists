#include "Desert.h"
#include "../Terrain.h"
#include <iostream>
Desert::Desert()
{
}
Desert::~Desert()
{
}
int Desert::determineNeededResources(int army_size)
{
  int min_range = 50, max_range = 70;

  int random_num = rand() % (max_range - min_range) + min_range;

  return (random_num / 100) * army_size;
}
int Desert::determineNumDeaths(int army_size)
{
  int min_range = 50, max_range = 70;

  int random_num = rand() % (max_range - min_range) + min_range;

  int min_num     = 18;

  return (random_num / 100) * army_size + min_num;
}
