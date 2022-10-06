#ifndef EMPIRE_H
#define EMPIRE_H

#include "Alliance/Alliance.h"
#include "Alliance/AllianceComponent.h"

#include "Army.h"

#include "Graph/Node.h"

#include "Policies/ColonyPolicy.h"
#include "Policies/RecruitmentPolicy.h"
#include "Policies/WarStylePolicy.h"

#include "WarStages/WarStage.h"

class Empire : AllianceComponent
{

  private:
  ColonyPolicy *colony_policy;
  WarStylePolicy *war_style_policy;
  RecruitmentPolicy *recruitment_policy;
  WarStage *war_stage;
  Alliance **alliances;

  public:
  void algorithm();

  void request();

  void action();

  Army recruit();

  void takeTurn();

  void addTown(Node *town);

  void joinAlliance(Empire *empire);

  void add(AllianceComponent *alliance_component);

  void remove(AllianceComponent *alliance_component);

  AllianceComponent *getChild(int index);
};

#endif
