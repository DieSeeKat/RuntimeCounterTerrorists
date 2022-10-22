//
// Created by Lukas Anthonissen on 2022/10/21.
//

#include "gtest/gtest.h"
#include <iostream>

#include "../Army.h"
#include "../Empire.h"
#include "../Units/Unit.h"
#include "Path.h"

TEST(Path, EnoughResources_TEST)
{
  Empire *e1 = new Empire("Rome");

  Node* node = new Node(e1, 4);

  Army *army = new Army(node, e1);
  e1->addArmy(army);
  for (int i = 0; i < 100; i++)
  {
    army->addUnit(Unit());
  }
  army->rechargeResources();

  Path *path = new Path(nullptr, nullptr);

  int previous_size = army->getArmySize();

  path->calculate_losses(army);

  ASSERT_TRUE(previous_size == army->getArmySize());
}

TEST(Path, SurvivePath_TEST)
{
  Empire *e1 = new Empire("Rome");

  Node* node = new Node(e1, 4);

  Army *army = new Army(node, e1);
  e1->addArmy(army);
  for (int i = 0; i < 100; i++)
  {
    army->addUnit(Unit());
  }
  army->setResource(0);

  Path *path = new Path(nullptr, nullptr);

  int previous_size = army->getArmySize();

  path->calculate_losses(army);

  ASSERT_TRUE(previous_size > army->getArmySize());
}

TEST(Path, Die_TEST)
{
  Empire *e1 = new Empire("Rome");

  Node* node = new Node(e1, 4);

  Army *army = new Army(node, e1);
  e1->addArmy(army);
  for (int i = 0; i < 5; i++)
  {
    army->addUnit(Unit());
  }
  army->setResource(0);

  Path *path = new Path(nullptr, nullptr);

  path->calculate_losses(army);

  ASSERT_TRUE(e1->getArmies().size() == 0);
}