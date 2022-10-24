#include "Terrain.h"
#include "Path.h"
#include "Empire.h"
#include <iostream>
using namespace std;

Terrain::Terrain()
{
}
Terrain::~Terrain()
{
}
void Terrain::calculate_losses(Army *army)
{
  int resources_needed = determineNeededResources(army->getArmySize());

  int difference = army->getResource() - resources_needed;

  army->setResource(difference);

  int num_deaths = 0;

  if (army->getResource() <= 0)
  {
    num_deaths = determineNumDeaths(army->getArmySize());

    if (num_deaths >= army->getArmySize())
    {
      num_deaths = army->getArmySize();
    }

    for (int i = 0; i < num_deaths; i++)
    {
      army->killRandomUnit();
    }
  }
}
