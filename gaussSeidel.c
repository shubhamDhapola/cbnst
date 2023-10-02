#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int n;
int flag = 0;

float findSum(int i, float arr[][n + 1])
{
    float sum = 0;
    for (int j = 0; j < n; j++)
    {
        if (i != j)
        {
            sum = sum + fabs(arr[i][j]);
        }
    }
    return sum;
}

bool isMethodApplicable(float arr[][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fabs(arr[i][i] <= findSum(i, arr)))
                return false;
        }
    }
    return true;
}
void print(int itr, float values[n])
{
    printf("iteration %d\n", itr);
    for (int i = 0; i < n; i++)
    {
        printf("value[%d] %f\n", i + 1, values[i]);
    }
}

void findValues(float arr[][n + 1], int itr, float values_old[n])
{
    float values_new[n];
    for (int i = 0; i < n; i++)
    {
        values_new[i] = 0;
    }
    int p=0;
    while (++p)
    {
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += arr[i][j] * values_new[j];
                }
            }
            values_new[i] = (arr[i][n] - sum) / arr[i][i];
        }

        // checking
        for (int i = 0; i < n; i++)
        {
            if (fabs(values_new[i] - values_old[i] > 0.001))
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            print(p, values_new);
            return;
        }
        flag = 0;
        print(p, values_new);
        for (int i = 0; i < n; i++)
        {
            values_old[i] = values_new[i];
        }
        print(p, values_new);
        if(p==n)
        break;
    }
}
int main()
{
    printf("enter the no. of variables ");
    scanf("%d", &n);
    float arr[n][n + 1];
    int itr;
    printf("enter the no. of iterations");
    scanf("%d", &itr);
    float val[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
    if(!isMethodApplicable(arr))
    {
        printf("gauss seidel cant be applied\n");
        return 0;
    }
    printf("gauss seidel can be applied\n");
    for (int i = 0; i < n; i++)
        val[i] = 0;
    findValues(arr, itr, val);
    return 0;
}