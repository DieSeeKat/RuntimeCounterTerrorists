//
// Created by Lukas Anthonissen on 2022/10/20.
//

#include "gtest/gtest.h"
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

#include "../Empire.h"
#include "../Memento/War.h"
#include "Capital.h"
#include "Node.h"
#include "Town.h"

TEST(Graph, ShortestPath_Test) {
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

  std::vector<Node *> expected = {n4, n7, c2};
  std::vector<Node *> path = c1->findShortestPathTo(war->getNodes(), c2);
  ASSERT_EQ(expected, path);
}

TEST(Graph, ConnectedToCapital_TEST) {
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

  EXPECT_TRUE(!(n7->connectedToCapital(war->getNodes(), c1)));
  EXPECT_TRUE(n6->connectedToCapital(war->getNodes(), c1));
  EXPECT_TRUE(!(n5->connectedToCapital(war->getNodes(), c2)));
}

TEST(Graph, Repopulate_TEST) {
  War *war = new War();

  Empire *e1 = new Empire("Rome");

  war->addEmpire(e1);

  Node *node = new Node(e1, "node", 4, true);

  int population = node->getPopulation();

  node->repopulate();

  ASSERT_TRUE(node->getPopulation() != population);
}

TEST(Graph, Recharge_TEST) {
  War *war = new War();

  Empire *e1 = new Empire("Rome");

  war->addEmpire(e1);

  Node *node = new Node(e1, "node", 4, true);

  node->setResources(1);

  int resources = node->getResources();

  node->rechargeResources();

  ASSERT_TRUE(node->getResources() != resources);

  resources = node->getResources();

  node->rechargeResources();

  ASSERT_TRUE(node->getResources() == resources);
}