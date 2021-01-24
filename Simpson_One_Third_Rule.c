// Simpson's 1/3rd Rule

#include <stdio.h>
#include <math.h>
int main(){
  float xo, xn, k, n, h, sum, x;
  float simp(float x);
  printf("Enter the Initial and Final Conversion Limits: ");
  scanf("%f %f", &xo, &xn);
  printf("Enter the Values of Rate Conversion: ");
  scanf("%f", &k);
  printf("Enter the Number of Steps: ");
  scanf("%f", &n);
  h = (xn-xo)/n;
  printf("The step lenght is %f: ", h);
  sum = simp(xo)+simp(xn);
  for (x=xo+h; x<xn; x=x+2*h)
    sum = sum+4*simp(x);
  for (x=xo+2*h; x<xn-h; x=x+2*h)
    sum = sum+2*simp(x);
  sum = sum*(h/(3*k));
  printf("\nTime Required is %f", sum);
}
float simp(float x){
  float y;
  y = 1/(1-x);
  return (y);
}
