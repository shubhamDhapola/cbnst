#include <stdio.h>
#include <math.h>
#define e 2.71

// f(x) = x3+3x+1
float f(float x)
{
    float ans = cos(x) - x * pow(e, x);
    return ans;
}
float fdash(float x)
{
    float ans = -sin(x) - (x * pow(e, x) + pow(e, x));
    return ans;
}
int main()
{
    float x0 = 0;
    int itr = 0;
    while (++itr)
    {
        float x1 = x0 - f(x0) / fdash(x0);
        printf("%f\n", x1);
        if (fabs(x1 - x0) < 0.0001)
            break;
        x0 = x1;
    }
    printf("no. of iterations are %d ", itr);
}