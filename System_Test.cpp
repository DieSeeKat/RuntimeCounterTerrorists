//
// Created by Lukas Anthonissen on 2022/10/20.
//

#include "gtest/gtest.h"
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

#include "Army.h"
#include "Empire.h"
#include "Graph/Capital.h"
#include "Graph/Node.h"
#include "Graph/NodeType.h"
#include "Graph/Town.h"
#include "Memento/War.h"

TEST(System, ArmyAttack)
{
  War *war = new War();

  Empire *e1 = new Empire("Rome", war);
  Empire *e2 = new Empire("Greece", war);

  war->addEmpire(e1);
  war->addEmpire(e2);

  Node *c1 = new Node(war, e1, "c1", 4, true);
  Node *n2 = new Node(war, e1, "n2", 4);
  Node *n3 = new Node(war, e1, "n3", 4);
  Node *n4 = new Node(war, e2, "n4", 4);
  Node *n5 = new Node(war, e2, "n5", 4);
  Node *n6 = new Node(war, e1, "n6", 4);
  Node *n7 = new Node(war, e1, "n7", 4);
  Node *n8 = new Node(war, e2, "n8", 4);
  Node *c2 = new Node(war, e2, "c2", 4, true);

  c1->addPathTo(n2);
  c1->addPathTo(n3);
  c1->addPathTo(n4);
  n2->addPathTo(n5);
  n3->addPathTo(n5);
  n3->addPathTo(n6);
  n4->addPathTo(n5);
  n4->addPathTo(n7);
  n5->addPathTo(n7);
  n5->addPathTo(n8);
  n6->addPathTo(n8);
  n7->addPathTo(n8);
  n7->addPathTo(c2);

  war->addNode(c1);
  war->addNode(n2);
  war->addNode(n3);
  war->addNode(n4);
  war->addNode(n5);
  war->addNode(n6);
  war->addNode(n7);
  war->addNode(n8);
  war->addNode(c2);

  Army *attacking_army = new Army(war, c1, e1);
  e1->addArmy(attacking_army);
  attacking_army->addUnit(Unit());
  attacking_army->addUnit(Unit());

  Army *defending_army = new Army(war, n8, e2);
  e2->addArmy(defending_army);
  defending_army->addUnit(Unit());

  attacking_army->attackTown(n8);

  ASSERT_EQ(n8->getOwnerEmpire(), e1);
  ASSERT_EQ(attacking_army->getNumUnits(), 1);
  ASSERT_EQ(e2->getArmies().size(), 1);
}

TEST(System, AdvanceArmies_Test)
{
  War *war = new War();

  Empire *e1 = new Empire("Rome", war);
  Empire *e2 = new Empire("Greece", war);

  war->addEmpire(e1);
  war->addEmpire(e2);

  Node *c1 = new Node(war, e1, "c1", 4, true);
  Node *n2 = new Node(war, e1, "n2", 4);
  Node *n3 = new Node(war, e1, "n3", 4);
  Node *n4 = new Node(war, e2, "n4", 4);
  Node *n5 = new Node(war, e2, "n5", 4);
  Node *n6 = new Node(war, e1, "n6", 4);
  Node *n7 = new Node(war, e1, "n7", 4);
  Node *n8 = new Node(war, e2, "n8", 4);
  Node *c2 = new Node(war, e2, "c2", 4, true);

  e1->setCapital(c1);
  e2->setCapital(c2);

  c1->addPathTo(n2);
  c1->addPathTo(n3);
  c1->addPathTo(n4);
  n2->addPathTo(n5);
  n3->addPathTo(n5);
  n3->addPathTo(n6);
  n4->addPathTo(n5);
  n4->addPathTo(n7);
  n5->addPathTo(n7);
  n5->addPathTo(n8);
  n6->addPathTo(n8);
  n7->addPathTo(n8);
  n7->addPathTo(c2);

  war->addNode(c1);
  war->addNode(n2);
  war->addNode(n3);
  war->addNode(n4);
  war->addNode(n5);
  war->addNode(n6);
  war->addNode(n7);
  war->addNode(n8);
  war->addNode(c2);

  Army *attacking_army = new Army(war, c1, e1);
  e1->addArmy(attacking_army);
  attacking_army->addUnit(Unit());
  attacking_army->addUnit(Unit());
  attacking_army->rechargeResources();

  Army *defending_army = new Army(war, n4, e2);
  e2->addArmy(defending_army);
  defending_army->addUnit(Unit());
  defending_army->rechargeResources();

  e1->advanceArmies();

  ASSERT_EQ(n4->getOwnerEmpire(), e1);
  ASSERT_EQ(attacking_army->getNumUnits(), 1);
  ASSERT_EQ(e2->getArmies().size(), 1);

  e1->advanceArmies();

  ASSERT_EQ(n7->getOwnerEmpire(), e1);
  ASSERT_TRUE(dynamic_cast<Town *>(c2->getNodeType()) == nullptr);

  e1->advanceArmies();

  ASSERT_EQ(c2->getOwnerEmpire(), e1);

  ASSERT_TRUE(dynamic_cast<Town *>(c2->getNodeType()) != nullptr);
}

