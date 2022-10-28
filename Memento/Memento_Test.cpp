//
// Created by Lukas Anthonissen on 2022/10/21.
//

#include "gtest/gtest.h"

#include "../Army.h"
#include "../Empire.h"
#include "../Graph/Capital.h"
#include "../Graph/Node.h"
#include "../Graph/Town.h"
#include "War.h"
#include "../Graph/NodeType.h"
#include "WarCaretaker.h"
#include "WarRollback.h"

TEST(Memento, Backup)
{

  War *war = new War();

  Empire *e1 = new Empire("Rome");
  Empire *e2 = new Empire("Greece");

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

  WarCaretaker *caretaker = new WarCaretaker();
  caretaker->storeMemento(war->createWarRollback());

  // Do stuff

  War *backupWar = new War();
  backupWar->setWarRollback(caretaker->getMemento());

  ASSERT_NE(war, backupWar);
  ASSERT_NE(war->getEmpires(), backupWar->getEmpires());
  ASSERT_NE(war->getEmpires().begin(), backupWar->getEmpires().begin());
  ASSERT_NE(war->getEmpires(), backupWar->getEmpires());
  ASSERT_NE(war->getNodes(), backupWar->getNodes());
  ASSERT_STREQ(war->getEmpires().at(0)->getCapital()->getName().c_str(), backupWar->getEmpires().at(0)->getCapital()->getName().c_str());
  ASSERT_NE(war->getEmpires().at(0)->getCapital(), backupWar->getEmpires().at(0)->getCapital());

  if (war->getPaths().size() == 0)
  {
    ASSERT_EQ(war->getPaths(), backupWar->getPaths());
  }
  else
  {
    ASSERT_NE(war->getPaths(), backupWar->getPaths());
  }

  for (auto a : war->getEmpires())
  {
    for (auto b : backupWar->getEmpires())
    {
      ASSERT_NE(a, b);
      if (war->objmap.find(a) != war->objmap.end() && b == (*war->objmap.find(a)).second)
      {
        ASSERT_STREQ(a->getName().c_str(), b->getName().c_str());

        ASSERT_NE(a->getArmies(), b->getArmies());
        ASSERT_EQ(a->getArmies().size(), b->getArmies().size());
        ASSERT_NE(a->getCapital(), b->getCapital());
        ASSERT_NE(a->getNodes(), b->getNodes());
        ASSERT_EQ(a->getNodes().size(), b->getNodes().size());
        ASSERT_NE(a->getWar(), b->getWar());

        ASSERT_EQ(a->getPrevNumNodes(), b->getPrevNumNodes());
        Node *a_c = a->getCapital(), *b_c = b->getCapital();
        ASSERT_STREQ(a_c->getName().c_str(), b_c->getName().c_str());
        ASSERT_TRUE(dynamic_cast<Town *>(a_c) == dynamic_cast<Town *>(b_c) || dynamic_cast<Capital *>(a_c) == dynamic_cast<Capital *>(b_c));
      }
    }
  }

  for (auto a : war->getNodes())
  {
    for (auto b : backupWar->getNodes())
    {
      ASSERT_NE(a, b);
      if (war->objmap.find(a) != war->objmap.end() && b == (*war->objmap.find(a)).second)
      {
        ASSERT_STREQ(a->getName().c_str(), b->getName().c_str());
        ASSERT_TRUE(dynamic_cast<Town *>(a->getNodeType()) == dynamic_cast<Town *>(b->getNodeType()) || dynamic_cast<Capital *>(a->getNodeType()) == dynamic_cast<Capital *>(b->getNodeType()));
        if (a->getObserverList().size() > 0 && b->getObserverList().size() > 0)
          ASSERT_NE(a->getObserverList(), b->getObserverList());
        else
          ASSERT_EQ(a->getObserverList(), b->getObserverList());
        ASSERT_NE(a->getOwnerEmpire(), b->getOwnerEmpire());
        ASSERT_NE(a->getPaths(), b->getPaths());
        ASSERT_EQ(a->getPopulation(), b->getPopulation());
        ASSERT_EQ(a->getResources(), b->getResources());
        if (a->getStationedArmies().size() > 0 && b->getStationedArmies().size() > 0)
          ASSERT_NE(a->getStationedArmies(), b->getStationedArmies());
        else
          ASSERT_EQ(a->getStationedArmies(), b->getStationedArmies());
      }
    }
  }

  //Show that backupWar can continue even if original war gets deleted.
  delete war;
  ASSERT_STREQ(backupWar->getEmpires().at(0)->getName().c_str(), "Rome");
  ASSERT_STREQ(backupWar->getEmpires().at(1)->getName().c_str(), "Greece");
}