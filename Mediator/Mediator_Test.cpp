//
// Created by Daniel on 10/28/2022.
//

#include "gtest/gtest.h"
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
#include "Mediator.h"
#include "ConcreteMediator.h"

TEST(Mediator, NotifyAttack)
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
    Node *n9 = new Node(war, e2, "n9", 4);
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
    n9->addPathTo(n8);

    war->addNode(c1);
    war->addNode(n2);
    war->addNode(n3);
    war->addNode(n4);
    war->addNode(n5);
    war->addNode(n6);
    war->addNode(n7);
    war->addNode(n8);
    war->addNode(c2);
    war->addNode(n9);

    Army *attacking_army = new Army(war, c1, e1);
    e1->addArmy(attacking_army);
    attacking_army->addUnit(Unit());
    attacking_army->addUnit(Unit());

    Army *defending_army = new Army(war, n8, e2);
    e2->addArmy(defending_army);
    defending_army->addUnit(Unit());

    ASSERT_EQ(n8->getStationedArmies().size(), 1);
    ASSERT_EQ(n5->getStationedArmies().size(), 0);
    attacking_army->attackTown(n8);

    ASSERT_EQ(n8->getStationedArmies().size(), 0);
    ASSERT_EQ(n5->getStationedArmies().size(), 1);
    ASSERT_EQ(n9->getStationedArmies().size(), 1);
    ASSERT_EQ(e2->getArmies().size(), 2);

}


