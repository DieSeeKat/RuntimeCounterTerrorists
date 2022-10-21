#include "Desert.h"
#include <iostream>
Desert::Desert()
{
  std::cout << "The Army has chosen the Desert path" << std::endl;
}
Desert::~Desert()
{
}
int Desert::determineNeededResources(int army_size)
{
  int return_resource = 0;
  int min_range = 10, max_range = 30;

  int random_num = rand() % (max_range - min_range) + min_range;

  return_resource = 3 * army_size + random_num;


  return return_resource;
}
int Desert::determineNumDeaths(int army_size)
{
  int min_range     = 18;
  int return_deaths = rand() % (army_size - min_range) + min_range;
  return return_deaths;
}
