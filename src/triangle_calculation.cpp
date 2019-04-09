#include "triangle.h"
#include <math.h>
#include <stdio.h>

void triangle_calculations(int* arr_tri_x, int* arr_tri_y, int tri_n)
{
    int x[tri_n * 3], y[tri_n * 3], k = 0;
    double a, b, c, S, P;
    for (int i = 0; i < tri_n * 3; i += 3) {
        x[i] = arr_tri_x[i + 1] - arr_tri_x[i];
        y[i] = arr_tri_y[i + 1] - arr_tri_y[i];
        x[i + 1] = arr_tri_x[i + 1] - arr_tri_x[i + 2];
        y[i + 1] = arr_tri_y[i + 2] - arr_tri_y[i + 1];
        x[i + 2] = arr_tri_x[i] - arr_tri_x[i + 2];
        y[i + 2] = arr_tri_y[i + 2] - arr_tri_y[i];
        a = sqrt(x[i] * x[i] + y[i] * y[i]);
        b = sqrt(x[i + 1] * x[i + 1] + y[i + 1] * y[+1]);
        c = sqrt(x[i + 2] * x[i + 2] + y[i + 2] * y[i + 2]);
        P = a + b + c;
        S = sqrt(P / 2 * (P / 2 - a) * (P / 2 - b) * (P / 2 - c));
        k += 1;
        printf("\nPerimeter of triangle #%d = %.2f", k, P);
        printf("\nArea of triangle #%d = %.2f\n", k, S);
    }
}