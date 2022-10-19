#include "Army.h"

void Army::update()
{
  // TODO - implement Army::update
  throw "Not yet implemented";
}

void Army::attackTown(Node *town)
{
  // TODO - implement Army::attackTown
  throw "Not yet implemented";
}

void Army::moveToTown(Node *town)
{
  // TODO - implement Army::moveToTown
  throw "Not yet implemented";
}

void Army::defendTown(Node *town)
{
  // TODO - implement Army::defendTown
  throw "Not yet implemented";
}
//-------------------------------------------ADDED BY DHARSHAN GOPAUL
int Army::getResource()
{
  return resources;
}

void Army::setResource(int new_resource)
{
  resources = new_resource;
}

int Army::getArmySize()
{
  return army_size;
}

void Army::setArmySize(int new_size)
{
  army_size = new_size;
}
Node *Army::getPosition()
{
  return position;
}
void Army::killRandomUnit(int deaths)
{
}
