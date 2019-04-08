#include "circle.h"
#include <stdio.h>

void circle(int* arr_cir_x, int* arr_cir_y, int* arr_cir_rad, int cir_n)
{
    printf("\n");

    for (int i = 0; i < cir_n; i++) {
        printf("Enter x, y and radius for circle #%d -> ", i + 1);
        scanf("%d%d%d", &arr_cir_x[i], &arr_cir_y[i], &arr_cir_rad[i]);
    }
}