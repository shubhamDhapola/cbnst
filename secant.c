#include <stdio.h>
#include <math.h>
float f(float x)
{
    // x3 – 5x + 1 = 0
    float ans = x * x * x - 5 * x + 1;
    return ans;
}

int main()
{
    int i = 0;
    float x0 = 0, x1 = 1;
    while (++i)
    {
        float x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0=x1;
        x1=x2;
        printf("x2=%f\n",x2);
        if(fabs(x1-x0)<=0.0001) break;
        // if(i==4) return 0;
    }
    printf("no of iterations are %d ",i);
    return 0;
}