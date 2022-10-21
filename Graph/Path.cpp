#include "Path.h"
#include "Terrains/Desert.h"
#include "Terrains/Forest.h"
#include "Terrains/Mountains.h"
#include "Terrains/Plains.h"
#include "Terrains/Snow.h"
#include <iostream>
#include <string>
using namespace std;

Path::Path(Node *first_node, Node *last_node)
{
  end_points.push_back(first_node);
  end_points.push_back(last_node);

  this->terrain_type = new Plains();

}

void Path::calculate_losses(Army *army)
{
  terrain_type->calculate_losses(army);
}

Path ::~Path()
{
  delete terrain_type;
}

//------------------------------------------------------------------
Node *Path::getOppositeEnd(Node *node)
{
  if (end_points.at(0) == node)
  {
    return end_points.at(1);
  }
  else
  {
    return end_points.at(0);
  }
}

/**
 * @todo Implement this clone
*/
Path* Path::clone(std::map<void*, void*> &objmap){
  return NULL;
}

Path::Path(Node *first_node, Node *last_node, std::string terrain_type)
{
  end_points.push_back(first_node);
  end_points.push_back(last_node);

  if (terrain_type == "desert") {
    this->terrain_type = new Desert();
  }else if (terrain_type == "forest") {
    this->terrain_type = new Forest();
  }else if (terrain_type == "mountains") {
    this->terrain_type = new Mountains();
  } else if (terrain_type == "snow") {
    this->terrain_type = new Snow();
  } else {
    this->terrain_type = new Plains();
  }
}
