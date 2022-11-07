
#include <iostream>
#include <vector>

#include "Army.h"
#include "Empire.h"
#include "Graph/Capital.h"
#include "Graph/Node.h"
#include "Graph/NodeType.h"
#include "Graph/Town.h"
#include "Memento/War.h"
#include "Memento/WarCaretaker.h"
#include "Memento/WarRollback.h"
#include "Policies/ArcherWarfare.h"
#include "Policies/GuerillaWarfare.h"
#include "Policies/HeavyWar.h"
#include "Policies/HorsemenWarfare.h"
#include "Policies/LegionaryWarfare.h"
#include "Policies/LightWar.h"
#include "Policies/NormalWar.h"
#include <algorithm>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

War *romanPunicWars()
{
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

  Node* n1 = new Node(roman_punic_war, rome, "n1", 5000);
  Node* n2 = new Node(roman_punic_war, rome, "n2", 5000);
  Node* n3 = new Node(roman_punic_war, rome, "n3", 5000);
  Node* n4 = new Node(roman_punic_war, rome, "n4", 5000);
  Node* n5 = new Node(roman_punic_war, rome, "n5", 5000);
  Node* n6 = new Node(roman_punic_war, rome, "n6", 5000);
  Node* n7 = new Node(roman_punic_war, rome, "n7", 5000);

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

void setFontColor(int r, int g, int b){
  cout << "\033[38;2;" << r << ";" << g << ";" << b << "m";
}

void setYellow(){
  setFontColor(220, 220, 0);
}

void setWhite() {
  setFontColor(255, 255, 255);
}

void setGreen() {
  setFontColor(0, 255, 0);
}

void setRed() {
  setFontColor(255, 0, 1);
}

void setBlue() {
  setFontColor(0, 0, 255);
}

int main()
{
  War *war = romanPunicWars();
  setYellow();
  cout << "______                             ______            _        _    _                " << endl <<
          "| ___ \\                            | ___ \\          (_)      | |  | |               " << endl <<
          "| |_/ /___  _ __ ___   __ _ _ __   | |_/ /   _ _ __  _  ___  | |  | | __ _ _ __ ___ " << endl <<
          "|    // _ \\| '_ ` _ \\ / _` | '_ \\  |  __/ | | | '_ \\| |/ __| | |/\\| |/ _` | '__/ __|" << endl <<
          "| |\\ \\ (_) | | | | | | (_| | | | | | |  | |_| | | | | | (__  \\  /\\  / (_| | |  \\__ \\" << endl <<
          "\\_| \\_\\___/|_| |_| |_|\\__,_|_| |_| \\_|   \\__,_|_| |_|_|\\___|  \\/  \\/ \\__,_|_|  |___/" << endl;


  cout << "---------------------------WAR HAS BEGUN-----------------------------" << endl;
  while (!war->isFinished())
  {
    vector<Empire *> empire1 = war->getEmpires();
    int menu_choice          = 0;//Yes=0; No=1

    while (menu_choice == 0)
    {
      cout << "----------------------------------" << endl;
      cout << "MENU" << endl;
      cout << "----------------------------------" << endl;
      setBlue();
      cout << "Press 1 to SHOW EMPIRES" << endl;
      cout << "Press 2 to ROLLBACK" << endl;
      setRed();
      cout << "Press 3 to END TURN" << endl;
      setYellow();
      cout << "---------------ENTER BELOW------------------" << endl;

      int choice = 0;
      setWhite();
      cin >> choice;
      setYellow();

      while (choice != 1 && choice != 2 && choice != 3)
      {
        cout << "----------------------------------" << endl;
        cout << "MENU" << endl;
        cout << "----------------------------------" << endl;
        setBlue();
        cout << "Press 1 to SHOW EMPIRES" << endl;
        cout << "Press 2 to ROLLBACK" << endl;
        setRed();
        cout << "Press 3 to END TURN" << endl;
        setYellow();
        cout << "---------------ENTER BELOW------------------" << endl;
        setWhite();
        cin >> choice;
        setYellow();
      }

      if (choice == 1)
      {
        cout << "----------------------------------" << endl;
        cout << "CHOOSE EMPIRE" << endl;
        cout << "----------------------------------" << endl;
        setBlue();
        for (int i = 0; i < empire1.size(); ++i)
        {
          cout << "Press " << i + 1 << " for " << empire1[i]->getName() << endl;
        }
        setYellow();
        cout << "---------------ENTER BELOW-----------------------" << endl;

        int empire_choice = 0;
        setWhite();
        cin >> empire_choice;
        setYellow();

        while (empire_choice > empire1.size() || empire_choice <= 0)
        {
          cout << "----------------------------------" << endl;
          cout << "CHOOSE EMPIRE" << endl;
          cout << "----------------------------------" << endl;
          setBlue();
          for (int i = 0; i < empire1.size(); ++i)
          {
            cout << "Press " << i + 1 << " for " << empire1[i]->getName() << endl;
          }
          setYellow();
          cout << "---------------ENTER BELOW-----------------------" << endl;
          setWhite();
          cin >> empire_choice;
          setYellow();
        }
        for (int i = 0; i < empire1.size(); i++)
        {
          if (empire_choice == i + 1)
          {
            int policy_choice = 0;

            cout << "----------------------------------" << endl;
            cout << "CHOOSE POLICIES TO CHANGE" << endl;
            cout << "----------------------------------" << endl;
            setBlue();
            cout << "Press 1: Current Recruitment Policy is " << empire1[i]->getRecruitmentPolicy() << endl;
            cout << "Press 2: Current War-style Policy is " << empire1[i]->getWarStylePolicy() << endl;
            setRed();
            cout << "Press 3: DO NOT CHANGE POLICY (GO BACK)" << endl;
            setYellow();
            cout << "---------------ENTER BELOW-----------------------" << endl;
            setWhite();
            cin >> policy_choice;
            setYellow();

            while (policy_choice != 1 && policy_choice != 2 && policy_choice != 3)
            {

              cout << "----------------------------------" << endl;
              cout << "CHOOSE POLICIES TO CHANGE" << endl;
              cout << "----------------------------------" << endl;
              setBlue();
              cout << "Press 1: Current Recruitment Policy is " << empire1[i]->getRecruitmentPolicy() << endl;
              cout << "Press 2: Current War-style Policy is " << empire1[i]->getWarStylePolicy() << endl;
              setRed();
              cout << "Press 3: DO NOT CHANGE POLICY (GO BACK)" << endl;
              setYellow();
              cout << "---------------ENTER BELOW-----------------------" << endl;
              setWhite();
              cin >> policy_choice;
              setYellow();
            }


            int policyTypeChange = 0;

            if (policy_choice == 1)
            {
              cout << "----------------------------------" << endl;
              cout << "RECRUITMENT POLICIES TYPES" << endl;
              cout << "----------------------------------" << endl;
              setBlue();
              cout << "Press 1 for Normal war" << endl;
              cout << "Press 2 for Light war" << endl;
              cout << "Press 3 for Heavy war" << endl;
              setYellow();
              cout << "---------------ENTER BELOW-----------------------" << endl;
              setWhite();
              cin >> policyTypeChange;
              setYellow();

              while (policyTypeChange != 1 && policyTypeChange != 2 && policyTypeChange != 3)
              {
                cout << "----------------------------------" << endl;
                cout << "RECRUITMENT POLICIES TYPES" << endl;
                cout << "----------------------------------" << endl;
                setBlue();
                cout << "Press 1 for Normal war" << endl;
                cout << "Press 2 for Light war" << endl;
                cout << "Press 3 for Heavy war" << endl;
                setYellow();
                cout << "---------------ENTER BELOW-----------------------" << endl;
                setWhite();
                cin >> policyTypeChange;
                setYellow();
              }

              if (policyTypeChange == 1)
              {
                empire1[i]->setRecruitmentPolicy(new NormalWar());
              }
              else if (policyTypeChange == 2)
              {
                empire1[i]->setRecruitmentPolicy(new LightWar());
              }
              else
              {
                empire1[i]->setRecruitmentPolicy(new HeavyWar());
              }
              cout << "-----------------------------------------" << endl;
              cout << "RECRUITMENT POLICY HAS BEEN CHANGED TO" << endl;
              cout << empire1[i]->getRecruitmentPolicy() << endl;
              cout << "-----------------------------------------" << endl;
            }
            else if (policy_choice == 2)
            {
              cout << "----------------------------------" << endl;
              cout << "WAR-STYLE POLICIES TYPE" << endl;
              cout << "----------------------------------" << endl;
              setBlue();
              cout << "Press 1 for Archer warfare" << endl;
              cout << "Press 2 for Guerilla warfare" << endl;
              cout << "Press 3 for Horsemen warfare" << endl;
              cout << "Press 4 for Legionary warfare" << endl;
              setYellow();
              cout << "---------------ENTER BELOW-----------------------" << endl;
              setWhite();
              cin >> policyTypeChange;
              setYellow();

              while (policyTypeChange != 1 && policyTypeChange != 2 && policyTypeChange != 3 && policyTypeChange != 4)
              {
                cout << "----------------------------------" << endl;
                cout << "WAR-STYLE POLICIES TYPE" << endl;
                cout << "----------------------------------" << endl;
                setBlue();
                cout << "Press 1 for Archer warfare" << endl;
                cout << "Press 2 for Guerilla warfare" << endl;
                cout << "Press 3 for Horsemen warfare" << endl;
                cout << "Press 4 for Legionary warfare" << endl;
                setYellow();
                cout << "---------------ENTER BELOW-----------------------" << endl;
                setWhite();
                cin >> policyTypeChange;
                setYellow();
              }

              if (policyTypeChange == 1)
              {
                empire1[i]->setWarStylePolicy(new ArcherWarfare());
              }
              else if (policyTypeChange == 2)
              {
                empire1[i]->setWarStylePolicy(new GuerillaWarfare());
              }
              else if (policyTypeChange == 3)
              {
                empire1[i]->setWarStylePolicy(new HorsemenWarfare());
              }
              else
              {
                empire1[i]->setWarStylePolicy(new LegionaryWarfare());
              }

              cout << "-----------------------------------------" << endl;
              cout << "WAR-STYLE POLICY HAS BEEN CHANGED TO" << endl;
              cout << empire1[i]->getWarStylePolicy() << endl;
              cout << "-----------------------------------------" << endl;
            }
          }
        }
      }
      else if (choice == 2)
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

      cout << "Go back to MENU?(0=Yes/1=No)" << endl;
      cin >> menu_choice;

      while (menu_choice != 0 && menu_choice != 1)
      {
        cout << "Go back to MENU?(0=Yes/1=No)" << endl;
        cin >> menu_choice;
      }
    }

    cout << "-----------------------------------------" << endl;
    cout << war->getNextTurn()->getName() << " is taking its turn." << endl;
    cout << "-----------------------------------------" << endl;
    setWhite();
    war->nextTurn();
    setYellow();
    cout << "---------------------------TURN HAS ENDED--------------------------" << endl;
  }

  setGreen();
  cout << "---------------------------THE WAR HAS BEEN WON BY--------------------------" << endl;
  for (auto empire : war->getEmpires()){
    cout << empire->getName() << endl;
  }
  cout << "-----------------------------------------" << endl;
  setWhite();
}
