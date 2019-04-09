#include "circle.h"
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
    int input = 0;

    while (input == 0) {
        input = getchar();
    }
    closegraph();
}
