#include <stdio.h>
#include <math.h>

#define f(x) x *x *x - 2 * x - 5

int main()
{
    float x0, x1, x2, f0, f1, f2, e;
        printf("enter the value inital 2 guess");
        scanf("%f %f", &x0, &x1);

        printf("%f %f\n", f(x0), f(x1));
        printf("enter the tolerable error ");
        scanf("%f", &e);
        f0 = f(x0);
        f1 = f(x1);
      int step=1;
      printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do{
        x2= (x0+x1)/2;
        f2=f(x2);
        printf("%d\t%f\t%f\t%f\t%f\n",step,x0,x1,x2,f(x2));
   if(f0*f2<0)
   {
    f1=f2;
    x1=x2;
   }
   else
   {
    f0=f2;
    x0=x2;
   }
   step++;
    }while(fabs(f2)>e);
    printf("\nroot is %f", x2);
    return 0;
}