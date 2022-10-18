#include "AllianceComponent.h"

AllianceComponent::AllianceComponent(std::string name)
{
  this->alliance_name = name;
}

void AllianceComponent::setAllianceName(std::string name)
{
  this->alliance_name = name;
}

std::string AllianceComponent::getAllianceName()
{
  return alliance_name;
}