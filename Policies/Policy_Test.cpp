//
// Created by Lukas Anthonissen on 2022/10/22.
//

#include "gtest/gtest.h"
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

#include "WarStylePolicy.h"
#include "RecruitmentPolicy.h"

#include "ArcherWarfare.h"
#include "GuerillaWarfare.h"
#include "HeavyWar.h"
#include "HorsemenWarfare.h"
#include "LegionaryWarfare.h"
#include "LightWar.h"
#include "NormalWar.h"

TEST (Policy, WarStylePolicy_Test) {
  WarStylePolicy* legionary_warfare = new LegionaryWarfare();
  ArmyRatio legionary_ratio = legionary_warfare->createArmyRatio();

  WarStylePolicy* horsemen_warfare = new HorsemenWarfare();
  ArmyRatio horsemen_ratio = horsemen_warfare->createArmyRatio();

  WarStylePolicy* guerilla_warfare = new LegionaryWarfare();
  ArmyRatio guerilla_ratio = guerilla_warfare->createArmyRatio();

  WarStylePolicy* archer_warfare = new ArcherWarfare();
  ArmyRatio archer_ratio = archer_warfare->createArmyRatio();

  delete legionary_warfare;
  delete horsemen_warfare;
  delete guerilla_warfare;
  delete archer_warfare;
}

TEST (Policy, RecruitmentPolicy) {
  int population = 1000;

  RecruitmentPolicy* heavy_war = new HeavyWar();
  int heavy_recruits = heavy_war->calculateRecruits(population);

  RecruitmentPolicy* normal_war = new NormalWar();
  int normal_recruit = normal_war->calculateRecruits(population);

  RecruitmentPolicy* light_war = new LightWar();
  int light_recruits = light_war->calculateRecruits(population);

  delete heavy_war;
  delete normal_war;
  delete light_war;
}