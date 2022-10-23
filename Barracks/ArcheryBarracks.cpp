#include "ArcheryBarracks.h"

Unit *ArcheryBarracks::factoryMethod(int numRecruits)
{
  // TODO - implement ArcheryBarracks::factoryMethod
  Archer** archers=new Archer*[numRecruits];

  for(int i=0;i<numRecruits;i++){
    archers[i]=new Archer();
  }

  return *archers;
}
