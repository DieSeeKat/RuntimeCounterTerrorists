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

TEST (System, DemoBuild) {
  War *roman_punic_war = new War();

  Empire *rome = new Empire("Rome", roman_punic_war);
  Empire *greece = new Empire("Greece", roman_punic_war);
  Empire *germania = new Empire("Germania", roman_punic_war);

  roman_punic_war->addEmpire(rome);
  roman_punic_war->addEmpire(greece);
  roman_punic_war->addEmpire(germania);

  Node* roma = new Node(roman_punic_war, rome, "Roma", 20000, true);
  Node* athens = new Node(roman_punic_war, greece, "Athens", 20000, true);
  Node* konigsberg = new Node(roman_punic_war, germania, "Königsberg", 20000, true);

  Node* n1 = new Node(roman_punic_war, rome, "n1", 1000);
  Node* n2 = new Node(roman_punic_war, rome, "n2", 1000);
  Node* n3 = new Node(roman_punic_war, rome, "n3", 1000);
  Node* n4 = new Node(roman_punic_war, rome, "n4", 1000);
  Node* n5 = new Node(roman_punic_war, rome, "n5", 1000);
  Node* n6 = new Node(roman_punic_war, rome, "n6", 1000);
  Node* n7 = new Node(roman_punic_war, rome, "n7", 1000);

  Node* n8 = new Node(roman_punic_war, germania, "n8", 1000);
  Node* n9 = new Node(roman_punic_war, germania, "n9", 1000);
  Node* n15 = new Node(roman_punic_war, germania, "n15", 1000);

  Node* n10 = new Node(roman_punic_war, greece, "n10", 1000);
  Node* n11 = new Node(roman_punic_war, greece, "n11", 1000);
  Node* n12 = new Node(roman_punic_war, greece, "n12", 1000);
  Node* n13 = new Node(roman_punic_war, greece, "n13", 1000);
  Node* n14 = new Node(roman_punic_war, greece, "n14", 1000);
  Node* n16 = new Node(roman_punic_war, greece, "n16", 1000);

  roma->addPathTo(n1);
  konigsberg->addPathTo(n7);
  konigsberg->addPathTo(n8);
  konigsberg->addPathTo(n9);
  athens->addPathTo(n12);
  athens->addPathTo(n16);

  n1->addPathTo(n2);
  n1->addPathTo(n4);
  n1->addPathTo(n6);

  n2->addPathTo(n3);
  n2->addPathTo(n4);

  n3->addPathTo(n4);
  n3->addPathTo(n6);

  n4->addPathTo(n6);
  n4->addPathTo(n7);

  n5->addPathTo(n7);
  n5->addPathTo(n11);

  n6->addPathTo(n7);
  n6->addPathTo(n8);

  n7->addPathTo(n8);
  n7->addPathTo(n9);
  n7->addPathTo(n10);

  n8->addPathTo(n9);

  n9->addPathTo(n10);
  n9->addPathTo(n15);

  n10->addPathTo(n11);
  n10->addPathTo(n12);
  n10->addPathTo(n13);
  n10->addPathTo(n14);
  n10->addPathTo(n15);

  n11->addPathTo(n12);

  n12->addPathTo(n13);
  n12->addPathTo(n16);

  n13->addPathTo(n14);
  n13->addPathTo(n16);

  n14->addPathTo(n15);
  n14->addPathTo(n16);

  roman_punic_war->addNode(roma);
  roman_punic_war->addNode(athens);
  roman_punic_war->addNode(konigsberg);

  roman_punic_war->addNode(n1);
  roman_punic_war->addNode(n2);
  roman_punic_war->addNode(n3);
  roman_punic_war->addNode(n4);
  roman_punic_war->addNode(n5);
  roman_punic_war->addNode(n6);
  roman_punic_war->addNode(n7);
  roman_punic_war->addNode(n8);
  roman_punic_war->addNode(n9);
  roman_punic_war->addNode(n10);
  roman_punic_war->addNode(n11);
  roman_punic_war->addNode(n12);
  roman_punic_war->addNode(n13);
  roman_punic_war->addNode(n14);
  roman_punic_war->addNode(n15);
  roman_punic_war->addNode(n16);

  while (!roman_punic_war->isFinished()) {

    roman_punic_war->nextTurn();

  }

  ASSERT_TRUE(roman_punic_war->getEmpires().size() == 1);
}