TEST(System, RetreatArmies_Test)
{
  War *war = new War();

  Empire *e1 = new Empire("Rome", war);
  Empire *e2 = new Empire("Greece", war);

  war->addEmpire(e1);
  war->addEmpire(e2);

  Node *c1 = new Node(war, e1, "c1", 4, true);
  Node *n2 = new Node(war, e1, "n2", 4);
  Node *n3 = new Node(war, e1, "n3", 4);
  Node *n4 = new Node(war, e2, "n4", 4);
  Node *n5 = new Node(war, e2, "n5", 4);
  Node *n6 = new Node(war, e1, "n6", 4);
  Node *n7 = new Node(war, e1, "n7", 4);
  Node *n8 = new Node(war, e2, "n8", 4);
  Node *c2 = new Node(war, e2, "c2", 4, true);

  e1->setCapital(c1);
  e2->setCapital(c2);

  c1->addPathTo(n2);
  c1->addPathTo(n3);
  c1->addPathTo(n4);
  n2->addPathTo(n5);
  n3->addPathTo(n5);
  n3->addPathTo(n6);
  n4->addPathTo(n5);
  n4->addPathTo(n7);
  n5->addPathTo(n7);
  n5->addPathTo(n8);
  n6->addPathTo(n8);
  n7->addPathTo(n8);
  n7->addPathTo(c2);

  war->addNode(c1);
  war->addNode(n2);
  war->addNode(n3);
  war->addNode(n4);
  war->addNode(n5);
  war->addNode(n6);
  war->addNode(n7);
  war->addNode(n8);
  war->addNode(c2);

  Army *attacking_army = new Army(war, c2, e1);
  e1->addArmy(attacking_army);
  attacking_army->addUnit(Unit());
  attacking_army->addUnit(Unit());
  attacking_army->rechargeResources();

  e1->retreatArmies();

  ASSERT_TRUE(attacking_army->getPosition() == n7);

  e1->retreatArmies();

  ASSERT_TRUE(attacking_army->getPosition() == n7);
}

