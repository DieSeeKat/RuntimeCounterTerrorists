#include "Plains.h"
#include <iostream>
using namespace std;


Plains::Plains() : Terrain()
{
  cout << "The Army has chosen to take the Plains path" << endl;
}
Plains::~Plains()
{
}
int Plains::determineNeededResources(int army_size)
{
  int return_resource = 0;
  int min_range = 1, max_range = 20;

  int random_num = rand() % (max_range - min_range) + min_range;

  return_resource = 2 * army_size + random_num;


  return return_resource;
}
int Plains::determineNumDeaths(int army_size)
{
  int min_range     = 5;
  int return_deaths = rand() % (army_size - min_range) + min_range;
  return return_deaths;
}
