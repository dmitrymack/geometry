#include "circle.h"
#include <graphics.h>

void print_circle(int* arr_cir_x, int* arr_cir_y, int* arr_cir_rad, int cir_n)
{
    int gd = 9, gm = 3;
    initgraph(&gd, &gm, NULL);
    for (int i = 0; i < cir_n; i++) {
        circle(arr_cir_x[i], arr_cir_y[i], arr_cir_rad[i]);
    }

    int input = 0;

    while (input == 0) {
        input = getchar();
    }
    closegraph();
}
