#include "Army.h"

Army::Army(Node* current_position, Empire* owner_empire)
{
  position = current_position;
  empire = owner_empire;
}

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
Node *Army::getPosition()
{
  return position;
}
Army::~Army()
{
}
