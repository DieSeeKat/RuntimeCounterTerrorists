#include "Barracks.h"

void Barracks::createUnits(int num_units) {
	for (int i = 0; i < num_units; i++) {
      units.push_back(factoryMethod());
    }
}
std::vector<Unit *> Barracks::getUnits()
{
  return units;
}
void Barracks::clearUnits()
{
  units.clear();
}
