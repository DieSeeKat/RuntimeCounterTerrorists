//
// Created by Adam on 2022/10/20.
//


#include "gtest/gtest.h"
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

#include "../Army.h"
#include "Observer.h"
#include "Subject.h"
#include "../Empire.h"
#include "../Graph/Capital.h"
#include "../Graph/Node.h"
#include "../Graph/Town.h"
#include "../Memento/War.h"

TEST(Observer, MoveToTown_Test)
{
War *war = new War();

Empire *e1 = new Empire("Rome");
Empire *e2 = new Empire("Greece");

war->addEmpire(e1);
war->addEmpire(e2);

Node *c1 = new Capital(e1, 4);
Node *n2 = new Town(e1, 4);
Node *n3 = new Town(e1, 4);
Node *n4 = new Town(e2, 4);
Node *n5 = new Town(e2, 4);
Node *n6 = new Town(e1, 4);
Node *n7 = new Town(e1, 4);
Node *n8 = new Town(e2, 4);
Node *c2 = new Capital(e2, 4);


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

Army * army = new Army(n2,e1);

ASSERT_EQ(n2->getObserverList().size(), 1);

army->moveToTown(n3);

ASSERT_EQ(n2->getObserverList().size(), 0);

ASSERT_EQ(n3->getObserverList().size(), 1);

ASSERT_EQ(army->getPosition(), n3);

army->moveToTown(n4);

ASSERT_EQ(n3->getObserverList().size(), 0);

ASSERT_EQ(n4->getObserverList().size(), 1);

ASSERT_EQ(army->getPosition(), n4);

army->moveToTown(n3);

ASSERT_EQ(n4->getObserverList().size(), 0);

ASSERT_EQ(n3->getObserverList().size(), 1);


ASSERT_EQ(army->getPosition(), n3);



Army *attacking_army = new Army(c1, e1);

e1->addArmy(attacking_army);

attacking_army->addUnit(Unit());

attacking_army->addUnit(Unit());

Army *defending_army1 = new Army(n5, e2);
Army *defending_army2 = new Army(n8, e2);

n5->addStationedArmy(defending_army1);
n8->addStationedArmy(defending_army1);

e2->addArmy(defending_army1);
e2->addArmy(defending_army2);

defending_army1->addUnit(Unit());
defending_army2->addUnit(Unit());

//attacking_army->attackTown(n8);

e2->retreatArmies();

ASSERT_EQ(defending_army1->getPosition(), n5);




}


TEST(Observer, Attach_Test)
{
  War *war = new War();

  Empire *e1 = new Empire("Rome");
  Empire *e2 = new Empire("Greece");

  war->addEmpire(e1);
  war->addEmpire(e2);

  Node *c1 = new Capital(e1, 4);
  Node *n2 = new Town(e1, 4);
  Node *n3 = new Town(e1, 4);
  Node *n4 = new Town(e2, 4);
  Node *n5 = new Town(e2, 4);
  Node *n6 = new Town(e1, 4);
  Node *n7 = new Town(e1, 4);
  Node *n8 = new Town(e2, 4);
  Node *c2 = new Capital(e2, 4);


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

  Subject* subject = new Subject();
  Observer * army = new Army(n2,e1);

  subject->attach(army);


  ASSERT_EQ(subject->getObserverList().size(), 1);


}


TEST(Observer, Detach_Test)
{
  War *war = new War();

  Empire *e1 = new Empire("Rome");
  Empire *e2 = new Empire("Greece");

  war->addEmpire(e1);
  war->addEmpire(e2);

  Node *c1 = new Capital(e1, 4);
  Node *n2 = new Town(e1, 4);
  Node *n3 = new Town(e1, 4);
  Node *n4 = new Town(e2, 4);
  Node *n5 = new Town(e2, 4);
  Node *n6 = new Town(e1, 4);
  Node *n7 = new Town(e1, 4);
  Node *n8 = new Town(e2, 4);
  Node *c2 = new Capital(e2, 4);


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

  Subject* subject = new Subject();
  Observer * army = new Army(n2,e1);

  subject->attach(army);

  subject->detach(army);


  ASSERT_EQ(subject->getObserverList().size(), 0);


}

