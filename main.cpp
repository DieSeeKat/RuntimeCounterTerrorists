
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
#include "Policies/LightWar.h"

using namespace std;

War* romanPunicWars(){
  War *roman_punic_war = new War();

  Empire *rome = new Empire("Rome", roman_punic_war);
  Empire *greece = new Empire("Greece", roman_punic_war);
  Empire *germania = new Empire("Germania", roman_punic_war);

  roman_punic_war->addEmpire(rome);
  roman_punic_war->addEmpire(greece);
  roman_punic_war->addEmpire(germania);

  greece->setRecruitmentPolicy(new LightWar());
  germania->setRecruitmentPolicy(new LightWar());

  Node* roma = new Node(roman_punic_war, rome, "Roma", 2000, true);
  Node* athens = new Node(roman_punic_war, greece, "Athens", 2000, true);
  Node* konigsberg = new Node(roman_punic_war, germania, "Konigsberg", 2000, true);

  Node* n1 = new Node(roman_punic_war, rome, "n1", 1000);
  Node* n2 = new Node(roman_punic_war, rome, "n2", 1000);
  Node* n3 = new Node(roman_punic_war, rome, "n3", 1000);
  Node* n4 = new Node(roman_punic_war, rome, "n4", 1000);
  Node* n5 = new Node(roman_punic_war, rome, "n5", 1000);
  Node* n6 = new Node(roman_punic_war, rome, "n6", 1000);
  Node* n7 = new Node(roman_punic_war, rome, "n7", 1000);

  Node* n8 = new Node(roman_punic_war, germania, "n8", 100);
  Node* n9 = new Node(roman_punic_war, germania, "n9", 100);
  Node* n15 = new Node(roman_punic_war, germania, "n15", 100);

  Node* n10 = new Node(roman_punic_war, greece, "n10", 100);
  Node* n11 = new Node(roman_punic_war, greece, "n11", 100);
  Node* n12 = new Node(roman_punic_war, greece, "n12", 100);
  Node* n13 = new Node(roman_punic_war, greece, "n13", 100);
  Node* n14 = new Node(roman_punic_war, greece, "n14", 100);
  Node* n16 = new Node(roman_punic_war, greece, "n16", 100);

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

  return roman_punic_war;
}

int main()
{
  War* war = romanPunicWars();

  int turn = 0;

  while (!war->isFinished()) {

    //Fancy things

    cout << "===========================" << "turn: " << turn++ << "===========================" << endl;

    war->nextTurn();


  }
}
