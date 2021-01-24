// Least Square Method

#include <stdio.h>
#include <math.h>
void main(){
  float roh, mu, l, d, sumr, sumf, sumrf, sumrr, slope, intcpt;
  float v[50], pd[50];
  int n, i;
  printf("Enter Density, Velocity, Height & Diameter: ");
  scanf("%f %f %f %f", &roh, &mu, &l, &d);
  printf("Enter the number of Trials: ");
  scanf("%d", &n);
  printf("Enter the Values of Velocity: ");
  for (i=1; i<=n; i++){
    printf("v[%d]: ", i);
    scanf("%f", &v[i]);
  }
  sumr = sumf = sumrr = sumrf = 0;
  for (i=1; i<=n; i++){
    pd[i] = (32*mu*v[i]*l)/pow(d, 2);
    sumr = sumr+log((d*v[i]*roh)/mu);
    sumf = sumf+log((d*pd[i]*2)/(4*roh*v[i]*v[i]*l));
    sumrf = sumrf+log((d*v[i]*roh)/mu)*log((d*pd[i]*2)/(4*roh*v[i]*v[i]*l));
    sumrr = sumrr+log((d*v[i]*roh)/mu)*log((d*v[i]*roh)/mu);
  }
  slope = ((n*sumrf)-(sumr*sumf))/((n*sumrr)-pow(sumr, 2));
  intcpt = (sumf-(slope*sumr))/n;
  printf("\nThe Intercept is %0.2f", intcpt);
  intcpt = exp(intcpt);
  printf("\nThe relation is lnf: %0.1f ln(Nre)+ln %0.1f", slope, intcpt);
}
