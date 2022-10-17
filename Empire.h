#ifndef EMPIRE_H
#define EMPIRE_H

#include <string>
#include <vector>

#include "Alliance/Alliance.h"
#include "Alliance/AllianceComponent.h"

#include "Army.h"

#include "Graph/Node.h"

#include "Policies/ColonyPolicy.h"
#include "Policies/RecruitmentPolicy.h"
#include "Policies/WarStylePolicy.h"

#include "WarStages/WarStage.h"

class Empire : public AllianceComponent
{
  private:
  std::vector<Node *> owned_nodes;
  std::string name;
  ColonyPolicy *colony_policy;
  WarStylePolicy *war_style_policy;
  RecruitmentPolicy *recruitment_policy;
  WarStage *war_stage;
  Alliance **alliances;
  std::vector<Army> armies;

  public:
  Empire(std::string name);
  void algorithm();
  void request();
  void action();
  void recruit();
  void takeTurn();
  void advanceArmies();
  void retreatArmies();
  void restoreTowns();
  void addTown(Node *town);
  void joinAlliance(Empire *empire);
  void add(AllianceComponent *alliance_component);
  void remove(AllianceComponent *alliance_component);
  bool isAlly(Empire * empire);

  AllianceComponent *getChild(int index);
};

#endif
