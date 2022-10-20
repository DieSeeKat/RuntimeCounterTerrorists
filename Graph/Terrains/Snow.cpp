#include "Snow.h"
#include <iostream>
Snow::Snow()
{
  std::cout<<"The Army has chosen the Snow path"<<std::endl;
}
Snow::~Snow()
{
}
int Snow::determineNeededResources(int army_size)
{
  int return_resource = 0;
  int min_range = 15, max_range = 50;

  int random_num = rand() % (max_range - min_range) + min_range;

  return_resource = 2 * army_size + random_num;


  return return_resource;
}
int Snow::determineNumDeaths(int army_size)
{
  int min_range     = 7;
  int return_deaths = rand() % (army_size - min_range) + min_range;
  return return_deaths;
}