TEST(System, Deletes)
{
  War *war = new War();

  Empire *e1 = new Empire("Rome", war);
  Empire *e2 = new Empire("Greece", war);
  Empire *e3 = new Empire("Israel", war);

  war->addEmpire(e1);
  war->addEmpire(e2);
  war->addEmpire(e3);

  Node *c1 = new Node(war, e1, "c1", 4, true);
  Node *n2 = new Node(war, e1, "n2", 4);
  Node *n3 = new Node(war, e1, "n3", 4);
  Node *n4 = new Node(war, e2, "n4", 4);
  Node *n5 = new Node(war, e2, "n5", 4);
  Node *n6 = new Node(war, e1, "n6", 4);
  Node *n7 = new Node(war, e1, "n7", 4);
  Node *n8 = new Node(war, e2, "n8", 4);
  Node *c2 = new Node(war, e2, "c2", 4, true);

  e1->setCapital(c1);
  e2->setCapital(c2);

  c1->addPathTo(n2);
  c1->addPathTo(n3);
  c1->addPathTo(n4);
  n2->addPathTo(n5);

  n3->addPathTo(n5);
  n3->addPathTo(n6);
  n4->addPathTo(n5);
  n4->addPathTo(n7);
  n5->addPathTo(n7);
  n5->addPathTo(n8);
  n6->addPathTo(n8);
  n7->addPathTo(n8);
  n7->addPathTo(c2);

  war->addNode(c1);
  war->addNode(n2);
  war->addNode(n3);
  war->addNode(n4);
  war->addNode(n5);
  war->addNode(n6);
  war->addNode(n7);
  war->addNode(n8);
  war->addNode(c2);

  Army *army_one = new Army(war, c1, e1);
  e1->addArmy(army_one);
  army_one->addUnit(Unit());
  army_one->addUnit(Unit());
  Army *army_three = new Army(war, c1, e1);
  e1->addArmy(army_three);
  army_three->addUnit(Unit());
  army_three->addUnit(Unit());

  Army *army_two = new Army(war, n2, e2);
  e2->addArmy(army_two);
  army_two->addUnit(Unit());

  e1->joinAlliance(e2);

  e1->joinAlliance(e3);

  for (auto empire : war->getEmpires())
  {
    delete empire;
  }
  for (auto node : war->getNodes())
  {
    delete node;
  }
}

TEST(System, War_Is_Finished)
{
  War *war = new War();

  Empire *e1 = new Empire("Rome", war);
  Empire *e2 = new Empire("Greece", war);
  Empire *e3 = new Empire("Israel", war);

  war->addEmpire(e1);
  war->addEmpire(e2);
  war->addEmpire(e3);

  Node *c1 = new Node(war, e1, "c1", 4, true);
  Node *n2 = new Node(war, e1, "n2", 4);
  Node *n3 = new Node(war, e1, "n3", 4);
  Node *n4 = new Node(war, e2, "n4", 4);
  Node *n5 = new Node(war, e2, "n5", 4);
  Node *n6 = new Node(war, e1, "n6", 4);
  Node *n7 = new Node(war, e1, "n7", 4);
  Node *n8 = new Node(war, e2, "n8", 4);
  Node *c2 = new Node(war, e2, "c2", 4, true);

  e1->setCapital(c1);
  e2->setCapital(c2);

  c1->addPathTo(n2);
  c1->addPathTo(n3);
  c1->addPathTo(n4);
  n2->addPathTo(n5);

  n3->addPathTo(n5);
  n3->addPathTo(n6);
  n4->addPathTo(n5);
  n4->addPathTo(n7);
  n5->addPathTo(n7);
  n5->addPathTo(n8);
  n6->addPathTo(n8);
  n7->addPathTo(n8);
  n7->addPathTo(c2);

  war->addNode(c1);
  war->addNode(n2);
  war->addNode(n3);
  war->addNode(n4);
  war->addNode(n5);
  war->addNode(n6);
  war->addNode(n7);
  war->addNode(n8);
  war->addNode(c2);

  e1->joinAlliance(e2);

  ASSERT_TRUE(!war->isFinished());

  e1->joinAlliance(e3);

  ASSERT_TRUE(war->isFinished());
}

TEST(System, TakeTurn)
{
  War* war = new War();

  Empire* rome = new Empire("Rome", war);
  Empire* greece = new Empire("Greece", war);

  war->addEmpire(rome);
  war->addEmpire(greece);

  Node* roma = new Node(war, rome, "Roma", 1000, true);
  Node* athens = new Node(war, greece, "Athens", 700, true);
  Node* venice = new Node(war, greece, "Venice", 1000);

  rome->setCapital(roma);
  greece->setCapital(athens);

  roma->addPathTo(venice);
  venice->addPathTo(athens);

  war->addNode(roma);
  war->addNode(athens);
  war->addNode(venice);

  int turn = 0;

  while (!war->isFinished()) {
    cout << ++turn << endl;
    war->nextTurn();
  }

  ASSERT_EQ(athens->getOwnerEmpire(), rome);
  ASSERT_TRUE(war->isFinished());
}