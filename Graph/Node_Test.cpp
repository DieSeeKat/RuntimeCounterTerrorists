//
// Created by Lukas Anthonissen on 2022/10/18.
//

#include "gtest/gtest.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
#include <climits>


class Empire
{
  public:
  Empire(){};
};

class Node;

class Path
{
  public:
  Node **end_points;
  Path(Node *n1, Node *n2)
  {
    end_points    = new Node *[2];
    end_points[0] = n1;
    end_points[1] = n2;
  };
  Node *getOppositeEnd(Node *node)
  {
    if (end_points[0] == node)
    {
      return end_points[1];
    }
    else
    {
      return end_points[0];
    }
  };
};


class Node
{
  public:
  Node(Empire *empire, int num)
  {
    owner_empire = empire;
    this->num    = num;
  }
  int dist;
  int num;
  Node *prev;
  Empire *owner_empire;
  Empire *getOwnerEmpire()
  {
    return owner_empire;
  };
  std::vector<Path *> paths;

  void showdq(std::deque<Node *> g)
  {
    std::deque<Node *>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
      std::cout << '\t' << (*it)->num;
    std::cout << '\n';
  }

  std::vector<Node *> findShortestPathTo(std::vector<Node *> nodes, Node *end_node)
  {
    std::deque<Node *> to_be_checked;

    for (auto node : nodes)
    {
      node->dist = INT_MAX;
      node->prev = nullptr;
    }
    this->dist = 0;
    to_be_checked.push_back(this);

    while (!to_be_checked.empty())
    {

      Node *curr = to_be_checked.front();
      to_be_checked.pop_front();
      for (auto path : curr->paths)
      {
        int newDist = curr->dist + 1;
        if (newDist < path->getOppositeEnd(curr)->dist)
        {
          path->getOppositeEnd(curr)->dist = newDist;
          path->getOppositeEnd(curr)->prev = curr;
          if (std::find(to_be_checked.begin(), to_be_checked.end(), path->getOppositeEnd(curr)) == to_be_checked.end())
          {
            to_be_checked.push_back(path->getOppositeEnd(curr));
          }
        }
      }
    }

    std::vector<Node *> return_vector;
    Node *curr_node = end_node;
    while (curr_node != this && curr_node != nullptr)
    {
      return_vector.push_back(curr_node);
      curr_node = curr_node->prev;
    }

    std::reverse(return_vector.begin(), return_vector.end());

    return return_vector;
  };
  bool connectedToCapital(std::vector<Node *> nodes, Node *capital)
  {
    std::deque<Node *> to_be_checked;

    for (auto node : nodes)
    {
      node->dist = INT_MAX;
      node->prev = nullptr;
    }
    this->dist = 0;
    to_be_checked.push_back(this);

    while (!to_be_checked.empty())
    {

      Node *curr = to_be_checked.front();
      to_be_checked.pop_front();
      for (auto path : curr->paths)
      {
        int newDist = curr->dist + 1;
        if (newDist < path->getOppositeEnd(curr)->dist && path->getOppositeEnd(curr)->getOwnerEmpire() == owner_empire)
        {
          path->getOppositeEnd(curr)->dist = newDist;
          path->getOppositeEnd(curr)->prev = curr;
          if (std::find(to_be_checked.begin(), to_be_checked.end(), path->getOppositeEnd(curr)) == to_be_checked.end())
          {
            to_be_checked.push_back(path->getOppositeEnd(curr));
          }
        }
      }
    }

    return capital->prev != nullptr;
  };
};

