
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
#include "Policies/ArcherWarfare.h"
#include "Policies/GuerillaWarfare.h"
#include "Policies/HorsemenWarfare.h"
#include "Policies/LegionaryWarfare.h"
#include "Policies/HeavyWar.h"
#include "Policies/LightWar.h"
#include "Policies/NormalWar.h"

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
    int menu_choice = 0; //Yes=0; No=1

    while(menu_choice == 0)
    {
      cout<<"----------------------------------"<<endl;
      cout << "MENU" << endl;
      cout<<"----------------------------------"<<endl;
      cout << "Press 1 to SHOW EMPIRES" << endl;
      cout << "Press 2 to ROLLBACK" << endl;
      cout << "Press 3 to END TURN" << endl;
      cout<<"---------------ENTER BELOW------------------"<<endl;

      int choice = 0;
      cin >> choice;

      while (choice != 1 && choice != 2 && choice !=3)
      {
        cout<<"----------------------------------"<<endl;
        cout << "MENU" << endl;
        cout<<"----------------------------------"<<endl;
        cout << "Press 1 to SHOW EMPIRES" << endl;
        cout << "Press 2 to ROLLBACK" << endl;
        cout << "Press 3 to END TURN" << endl;
        cout<<"---------------ENTER BELOW------------------"<<endl;
        cin >> choice;
      }

      if (choice == 1)
      {
        cout<<"----------------------------------"<<endl;
        cout << "CHOOSE EMPIRE" << endl;
        cout<<"----------------------------------"<<endl;
        for (int i = 0; i < empire1.size(); ++i)
        {
          cout<<"Press "<<i+1<<" for "<<empire1[i]->getName()<<endl;
        }
        cout<<"---------------ENTER BELOW-----------------------"<<endl;

        int empire_choice = 0;
        cin >> empire_choice;

        while (empire_choice != 1 && empire_choice != 2)
        {
          cout<<"----------------------------------"<<endl;
          cout << "CHOOSE EMPIRE" << endl;
          cout<<"----------------------------------"<<endl;
          for (int i = 0; i < empire1.size(); ++i)
          {
            cout<<"Press "<<i+1<<" for "<<empire1[i]->getName()<<endl;
          }
          cout<<"---------------ENTER BELOW-----------------------"<<endl;
          cin >> empire_choice;
        }

        if (empire_choice == 1)
        {
          int policy_choice = 0;

          cout<<"----------------------------------"<<endl;
          cout<<"CHOOSE POLICIES TO CHANGE"<<endl;
          cout<<"----------------------------------"<<endl;
          cout<<"Press 1: Current Recruitment Policy is "<<empire1[0]->getRecruitmentPolicy()<<endl;
          cout<<"Press 2: Current War-style Policy is "<<empire1[0]->getWarStylePolicy()<<endl;
          cout<<"Press 3: DO NOT CHANGE POLICY (GO BACK)"<<endl;
          cout<<"---------------ENTER BELOW-----------------------"<<endl;
          cin>>policy_choice;

          while( policy_choice != 1 && policy_choice != 2 && policy_choice != 3)
          {

            cout<<"----------------------------------"<<endl;
            cout<<"CHOOSE POLICIES TO CHANGE"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"Press 1: Current Recruitment Policy is "<<empire1[0]->getRecruitmentPolicy()<<endl;
            cout<<"Press 2: Current War-style Policy is "<<empire1[0]->getWarStylePolicy()<<endl;
            cout<<"Press 3: DO NOT CHANGE POLICY (GO BACK)"<<endl;
            cout<<"---------------ENTER BELOW-----------------------"<<endl;
            cin>>policy_choice;
          }

          int policyTypeChange=0;

          if(policy_choice==1){
            cout<<"----------------------------------"<<endl;
            cout<<"RECRUITMENT POLICIES TYPES"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"Press 1 for Normal war"<<endl;
            cout<<"Press 2 for Light war"<<endl;
            cout<<"Press 3 for Heavy war"<<endl;
            cout<<"---------------ENTER BELOW-----------------------"<<endl;
            cin>>policyTypeChange;

            while( policyTypeChange != 1 && policyTypeChange != 2 && policyTypeChange != 3)
            {
              cout<<"----------------------------------"<<endl;
              cout<<"RECRUITMENT POLICIES TYPES"<<endl;
              cout<<"----------------------------------"<<endl;
              cout<<"Press 1 for Normal war"<<endl;
              cout<<"Press 2 for Light war"<<endl;
              cout<<"Press 3 for Heavy war"<<endl;
              cout<<"---------------ENTER BELOW-----------------------"<<endl;
              cin>>policyTypeChange;
            }

            if(policyTypeChange==1){
              empire1[0]->setRecruitmentPolicy(new NormalWar());
            }
            else if(policyTypeChange==2){
              empire1[0]->setRecruitmentPolicy(new LightWar());
            }
            else{
              empire1[0]->setRecruitmentPolicy(new HeavyWar());
            }
            cout << "-----------------------------------------" << endl;
            cout << "RECRUITMENT POLICY HAS BEEN CHANGED TO" << endl;
            cout << empire1[0]->getRecruitmentPolicy()<< endl;
            cout << "-----------------------------------------" << endl;


          }
          else if(policy_choice==2){
            cout<<"----------------------------------"<<endl;
            cout<<"WAR-STYLE POLICIES TYPE"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"Press 1 for Archer warfare"<<endl;
            cout<<"Press 2 for Guerilla warfare"<<endl;
            cout<<"Press 3 for Horsemen warfare"<<endl;
            cout<<"Press 4 for Legionary warfare"<<endl;
            cout<<"---------------ENTER BELOW-----------------------"<<endl;
            cin>>policyTypeChange;

            while( policyTypeChange != 1 && policyTypeChange != 2 && policyTypeChange != 3 && policyTypeChange != 4)
            {
              cout<<"----------------------------------"<<endl;
              cout<<"WAR-STYLE POLICIES TYPE"<<endl;
              cout<<"----------------------------------"<<endl;
              cout<<"Press 1 for Archer warfare"<<endl;
              cout<<"Press 2 for Guerilla warfare"<<endl;
              cout<<"Press 3 for Horsemen warfare"<<endl;
              cout<<"Press 4 for Legionary warfare"<<endl;
              cout<<"---------------ENTER BELOW-----------------------"<<endl;
              cin>>policyTypeChange;
            }

            if(policyTypeChange==1){
              empire1[0]->setWarStylePolicy(new ArcherWarfare());
            }
            else if(policyTypeChange==2){
              empire1[0]->setWarStylePolicy(new GuerillaWarfare());
            }
            else if(policyTypeChange==3){
              empire1[0]->setWarStylePolicy(new HorsemenWarfare());
            }
            else{
              empire1[0]->setWarStylePolicy(new LegionaryWarfare());
            }

            cout << "-----------------------------------------" << endl;
            cout << "WAR-STYLE POLICY HAS BEEN CHANGED TO" << endl;
            cout << empire1[0]->getWarStylePolicy()<< endl;
            cout << "-----------------------------------------" << endl;


          }


        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////
        else //if empire choice = 2
        {
          int policy_choice = 0;
          cout<<"----------------------------------"<<endl;
          cout<<"CHOOSE POLICIES TO CHANGE"<<endl;
          cout<<"----------------------------------"<<endl;
          cout<<"Press 1: Current Recruitment Policy is "<<empire1[1]->getRecruitmentPolicy()<<endl;
          cout<<"Press 2: Current War-style Policy is "<<empire1[1]->getWarStylePolicy()<<endl;
          cout<<"Press 3: DO NOT CHANGE POLICY (GO BACK)"<<endl;
          cout<<"---------------ENTER BELOW-----------------------"<<endl;
          cin>>policy_choice;

          while( policy_choice != 1 && policy_choice != 2 && policy_choice != 3)
          {

            cout<<"----------------------------------"<<endl;
            cout<<"CHOOSE POLICIES TO CHANGE"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"Press 1: Current Recruitment Policy is "<<empire1[1]->getRecruitmentPolicy()<<endl;
            cout<<"Press 2: Current War-style Policy is "<<empire1[1]->getWarStylePolicy()<<endl;
            cout<<"Press 3: DO NOT CHANGE POLICY (GO BACK)"<<endl;
            cout<<"---------------ENTER BELOW-----------------------"<<endl;
            cin>>policy_choice;
          }

          int policyTypeChange=0;
          ////////////////////////////////////////////////////////////////////////////////////////////////////
          ///////////////////////////////////////////////////////////////////////////////////////////////////
          if(policy_choice==1){
            cout<<"----------------------------------"<<endl;
            cout<<"RECRUITMENT POLICIES TYPES"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"Press 1 for Normal war"<<endl;
            cout<<"Press 2 for Light war"<<endl;
            cout<<"Press 3 for Heavy war"<<endl;
            cout<<"---------------ENTER BELOW-----------------------"<<endl;
            cin>>policyTypeChange;

            while( policyTypeChange != 1 && policyTypeChange != 2 && policyTypeChange != 3)
            {
              cout<<"----------------------------------"<<endl;
              cout<<"RECRUITMENT POLICIES TYPES"<<endl;
              cout<<"----------------------------------"<<endl;
              cout<<"Press 1 for Normal war"<<endl;
              cout<<"Press 2 for Light war"<<endl;
              cout<<"Press 3 for Heavy war"<<endl;
              cout<<"---------------ENTER BELOW-----------------------"<<endl;
              cin>>policyTypeChange;
            }

            if(policyTypeChange==1){
              empire1[1]->setRecruitmentPolicy(new NormalWar());
            }
            else if(policyTypeChange==2){
              empire1[1]->setRecruitmentPolicy(new LightWar());
            }
            else{
              empire1[1]->setRecruitmentPolicy(new HeavyWar());
            }
            cout << "-----------------------------------------" << endl;
            cout << "RECRUITMENT POLICY HAS BEEN CHANGED TO" << endl;
            cout << empire1[1]->getRecruitmentPolicy()<< endl;
            cout << "-----------------------------------------" << endl;


          }
          else if(policy_choice==2){
            cout<<"----------------------------------"<<endl;
            cout<<"WAR-STYLE POLICIES TYPE"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"Press 1 for Archer warfare"<<endl;
            cout<<"Press 2 for Guerilla warfare"<<endl;
            cout<<"Press 3 for Horsemen warfare"<<endl;
            cout<<"Press 4 for Legionary warfare"<<endl;
            cout<<"---------------ENTER BELOW-----------------------"<<endl;
            cin>>policyTypeChange;

            while( policyTypeChange != 1 && policyTypeChange != 2 && policyTypeChange != 3 && policyTypeChange != 4)
            {
              cout<<"----------------------------------"<<endl;
              cout<<"WAR-STYLE POLICIES TYPE"<<endl;
              cout<<"----------------------------------"<<endl;
              cout<<"Press 1 for Archer warfare"<<endl;
              cout<<"Press 2 for Guerilla warfare"<<endl;
              cout<<"Press 3 for Horsemen warfare"<<endl;
              cout<<"Press 4 for Legionary warfare"<<endl;
              cout<<"---------------ENTER BELOW-----------------------"<<endl;
              cin>>policyTypeChange;
            }

            if(policyTypeChange==1){
              empire1[1]->setWarStylePolicy(new ArcherWarfare());
            }
            else if(policyTypeChange==2){
              empire1[1]->setWarStylePolicy(new GuerillaWarfare());
            }
            else if(policyTypeChange==3){
              empire1[1]->setWarStylePolicy(new HorsemenWarfare());
            }
            else{
              empire1[1]->setWarStylePolicy(new LegionaryWarfare());
            }

            cout << "-----------------------------------------" << endl;
            cout << "WAR-STYLE POLICY HAS BEEN CHANGED TO" << endl;
            cout << empire1[1]->getWarStylePolicy()<< endl;
            cout << "-----------------------------------------" << endl;


          }
          
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////////
      }
      else if(choice==2)
      {
        bool bRollBack = true;
        while (bRollBack)
        {
          WarRollback *rollback = war->createWarRollback();
          war->setWarRollback(rollback);
          cout << "-----------------------------------------" << endl;
          cout << "ROLLBACK has been called" << endl;
          cout << "-----------------------------------------" << endl;
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
