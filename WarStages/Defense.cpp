#include "Defense.h"
#include "Attack.h"

Defense::Defense(){

}

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

WarStage* Defense::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (WarStage*)((*objmap.find(this)).second);
  }
  else{
    Defense* temp = new Defense();
    objmap.insert(std::pair<void*,void*>(this, temp));
    temp->empire = empire->clone(objmap);
    return temp;
  }
}