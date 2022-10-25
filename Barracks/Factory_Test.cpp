//
// Created by Lukas Anthonissen on 2022/10/25.
//

#include "gtest/gtest.h"
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

#include "Barracks.h"
#include "ArcheryBarracks.h"
#include "CavalryBarracks.h"
#include "FootmenBarracks.h"
#include "SlingerBarracks.h"

#include "../Units/Unit.h"
#include "../Units/Archer.h"
#include "../Units/Cavalry.h"
#include "../Units/Footmen.h"
#include "../Units/Slinger.h"

TEST(Barracks, CreateUnitsTest)
{
  int num_units = 5;

  Barracks* archer_barracks = new ArcheryBarracks();
  Barracks* cavalry_barracks = new CavalryBarracks();
  Barracks* footmen_barracks = new FootmenBarracks();
  Barracks* slinger_barracks = new SlingerBarracks();

  archer_barracks->createUnits(num_units);
  cavalry_barracks->createUnits(num_units);
  footmen_barracks->createUnits(num_units);
  slinger_barracks->createUnits(num_units);

  std::vector<Unit*> archers = archer_barracks->getUnits();
  std::vector<Unit*> cavalry = cavalry_barracks->getUnits();
  std::vector<Unit*> slinger = slinger_barracks->getUnits();
  std::vector<Unit*> footmen = footmen_barracks->getUnits();

  ASSERT_EQ(archers.size(), num_units);
  ASSERT_EQ(cavalry.size(), num_units);
  ASSERT_EQ(slinger.size(), num_units);
  ASSERT_EQ(footmen.size(), num_units);
}