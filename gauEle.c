#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("enter the no of variables ");
    scanf("%d", &n);
    int itr;
    printf("enter the no. of max iterations: ");
    scanf("%d", itr);
    float arr[n][n + 1];
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
            float ratio = arr[j][i] / arr[i][i];
            if (j > i)
            {
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
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
    float values[n];

    values[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];
    float sum=0;
    for (int i = n - 2; i >= 0; i--)
    {
        sum=0;
        for (int j = i + 1; j < n; j++)
        {
            sum+= values[j] * arr[i][j];
        }
        values[i] = (arr[i][n]-sum) / arr[i][i];
    }
}