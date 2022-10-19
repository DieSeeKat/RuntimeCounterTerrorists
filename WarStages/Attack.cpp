#include "Attack.h"
#include "Defense.h"

void Attack::takeTurn()
{
  empire->restoreTowns();
  empire->recruit();
  empire->advanceArmies();
  if (empire->getPrevNumNodes() - empire->getNodes().size() > 2 || empire->getNodes().size() < 5)
  {
    empire->setState(new Defense(empire));
  }
  empire->setPrevNumNodes(empire->getNodes().size());
}
Attack::Attack(Empire *empire) : WarStage(empire)
{
}
