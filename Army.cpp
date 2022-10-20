#include "Army.h"

void Army::update()
{
    moveToTown(subject);
}

void Army::attackTown(Node *town)
{
  // TODO - implement Army::attackTown
  throw "Not yet implemented";
}

void Army::moveToTown(Node *town)
{
    if (position == town)
    {
        std::cout << "Army is already in that town" << std::endl;

    }

    else
    {
        position = town;

        std::cout << "Army has been moved to " << position << std::endl;
    }
}

void Army::defendTown(Node *town)
{
  // TODO - implement Army::defendTown
  throw "Not yet implemented";
}
Node *Army::getPosition()
{
  return position;
}
