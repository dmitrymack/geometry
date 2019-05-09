#include "gtest/gtest.h"
#include <math.h>

double P, S;
const int poly1 = 3;
const int poly2 = 4;
const int poly3 = 5;

int tri_x1[3] = {0, 3, 0}, tri_y1[3] = {0, 0, 4};
int tri_x2[3] = {0, 5, 0}, tri_y2[3] = {0, 0, 12};
int tri_x3[3] = {0, 8, 0}, tri_y3[3] = {0, 0, 6};

int pol_x1[poly1] = {0, 15, 0}, pol_y1[poly1] = {0, 0, 20};
int pol_x2[poly2] = {0, 3, 3, 0}, pol_y2[poly2] = {0, 0, 3, 3};
int pol_x3[poly3] = {1, 10, 3, 5, 4}, pol_y3[poly3] = {7, 0, 2, 3, 1};

void circle_calculations(int rad)
{
    P = 0, S = 0;
    double Pi = 3.14;
    P = 2 * Pi * rad;
    S = Pi * rad * rad;
}

void triangle_calculations(int* tri_x, int* tri_y)
{
    P = 0, S = 0;
    int x[3], y[3];
    double a, b, c;

    x[0] = tri_x[1] - tri_x[0];
    y[0] = tri_y[1] - tri_y[0];
    x[1] = tri_x[1] - tri_x[2];
    y[1] = tri_y[2] - tri_y[1];
    x[2] = tri_x[0] - tri_x[2];
    y[2] = tri_y[2] - tri_y[0];
    a = sqrt(x[0] * x[0] + y[0] * y[0]);
    b = sqrt(x[1] * x[1] + y[1] * y[1]);
    c = sqrt(x[2] * x[2] + y[2] * y[2]);
    P = a + b + c;
    S = sqrt(P / 2 * (P / 2 - a) * (P / 2 - b) * (P / 2 - c));
}

void polygon_calculations(int* pol_x, int* pol_y, int poly)
{
    P = 0;
    S = 0;
    int x[poly], y[poly];
    double t[poly], l[poly], r[poly], Sl, Sr;

    Sl = 0;
    Sr = 0;

    for (int j = 0; j < poly - 1; j++) {
        x[j] = pol_x[j + 1] - pol_x[j];
        if (j + 2 == poly)
            x[j + 1] = pol_x[0] - pol_x[j + 1];
        y[j] = pol_y[j + 1] - pol_y[j];
        if (j + 2 == poly)
            y[j + 1] = pol_y[0] - pol_y[j + 1];
    }
    for (int j = 0; j < poly; j++) {
        t[j] = sqrt(x[j] * x[j] + y[j] * y[j]);
        P += t[j];
    }

    for (int j = 0; j < poly - 1; j++) {
        l[j] = pol_x[j] * pol_y[j + 1];
        r[j] = pol_x[j + 1] * pol_y[j];
        if (j + 2 == poly) {
            Sl += pol_x[poly - 1] * pol_y[0];
            Sr += pol_x[0] * pol_y[poly - 1];
        }
        Sl += abs(l[j]);
        Sr += abs(r[j]);
    }
    S = abs(Sl - Sr) / 2;
}

TEST(Circle, Per_1)
{
    circle_calculations(1);
    EXPECT_EQ(6.28, P);
}

TEST(Circle, Area_1)
{
    EXPECT_EQ(3.14, S);
}

TEST(Circle, Per_2)
{
    circle_calculations(9);
    EXPECT_EQ(56.52, P);
}

TEST(Circle, Area_2)
{
    EXPECT_EQ(254.34, S);
}

TEST(Circle, Per_3)
{
    circle_calculations(13);
    EXPECT_EQ(81.64, P);
}

TEST(Circle, Area_3)
{
    EXPECT_EQ(530.66, S);
}

TEST(Triangle, Per_1)
{
    triangle_calculations(tri_x1, tri_y1);
    EXPECT_EQ(12, P);
}

TEST(Triangle, Area_1)
{
    EXPECT_EQ(6, S);
}

TEST(Triangle, Per_2)
{
    triangle_calculations(tri_x2, tri_y2);
    EXPECT_EQ(30, P);
}

TEST(Triangle, Area_2)
{
    EXPECT_EQ(30, S);
}

TEST(Triangle, Per_3)
{
    triangle_calculations(tri_x3, tri_y3);
    EXPECT_EQ(24, P);
}

TEST(Triangle, Area_3)
{
    EXPECT_EQ(24, S);
}

TEST(Polygon, Per_1)
{
    polygon_calculations(pol_x1, pol_y1, poly1);
    EXPECT_EQ(60, P);
}

TEST(Polygon, Area_1)
{
    EXPECT_EQ(150, S);
}

TEST(Polygon, Per_2)
{
    polygon_calculations(pol_x2, pol_y2, poly2);
    EXPECT_EQ(12, P);
}

TEST(Polygon, Area_2)
{
    EXPECT_EQ(9, S);
}

TEST(Polygon, Per_3)
{
    polygon_calculations(pol_x3, pol_y3, poly3);
    EXPECT_EQ(29.8622, P);
}

TEST(Polygon, Area_3)
{
    EXPECT_EQ(15.5, S);
}