#include<stdio.h>
#include<math.h>

#define f1(x,y,z) (85-(6*y-z))/27
#define f2(x,y,z) (72-(6*x+2*z))/15
#define f3(x,y,z) (110-(x+y))/54


int main()
{
    float x0=0,y0=0,z0=0, x1,y1,z1, e1,e2,e3,e;
    int count=1;
    printf("enter tolerable error");
    scanf("%f",&e);

do
{
x1=f1(x0,y0,z0);
y1=f2(x1,y0,z0);
z1=f3(x1,y1,z0);
printf("iteration %d x=%f y=%f z=%f\n",count,x1,y1,z1);

e1=fabs(x0-x1);
e2=fabs(y0-y1);
e3=fabs(z0-z1);

count++;
x0=x1;
y0=y1;
z0=z1;
} while (e1>e && e2>e && e3>e);

printf("solution is \n");
printf("iteration %d x=%f y=%f z=%f\n",count,x1,y1,z1);

return 0;
}
