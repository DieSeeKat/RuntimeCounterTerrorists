#include "Town.h"
#include "Node.h"
#include <iostream>

Town::Town(){

}

void Town::colonise(Empire* empire)
{
#ifndef disable_output
  std::cout << node->getOwnerEmpire()->getName() << "'s city, " << node->getName()
            << ", has been captured by " << empire->getName() << "." << std::endl;
#endif
}
Town::Town(Node* node) : NodeType(node)
{
}
Town::~Town()
{
}

NodeType* Town::clone(std::map<void*,void*> &objmap){
    if(objmap.find(this)!=objmap.end()){
        return (NodeType*)((*objmap.find(this)).second);
    }
    else{
        Town* temp = new Town();
        objmap.insert(std::pair<void*,void*>(this, temp));
        if(node)
            temp->node = node->clone(objmap);
        return temp;
    }
}