#include "Unit.h"

Unit* Unit::clone(std::map<void*, void*> &objmap){
    if(objmap.find(this)!=objmap.end()){
        return (Unit*)((*objmap.find(this)).second);
    }
    else{
        Unit* temp = new Unit();
        objmap.insert(std::pair<void*,void*>(this, temp));

        temp->health = health;
        temp->damage = damage;
        return temp;
    }
Unit::Unit(int damage,int health){
    this->damage=damage;
    this->health=health;
}