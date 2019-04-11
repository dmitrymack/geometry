#include "polygon.h"
#include <stdio.h>

void polygon(int** arr_pol_x, int** arr_pol_y, int* pol_v, int pol_n)
{
    printf("\n");
    for (int i = 0; i < pol_n; i++) {
        printf("Input %d vertices of the form x y for polygon #%d -> ",
               pol_v[i],
               i + 1);
        for (int j = 0; j < pol_v[i]; j++) {
            scanf("%d%d", &arr_pol_x[i][j], &arr_pol_y[i][j]);
        }
    }
}