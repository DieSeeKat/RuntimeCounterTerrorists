#include "Capital.h"
#include "../Empire.h"
#include "Town.h"
#include "Node.h"

Capital::Capital(){
  this->node = nullptr;
}

void Capital::colonise(Empire* empire)
{
  empire->dieOff();

  node->setNodeType(new Town(node));
}
Capital::~Capital()
{
}
Capital::Capital(Node* node) : NodeType(node)
{
}

NodeType* Capital::clone(std::map<void*,void*> &objmap){
  if(objmap.find(this)!=objmap.end()){
    return (NodeType*)((*objmap.find(this)).second);
  }
  else{
    Capital* temp = new Capital();
    objmap.insert(std::pair<void*,void*>(this, temp));
    if(node)
      temp->node = node->clone(objmap);
    return temp;
  }
}