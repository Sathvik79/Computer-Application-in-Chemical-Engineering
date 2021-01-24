// Runge Kutta

#include <stdio.h>
#include <math.h>
int main(){
  float to, c, tf, h, t, d, d1, d2, d3, d4;
  float f(float, float);
  printf("Enter to & c: ");
  scanf("%f %f", &to, &c);
  printf("Enter the value of t at which c must be found: ");
  scanf("%f", &tf);
  printf("Enter the Step Lenght: ");
  scanf("%f", &h);
  for (t=to; t<tf; t=t+h){
    d1 = h*f(t, c);
    d2 = h*f(t+(h/2), c+(d1/2));
    d3 = h*f(t+(h/2), c+(d2/2));
    d4 = h*f((t+h), (c+d3));
    d = (d1+(2*d2)+(2*d3)+d4)/6;
    c = c+d;
    printf("t: %f\tc: %f\n", t+h, c);
  }
}
float f(float t, float c){
  float y;
  y = 0.78*pow(c, 2);
  return (y);
}
