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
#include "../Empire.h"
#include "../Graph/Capital.h"
#include "../Graph/Node.h"
#include "../Graph/Town.h"
#include "../Memento/War.h"
#include "Observer.h"
#include "Subject.h"

TEST(Observer, MoveToTown_Test)
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

  Army *army_one = new Army(war, n2, e1);
  army_one->addUnit(Unit());
  e1->addArmy(army_one);
  army_one->rechargeResources();

  Army *army_two = new Army(war, n5, e2);
  army_two->addUnit(Unit());
  army_two->addUnit(Unit());
  e2->addArmy(army_two);
  army_two->rechargeResources();

  army_one->moveToTown(n3);

  ASSERT_EQ(n2->getObserverList().size(), 1);

  ASSERT_EQ(army_one->getPosition(), n3);

  army_one->moveToTown(n4);

  ASSERT_EQ(army_one->getPosition(), n4);

  ASSERT_EQ(n2->getObserverList().size(), 0);

  ASSERT_EQ(n3->getObserverList().size(), 1);

  army_two->moveToTown(n8);

  army_one->moveToTown(n5);

  ASSERT_EQ(n5->getOwnerEmpire(), e2);
  ASSERT_EQ(army_two->getPosition(), n5);
}


TEST(Observer, Attach_Test)
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

  Subject *subject = new Subject();
  Observer *army   = new Army(war, n2, e1);

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

  Subject *subject = new Subject();
  Observer *army   = new Army(war, n2, e1);

  subject->attach(army);

  subject->detach(army);

  ASSERT_EQ(subject->getObserverList().size(), 0);
}
