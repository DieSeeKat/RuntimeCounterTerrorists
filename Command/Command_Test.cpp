//
// Created by Daniel van Zyl on 10/24/2022.
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
#include "Communication.h"
#include "AcceptAlliance.h"
#include "RequestAlliance.h"

TEST(Command, Alliance_of_two)
{
    Empire *e1 = new Empire("Rome");
    Empire *e2 = new Empire("Greece");

    e1->requestAlliance(e2);

    ASSERT_EQ(e1->getAlliances().at(0), e2);
    ASSERT_EQ(e2->getAlliances().at(0), e1);
}

TEST(Command, Alliance_of_three)
{
    Empire *e1 = new Empire("Rome");
    Empire *e2 = new Empire("Greece");
    Empire *e3 = new Empire("England");

    e1->requestAlliance(e2);
    e2->requestAlliance(e3);

    ASSERT_EQ(e1->getAlliances().at(0), e2);
//    ASSERT_EQ(e1->getAlliances().at(1), e3);
}