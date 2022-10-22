#include "Town.h"
#include "Node.h"

Town::Town(){

}

void Town::colonise(Empire* empire)
{

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