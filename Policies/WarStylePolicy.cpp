#include "WarStylePolicy.h"
#include <iostream>

WarStylePolicy::WarStylePolicy()
{
  std::cout<<"The Army is determining the ratio of units in the Army"<<std::endl;
}
WarStylePolicy::~WarStylePolicy()
{
}


WarStylePolicy* WarStylePolicy::clone(std::map<void*,void*> &objmap){
	if(objmap.find(this)!=objmap.end()){
		return (WarStylePolicy*)((*objmap.find(this)).second);
	}
	else{
		WarStylePolicy* temp = new WarStylePolicy();
		objmap.insert(std::pair<void*,void*>(this, temp));
		return temp;
	}
}