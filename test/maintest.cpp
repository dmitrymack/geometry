#include "gtest/gtest.h"

double P, S;

void circle_calculations(int rad)
{
    double Pi = 3.14;
    P = 2 * Pi * rad;
    S = Pi * rad * rad;
}

TEST(CalculationsTest, CirclePer)
{
    circle_calculations(1);
    EXPECT_EQ(6.28, P);
}

TEST(CalculationsTest, CircleArea)
{
    EXPECT_EQ(3.14, S);
}