//
// Created by Lukas Anthonissen on 2022/10/25.
//

#include "gtest/gtest.h"
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

#include "ArcheryBarracks.h"
#include "Barracks.h"
#include "CavalryBarracks.h"
#include "FootmenBarracks.h"
#include "SlingerBarracks.h"

#include "../Units/Archer.h"
#include "../Units/Cavalry.h"
#include "../Units/Footmen.h"
#include "../Units/Slinger.h"
#include "../Units/Unit.h"

#include "../ArmyRatio.h"
#include "../Empire.h"
#include "../Memento/War.h"

TEST(Barracks, CreateUnitsTest)
{
  int num_units = 5;

  Barracks *archer_barracks  = new ArcheryBarracks();
  Barracks *cavalry_barracks = new CavalryBarracks();
  Barracks *footmen_barracks = new FootmenBarracks();
  Barracks *slinger_barracks = new SlingerBarracks();

  archer_barracks->createUnits(num_units);
  cavalry_barracks->createUnits(num_units);
  footmen_barracks->createUnits(num_units);
  slinger_barracks->createUnits(num_units);

  std::vector<Unit *> archers = archer_barracks->getUnits();
  std::vector<Unit *> cavalry = cavalry_barracks->getUnits();
  std::vector<Unit *> slinger = slinger_barracks->getUnits();
  std::vector<Unit *> footmen = footmen_barracks->getUnits();

  ASSERT_EQ(archers.size(), num_units);
  ASSERT_EQ(cavalry.size(), num_units);
  ASSERT_EQ(slinger.size(), num_units);
  ASSERT_EQ(footmen.size(), num_units);
}

TEST(Barracks, NodeRecruit)
{
  ArmyRatio army_ratio = ArmyRatio(0.2, 0.2, 0.2, 0.4);

  War* war = new War();

  Empire* empire = new Empire("Rome", war);

  Node* node = new Node(empire, "Roma", 1000);

  Army* army = node->recruit(army_ratio, 501);

  ASSERT_TRUE(army->getNumUnits() > 501);
}