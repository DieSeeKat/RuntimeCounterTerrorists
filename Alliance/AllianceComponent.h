#ifndef ALLIANCECOMPONENT_H
#define ALLIANCECOMPONENT_H

#include <string>

class AllianceComponent
{

  private:
  std::string alliance_name;

  public:
  AllianceComponent(std::string name);

  virtual void add(AllianceComponent *alliance_component) = 0;

  virtual void remove(AllianceComponent *alliance_component) = 0;

  virtual AllianceComponent *getChild(int index) = 0;

  void setAllianceName(std::string name);

  std::string getAllianceName();
};

#endif
