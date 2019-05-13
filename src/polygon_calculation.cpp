#include "polygon.h"
#include <math.h>
#include <stdio.h>

void polygon_calculations(
        int** arr_pol_x, int** arr_pol_y, int* pol_v, int pol_n)
{
    int x[pol_n * 20], y[pol_n * 20];
    double S, P, t[20], l[20], r[20], Sl, Sr;
    for (int i = 0; i < pol_n; i++) {
        P = 0;
        S = 0;
        Sl = 0;
        Sr = 0;
        for (int j = 0; j < pol_v[i] - 1; j++) {
            x[j] = arr_pol_x[i][j + 1] - arr_pol_x[i][j];
            if (j + 2 == pol_v[i])
                x[j + 1] = arr_pol_x[i][0] - arr_pol_x[i][j + 1];
            y[j] = arr_pol_y[i][j + 1] - arr_pol_y[i][j];
            if (j + 2 == pol_v[i])
                y[j + 1] = arr_pol_y[i][0] - arr_pol_y[i][j + 1];
        }
        for (int j = 0; j < pol_v[i]; j++) {
            t[j] = sqrt(x[j] * x[j] + y[j] * y[j]);
            P += t[j];
        }
        printf("\nPerimeter of polygon #%d = %.2f\n", i + 1, P);

        for (int j = 0; j < pol_v[i] - 1; j++) {
            l[j] = arr_pol_x[i][j] * arr_pol_y[i][j + 1];
            r[j] = arr_pol_x[i][j + 1] * arr_pol_y[i][j];
            if (j + 2 == pol_v[i]) {
                Sl += arr_pol_x[i][pol_v[i] - 1] * arr_pol_y[i][0];
                Sr += arr_pol_x[i][0] * arr_pol_y[i][pol_v[i] - 1];
            }
            if (l[j] < 0)
                l[j] = -l[j];
            if (r[j] < 0)
                r[j] = -r[j];
            Sl += l[j];
            Sr += r[j];
        }
        S = (Sl - Sr) / 2;
        printf("Area of polygon #%d = %.2f\n", i + 1, S);
    }
}