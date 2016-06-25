#include  <math.h>
#include  <stdio.h>
double sqrt_root(double a,double x0)
{  double x1,y;
  x1=(x0+a/x0)/2.0;
  if(fabs(x1-x0)>=0.00001)
      y=sqrt_root(a,x1);
  else  y=x1;
  return y;
}
double cube_root(double a,double x0)
{  double x1,y;
  x1=(2*x0+a/(x0*x0))/3.0;
  if(fabs(x1-x0)>=0.00001)
      y=cube_root(a,x1);
  else  y=x1;
  return y;
}
int main()
{ double x;
  printf("Enter x: "); scanf("%lf",&x);
  printf("The square root of %lf is %f \n",x, sqrt_root(x,1.0));
  printf("The cube root of %lf is %f \n",x, cube_root(x,1.0));
}