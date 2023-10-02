#include <stdio.h>
#define N 10
int main()
{
    int n;
    scanf("%d", &n);
    float arr[N][N + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                float ratio = arr[j][i] / arr[i][i];

                for (int k = 0; k < n + 1; k++)
                {
                    arr[j][k] -= (ratio * arr[i][k]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
    float value[N];
    for (int i = 0; i < n; i++)
    {
        value[i] = arr[i][n] / arr[i][i];
        printf("%.2f ", value[i]);
    }
}