#include "circle.h"
#include "polygon.h"
#include "triangle.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cir_n, *arr_cir_x, *arr_cir_y, *arr_cir_rad;
    int *arr_tri_x, *arr_tri_y, tri_n;
    int **arr_pol_x, **arr_pol_y, pol_n, *pol_v;

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
    triangle_calculations(arr_tri_x, arr_tri_y, tri_n);

    printf("Input quanity of polygons -> ");
    scanf("%d", &pol_n);
    printf("\n");
    pol_v = new int[pol_n * 20];
    arr_pol_x = new int*[pol_n * 20];
    arr_pol_y = new int*[pol_n * 20];
    for (int i = 0; i < pol_n; i++) {
        printf("Enter quanity of vertices for polygon #%d: ", i + 1);
        scanf("%d", &pol_v[i]);
        arr_pol_x[i] = new int[pol_v[i]];
        arr_pol_y[i] = new int[pol_v[i]];
    }
    polygon(arr_pol_x, arr_pol_y, pol_v, pol_n);

    print_circle(arr_cir_x, arr_cir_y, arr_cir_rad, cir_n);
    print_triangle(arr_tri_x, arr_tri_y, tri_n);

    delete (arr_cir_x);
    delete (arr_cir_y);
    delete (arr_cir_rad);
    delete (arr_tri_x);
    delete (arr_tri_y);
    return 0;
}
