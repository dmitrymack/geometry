#include "circle.h"
#include "polygon.h"
#include "triangle.h"
#include <graphics.h>

void print_circle(int* arr_cir_x, int* arr_cir_y, int* arr_cir_rad, int cir_n)
{
    int gd = 9, gm = 3;
    initgraph(&gd, &gm, NULL);
    for (int i = 0; i < cir_n; i++) {
        circle(arr_cir_x[i], arr_cir_y[i], arr_cir_rad[i]);
    }
}

void print_triangle(int* arr_tri_x, int* arr_tri_y, int tri_n)
{
    for (int i = 0; i < tri_n * 3; i += 3) {
        line(arr_tri_x[i], arr_tri_y[i], arr_tri_x[i + 1], arr_tri_y[i + 1]);
        line(arr_tri_x[i + 1],
             arr_tri_y[i + 1],
             arr_tri_x[i + 2],
             arr_tri_y[i + 2]);
        line(arr_tri_x[i + 2], arr_tri_y[i + 2], arr_tri_x[i], arr_tri_y[i]);
    }
}

void print_polygon(int** arr_pol_x, int** arr_pol_y, int* pol_v, int pol_n)
{
    for (int i = 0; i < pol_n; i++) {
        for (int j = 0; j < pol_v[i] - 1; j++) {
            line(arr_pol_x[i][j],
                 arr_pol_y[i][j],
                 arr_pol_x[i][j + 1],
                 arr_pol_y[i][j + 1]);
            if (j + 2 == pol_v[i])
                line(arr_pol_x[i][0],
                     arr_pol_y[i][0],
                     arr_pol_x[i][j + 1],
                     arr_pol_y[i][j + 1]);
        }
    }
    getch();
    closegraph();
}
