#include "Defense.h"

void Defense::takeTurn()
{
  empire->restoreTowns();
  empire->recruit();
  // TODO - Peace offerings
  empire->retreatArmies();
  // TODO - If certain conditions are met, switch to Attack
}
Defense::Defense(Empire *empire) : WarStage(empire)
{
}
