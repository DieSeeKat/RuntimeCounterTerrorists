
#include <iostream>
#include <vector>

#include "Army.h"
#include "Empire.h"
#include "Graph/Capital.h"
#include "Graph/Node.h"
#include "Graph/Town.h"
#include "Memento/War.h"
#include "Graph/NodeType.h"
#include "Memento/WarCaretaker.h"
#include "Memento/WarRollback.h"
#include <algorithm>

using namespace std;

int main()
{
  cout << "Hello, World!" << endl;

  if (true)
  {
    cout << "Yay. The formatting works!" << endl;
  }
  else
  {
    cout << "Nay. The formatting worksn't" << endl;
  }

  War *war = new War();

  Empire *e1 = new Empire("Rome");
  Empire *e2 = new Empire("Greece");

  war->addEmpire(e1);
  war->addEmpire(e2);

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

  Army *army_two = new Army(n8, e2);
  e2->addArmy(army_two);
  army_two->addUnit(Unit());

  WarCaretaker* caretaker = new WarCaretaker();
  caretaker->storeMemento(war->createWarRollback());

  //Do stuff

  war->setWarRollback(caretaker->getMemento());

  //Test if everything is the same again

}
