#include "circle.h"
#include <stdio.h>

void circle_calculations(int* arr_cir_rad, int cir_n)
{
    double Pi = 3.1415926535, P, S;
    for (int i = 0; i < cir_n; i++) {
        P = 2 * Pi * arr_cir_rad[i];
        S = Pi * arr_cir_rad[i] * arr_cir_rad[i];
        printf("\nPerimeter of circle #%d = %.3f\n", i + 1, P);
        printf("Area of circle #%d = %.3f\n", i + 1, S);
    }
    printf("\n");
}