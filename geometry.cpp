#include <stdio.h>
#include <stdlib.h>

void Circle(int x, int y, int z)
{
    printf("circle (%d, %d, %d)\n", x, y, z);
}

int main()
{
    int n, *arr_x, *arr_y, *arr_rad;
    printf("Input the number of circles -> ");
    scanf("%d", &n);
    arr_x = (int*)malloc(n * sizeof(int));
    arr_y = (int*)malloc(n * sizeof(int));
    arr_rad = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Input the x, y and radius of %d circle -> ", i + 1);
        scanf("%d%d%d", &arr_x[i], &arr_y[i], &arr_rad[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d. ", i + 1);
        Circle(arr_x[i], arr_y[i], arr_rad[i]);
    }

    free(arr_x);
    free(arr_y);
    free(arr_rad);
    return 0;
}
