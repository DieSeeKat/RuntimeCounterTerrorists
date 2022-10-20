#include "Mountains.h"
#include <iostream>
using namespace std;


Mountains::Mountains() : Terrain()
{
  cout << "The Army has chosen to take the Mountain path" << endl;
}
Mountains::~Mountains()
{
}
int Mountains::determineNeededResources(int army_size)
{
  int return_resource = 0;
  int min_range = 20, max_range = 80;

  int random_num = rand() % (max_range - min_range) + min_range;

  return_resource = 3 * army_size + random_num;


  return return_resource;
}
int Mountains::determineNumDeaths(int army_size)
{
  int min_range     = 10;
  int return_deaths = rand() % (army_size - min_range) + min_range;
  return return_deaths;
}
