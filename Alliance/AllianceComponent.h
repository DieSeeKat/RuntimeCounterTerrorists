#ifndef ALLIANCECOMPONENT_H
#define ALLIANCECOMPONENT_H

class AllianceComponent
{

  public:
  virtual void add(AllianceComponent *alliance_component) = 0;

  virtual void remove(AllianceComponent *alliance_component) = 0;

  virtual AllianceComponent *getChild(int index) = 0;
};

#endif
