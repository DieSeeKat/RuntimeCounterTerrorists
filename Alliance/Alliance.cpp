#include "Alliance.h"

void Alliance::add(AllianceComponent* alliance_component)
{
  children.push_back(alliance_component);
}

void Alliance::remove(AllianceComponent* alliance_component)
{
  //find location of element to remove
  int location = -1;
  for(int i = 0; i < children.size(); i++)
  {
    if(children.at(i) == alliance_component)
    {
      location = i;
    }
  }

  if(location != -1){
    children.erase(children.begin()+ location);
  }

}

std::vector<AllianceComponent*> Alliance::getChildren()
{
  return children;
}

AllianceComponent* Alliance::getChild(int index) {
  return children.at(index);
}

/**
 * @todo Implement this clone
*/
Alliance* Alliance::clone(){
	return NULL;
}