TEST(NodeTest, PathFindingTest)
{
  Empire *e1                = new Empire();
  Empire *e2                = new Empire();
  Node *c1                  = new Node(e1, 1);
  Node *n2                  = new Node(e1, 2);
  Node *n3                  = new Node(e1, 3);
  Node *n4                  = new Node(e2, 4);
  Node *n5                  = new Node(e2, 5);
  Node *n6                  = new Node(e1, 6);
  Node *n7                  = new Node(e1, 7);
  Node *n8                  = new Node(e2, 8);
  Node *c2                  = new Node(e2, 9);
  std::vector<Node *> nodes = {c1, n2, n3, n4, n5, n6, n7, n8, c2};

  Path *p1  = new Path(c1, n2);
  Path *p2  = new Path(c1, n3);
  Path *p3  = new Path(c1, n4);
  Path *p4  = new Path(n2, n5);
  Path *p5  = new Path(n3, n5);
  Path *p6  = new Path(n3, n6);
  Path *p7  = new Path(n4, n5);
  Path *p8  = new Path(n4, n7);
  Path *p9  = new Path(n5, n7);
  Path *p10 = new Path(n5, n8);
  Path *p11 = new Path(n6, n8);
  Path *p12 = new Path(n7, n8);
  Path *p13 = new Path(n7, c2);

  c1->paths.push_back(p1);
  n2->paths.push_back(p1);
  c1->paths.push_back(p2);
  n3->paths.push_back(p2);
  n2->paths.push_back(p4);
  n5->paths.push_back(p4);
  n3->paths.push_back(p5);
  n5->paths.push_back(p5);
  n3->paths.push_back(p6);
  n6->paths.push_back(p6);
  n4->paths.push_back(p7);
  n5->paths.push_back(p7);
  n4->paths.push_back(p8);
  n7->paths.push_back(p8);
  n5->paths.push_back(p9);
  n7->paths.push_back(p9);
  n5->paths.push_back(p10);
  n8->paths.push_back(p10);
  n6->paths.push_back(p11);
  n8->paths.push_back(p11);
  n7->paths.push_back(p12);
  n8->paths.push_back(p12);
  n7->paths.push_back(p13);
  c2->paths.push_back(p13);


  std::vector<Node *> expected = {n2, n5, n7, c2};
  std::vector<Node *> path     = c1->findShortestPathTo(nodes, c2);
  ASSERT_EQ(expected, path);

  c1->paths.push_back(p3);
  n4->paths.push_back(p3);

  path     = c1->findShortestPathTo(nodes, c2);
  expected = {n4, n7, c2};
  ASSERT_EQ(expected, path);
}

TEST(NodeTest, connectionTest)
{
  Empire *e1                = new Empire();
  Empire *e2                = new Empire();
  Node *c1                  = new Node(e1, 1);
  Node *n2                  = new Node(e1, 2);
  Node *n3                  = new Node(e1, 3);
  Node *n4                  = new Node(e2, 4);
  Node *n5                  = new Node(e2, 5);
  Node *n6                  = new Node(e1, 6);
  Node *n7                  = new Node(e1, 7);
  Node *n8                  = new Node(e2, 8);
  Node *c2                  = new Node(e2, 9);
  std::vector<Node *> nodes = {c1, n2, n3, n4, n5, n6, n7, n8, c2};

  Path *p1  = new Path(c1, n2);
  Path *p2  = new Path(c1, n3);
  Path *p3  = new Path(c1, n4);
  Path *p4  = new Path(n2, n5);
  Path *p5  = new Path(n3, n5);
  Path *p6  = new Path(n3, n6);
  Path *p7  = new Path(n4, n5);
  Path *p8  = new Path(n4, n7);
  Path *p9  = new Path(n5, n7);
  Path *p10 = new Path(n5, n8);
  Path *p11 = new Path(n6, n8);
  Path *p12 = new Path(n7, n8);
  Path *p13 = new Path(n7, c2);

  c1->paths.push_back(p1);
  n2->paths.push_back(p1);
  c1->paths.push_back(p2);
  n3->paths.push_back(p2);
  c1->paths.push_back(p3);
  n4->paths.push_back(p3);
  n2->paths.push_back(p4);
  n5->paths.push_back(p4);
  n3->paths.push_back(p5);
  n5->paths.push_back(p5);
  n3->paths.push_back(p6);
  n6->paths.push_back(p6);
  n4->paths.push_back(p7);
  n5->paths.push_back(p7);
  n4->paths.push_back(p8);
  n7->paths.push_back(p8);
  n5->paths.push_back(p9);
  n7->paths.push_back(p9);
  n5->paths.push_back(p10);
  n8->paths.push_back(p10);
  n6->paths.push_back(p11);
  n8->paths.push_back(p11);
  n7->paths.push_back(p12);
  n8->paths.push_back(p12);
  n7->paths.push_back(p13);
  c2->paths.push_back(p13);

  EXPECT_TRUE(!(n7->connectedToCapital(nodes, c1)));
  EXPECT_TRUE(n6->connectedToCapital(nodes, c1));
  EXPECT_TRUE(!(n5->connectedToCapital(nodes, c2)));
}