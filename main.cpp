
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

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

War* romanPunicWars(){
  War *roman_punic_war = new War();

  Empire *e1 = new Empire("Rome");
  Empire *e2 = new Empire("Greece");
  //Empire* e3 = new Empire("Germania");

  roman_punic_war->addEmpire(e1);
  roman_punic_war->addEmpire(e2);
  //roman_punic_war->addEmpire(e3);

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

  roman_punic_war->addNode(c1);
  roman_punic_war->addNode(n2);
  roman_punic_war->addNode(n3);
  roman_punic_war->addNode(n4);
  roman_punic_war->addNode(n5);
  roman_punic_war->addNode(n6);
  roman_punic_war->addNode(n7);
  roman_punic_war->addNode(n8);
  roman_punic_war->addNode(c2);

  return roman_punic_war;
}

int main()
{
  War* war = romanPunicWars();
  cout<<"---------------------------WAR HAS BEGUN-----------------------------"<<endl;
  while (!war->isFinished()) {

    //Fancy things
    vector<Empire *> empire1 = war->getEmpires();
    int menu_choice = 0; //Yes=0

    while(menu_choice == 0)
    {


      cout << "MENU" << endl;
      cout << "Press 1 to SHOW EMPIRES" << endl;
      cout << "Press 2 to ROLLBACK" << endl;

      int choice = 0;
      cin >> choice;

      while (choice != 1 && choice != 2)
      {
        cout << "MENU" << endl;
        cout << "Press 1 to SHOW EMPIRES" << endl;
        cout << "Press 2 to ROLLBACK" << endl;
        cin >> choice;
      }

      if (choice == 1)
      {
        cout << "CHOOSE EMPIRE" << endl;
        cout << "Press 1 for " << empire1[0]->getName() << endl;
        cout << "Press 2 for " << empire1[1]->getName() << endl;

        int empire_choice = 0;
        cin >> empire_choice;

        while (empire_choice != 1 && empire_choice != 2)
        {
          cout << "CHOOSE EMPIRE" << endl;
          cout << "1: " << empire1[0]->getName() << endl;
          cout << "2: " << empire1[1]->getName() << endl;
          cin >> empire_choice;
        }

        if (empire_choice == 1)
        {
          int policy_choice = 0;

          cout<<"CHOOSE POLICIES TO CHANGE"<<endl;
          cout<<"1: Recruitment Policy = "<<endl;
          cout<<"2: War-style Policy = "<<endl;
          cout<<"3: DO NOT CHANGE POLICY (BACK)"<<endl;
          cin>>policy_choice;

          while( policy_choice != 1 && policy_choice != 2 && policy_choice != 3)
          {

            cout<<"CHOOSE POLICIES TO CHANGE"<<endl;
            cout<<"1: Recruitment Policy = "<<empire1[0]->getRecruitmentPolicy()->getRecuitmentPolicyName()<<endl;
            cout<<"2: War-style Policy = "<<empire1[0]->getWarStylePolicy()->getWarStyleName()<<endl;
            cout<<"3: DO NOT CHANGE POLICY (BACK)"<<endl;
            cin>>policy_choice;
          }


        }
        else //if empire choice = 2
        {

        }

      }
      else
      {
        bool bRollBack = true;
        while (bRollBack)
        {
          WarRollback *rollback = war->createWarRollback();
          war->setWarRollback(rollback);
          cout << "ROLLBACK has been called" << endl;
          cout << "--------------------------------" << endl;
          cout << "Continue rollback?(0=Yes/1=No)" << endl;
          int rollbackChoice = 0;
          cin >> rollbackChoice;

          while (rollbackChoice != 0 && rollbackChoice != 1)
          {
            cout << "Continue rollback?(0=Yes/1=No)" << endl;
            cin >> rollbackChoice;
          }

          if (rollbackChoice == 1)
          {
            bRollBack = false;
          }
        }
      }

      cout<<"Go back to MENU?(0=Yes/1=No)"<<endl;
      cin>>menu_choice;

      while(menu_choice != 0 && menu_choice != 1)
      {
        cout<<"Go back to MENU?(0=Yes/1=No)"<<endl;
        cin>>menu_choice;
      }

    }

    cout<<"---------------------------TURN HAS ENDED--------------------------"<<endl;






    war->nextTurn();

  }
}
