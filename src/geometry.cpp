#include "circle.h"
#include "triangle.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cir_n, *arr_cir_x, *arr_cir_y, *arr_cir_rad;
    int *arr_tri_x, *arr_tri_y, tri_n;

    printf("Input quantity of circles -> ");
    scanf("%d", &cir_n);

    arr_cir_x = new int[cir_n];
    arr_cir_y = new int[cir_n];
    arr_cir_rad = new int[cir_n];

    circle(arr_cir_x, arr_cir_y, arr_cir_rad, cir_n);
    circle_calculations(arr_cir_rad, cir_n);

    printf("\nInput quanity of triangles -> ");
    scanf("%d", &tri_n);
    arr_tri_x = new int[tri_n * 3];
    arr_tri_y = new int[tri_n * 3];
    triangle(arr_tri_x, arr_tri_y, tri_n);

    print_circle(arr_cir_x, arr_cir_y, arr_cir_rad, cir_n);

    delete (arr_cir_x);
    delete (arr_cir_y);
    delete (arr_cir_rad);
    delete (arr_tri_x);
    delete (arr_tri_y);
    return 0;
}
