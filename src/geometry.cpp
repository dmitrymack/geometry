#include "circle.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cir_n, *arr_cir_x, *arr_cir_y, *arr_cir_rad;
    printf("Input the number of circles -> ");
    scanf("%d", &cir_n);
    arr_cir_x = new int[cir_n];
    arr_cir_y = new int[cir_n];
    arr_cir_rad = new int[cir_n];
    for (int i = 0; i < cir_n; i++) {
        printf("Input the x, y and radius of %d circle -> ", i + 1);
        scanf("%d%d%d", &arr_cir_x[i], &arr_cir_y[i], &arr_cir_rad[i]);
    }

    delete (arr_cir_x);
    delete (arr_cir_y);
    delete (arr_cir_rad);
    return 0;
}