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

    circle(arr_cir_x, arr_cir_y, arr_cir_rad, cir_n);
    circle_calculations(arr_cir_rad, cir_n);
    delete (arr_cir_x);
    delete (arr_cir_y);
    delete (arr_cir_rad);
    return 0;
}
