#include "Defense.h"
#include "Attack.h"
#include "../Memento/War.h"

Defense::Defense(){

}

void Defense::takeTurn()
{
  empire->restoreTowns();
  empire->recruit();

  for (auto other_empire : empire->getWar()->getEmpires()) {
    if (!empire->isAlly(other_empire)){
      empire->requestAlliance(other_empire);
    }
  }

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

WarStage* Defense::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (WarStage*)((*objmap.find(this)).second);
  }
  else{
    Defense* temp = new Defense();
    objmap.insert(std::pair<void*,void*>(this, temp));
    if(empire)
      temp->empire = empire->clone(objmap);
    return temp;
  }
}