#include "ArcheryBarracks.h"

Unit *ArcheryBarracks::factoryMethod()
{
  return new Archer();
}
ArcheryBarracks::ArcheryBarracks()
{
}
