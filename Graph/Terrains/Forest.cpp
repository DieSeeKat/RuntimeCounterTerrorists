#include "Forest.h"
#include <iostream>
Forest::Forest()
{
  std::cout<<"The Army has chosen the Forest path"<<std::endl;
}
Forest::~Forest()
{
}
int Forest::determineNeededResources(int army_size)
{
  int return_resource = 0;
  int min_range = 2, max_range = 20;

  int random_num = rand() % (max_range - min_range) + min_range;

  return_resource = 3 * army_size + random_num;


  return return_resource;
}
int Forest::determineNumDeaths(int army_size)
{
  int min_range     = 4;
  int return_deaths = rand() % (army_size - min_range) + min_range;
  return return_deaths;
}
