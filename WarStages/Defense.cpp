#include "Defense.h"
#include "Attack.h"

void Defense::takeTurn()
{
  empire->restoreTowns();
  empire->recruit();
  // TODO - Peace offerings
  empire->retreatArmies();
  if (empire->getPrevNumNodes() <= empire->getNodes().size())
  {
    empire->setState(new Attack(empire));
  }
  empire->setPrevNumNodes(empire->getNodes().size());
}
Defense::Defense(Empire *empire) : WarStage(empire)
{
}
Defense::~Defense()
{
}
