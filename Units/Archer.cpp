#include "Archer.h"

Unit* Archer::clone(std::map<void*, void*> &objmap){
    if(objmap.find(this)!=objmap.end()){
        return (Unit*)((*objmap.find(this)).second);
    }
    else{
        Archer* temp = new Archer();
        objmap.insert(std::pair<void*,void*>(this, temp));

        temp->health = health;
        temp->damage = damage;
        return temp;
    }
}