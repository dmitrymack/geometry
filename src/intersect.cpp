#include "circle.h"
#include <math.h>
#include <stdio.h>

void intersect(int* arr_cir_x, int* arr_cir_y, int* arr_rad, int cir_n)
{
    int x, y, z, h, h1, k, k1, inter[cir_n][cir_n] = {0};
    for (int i = 0; i < cir_n; i++)
        for (int j = i + 1; j < cir_n; j++) {
            x = arr_cir_x[i] - arr_cir_x[j];
            if (x < 0)
                x = -x;
            y = arr_cir_y[i] - arr_cir_y[j];
            if (y < 0)
                y = -y;
            z = arr_rad[i] + arr_rad[j];
            h = arr_cir_x[i] + arr_rad[i];
            k = arr_cir_y[i] + arr_rad[i];
            h1 = arr_cir_x[j] + arr_rad[j];
            k1 = arr_cir_y[j] + arr_rad[j];
            if (x <= z && y <= z && (h < h1 || k < k1)) {
                inter[i][j] = -1;
                inter[j][i] = -1;
                // printf("Circle #%d intersects with Circle #%d", i + 1, j +
                // 1);
            }
        }
    for (int i = 0; i < cir_n; i++) {
        printf("Circle #%d intersects: ", i + 1);
        for (int j = 0; j < cir_n; j++)
            if (inter[i][j] == -1)
                printf("Circle #%d", j + 1);
        printf("\n");
    }
}