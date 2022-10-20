#include "Army.h"
#include "Empire.h"
#include "Memento/War.h"

Army::Army(Node* current_position)
{
    position = current_position;

}

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
    if (town == position)
    {
        std::cout << "Army is already in that town" << std::endl;

    }

    else
    {
      town->removeObserver(this);
      town = position;
      town->addObserver(this);

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
