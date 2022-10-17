#include "Attack.h"

void Attack::takeTurn()
{
  empire->restoreTowns();
  empire->recruit();
  empire->advanceArmies();
  // TODO - If certain conditions are met, switch to Defense.
}
Attack::Attack(Empire *empire) : WarStage(empire)
{
}
