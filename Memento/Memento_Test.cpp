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

TEST (Memento, Backup) {

  War *war = new War();

  Empire *e1 = new Empire("Rome");
  Empire *e2 = new Empire("Greece");
  Empire* e3 = new Empire("Israel");

  war->addEmpire(e1);
  war->addEmpire(e2);
  war->addEmpire(e3);

  Node *c1 = new Node(e1, "c1", 4, true);
  Node *n2 = new Node(e1, "n2", 4);
  Node *n3 = new Node(e1, "n3", 4);
  Node *n4 = new Node(e2, "n4", 4);
  Node *n5 = new Node(e2, "n5", 4);
  Node *n6 = new Node(e1, "n6", 4);
  Node *n7 = new Node(e1, "n7", 4);
  Node *n8 = new Node(e2, "n8", 4);
  Node *c2 = new Node(e2, "c2", 4, true);

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

  Army *army_one = new Army(c1, e1);
  e1->addArmy(army_one);
  army_one->addUnit(Unit());
  army_one->addUnit(Unit());
  Army *army_three = new Army(c1, e1);
  e1->addArmy(army_three);
  army_three->addUnit(Unit());
  army_three->addUnit(Unit());

  Army *army_two = new Army(n2, e2);
  e2->addArmy(army_two);
  army_two->addUnit(Unit());

  e1->joinAlliance(e2);

  e1->joinAlliance(e3);

  WarCaretaker* caretaker = new WarCaretaker();
  caretaker->storeMemento(war->createWarRollback());

  //Do stuff

  war->setWarRollback(caretaker->getMemento());

  //Test if everything is the same again

}