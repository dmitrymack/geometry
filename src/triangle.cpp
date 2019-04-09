#include "triangle.h"
#include <stdio.h>

void triangle(int* arr_tri_x, int* arr_tri_y, int tri_n)
{
    printf("\n");
    for (int i = 0; i < tri_n * 3; i += 3) {
        printf("Input x1 y1, x2 y2, x3 y3 for triangle #%d -> ", i / 3 + 1);
        scanf("%d%d%d%d%d%d",
              &arr_tri_x[i],
              &arr_tri_y[i],
              &arr_tri_x[i + 1],
              &arr_tri_y[i + 1],
              &arr_tri_x[i + 2],
              &arr_tri_y[i + 2]);
    }
}