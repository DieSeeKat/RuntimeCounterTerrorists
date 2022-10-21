//
// Created by Lukas Anthonissen on 2022/10/21.
//

#include "gtest/gtest.h"
#include <iostream>

#include "../Army.h"
#include "Path.h"
#include "../Units/Unit.h"

TEST(Path, CalculateLosses_TEST) {

  Army* army_one = new Army(nullptr, nullptr);
  for (int i = 0; i < 100; i++){
    army_one->addUnit(Unit());
  }
  army_one->rechargeResources();

  Army* army_two = new Army(nullptr, nullptr);
  for (int i = 0; i < 100; i++){
    army_two->addUnit(Unit());
  }
  army_two->setResource(0);

  Path* path = new Path(nullptr, nullptr);

  int previous_size_one = army_one->getArmySize();
  int previous_size_two = army_two->getArmySize();

  path->calculate_losses(army_one);
  path->calculate_losses(army_two);

  ASSERT_TRUE(previous_size_one == army_one->getArmySize());
  ASSERT_TRUE(previous_size_two > army_two->getArmySize());

}