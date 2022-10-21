#include "Terrain.h"
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
    for (int i = 0; i < num_deaths; i++)
    {
      //determine random index in army vector size
      //delete that index
      army->killRandomUnit();
    }
  }

  if (army->getArmySize() <= 0)
  {
    cout << "The Army has perished along the path" << endl;
  }
  else
  {
    if (num_deaths == 0)
    {
      cout << "The Army has not lost a unit" << endl;
    }
    else
    {
      cout << "The Army has lost " << num_deaths << " units while on the path" << endl;
    }
  }
}
