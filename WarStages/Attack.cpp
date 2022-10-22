#include "Attack.h"
#include "Defense.h"

Attack::Attack(){
  
}

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
Attack::~Attack()
{
}

WarStage* Attack::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (WarStage*)((*objmap.find(this)).second);
  }
  else{
    Attack* temp = new Attack();
    objmap.insert(std::pair<void*,void*>(this, temp));
    temp->empire = empire->clone(objmap);
    return temp;
  }
}