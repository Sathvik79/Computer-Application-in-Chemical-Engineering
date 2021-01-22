//Newton Rapson Method

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main()
{
    double p, t, r, mavg, noi, acc, x1, x2, a1, b1,
    a2, b2;
    double a12, am, bm, vg, fv, fdv, vnew, sv; 
    int i, toi;
    printf("Enter Pressure and Temperature: ");
    scanf("%lf %lf \n", &p, &t);
    printf("Enter Univesal Gas Const. based on the Pressure and Temperature: ");
    scanf("%lf \n", &r);
    printf("Enter Avg. Molecuar Weight of Mixture: ");
    scanf("%lf \n", &mavg);
    printf("Enter Number of Iteration and Accuracy Level: ");
    scanf("%lf %lf \n", &noi, &acc);
    printf("Enter mole fraction of two lquids: ");
    scanf("%lf %lf \n", &x1, &x2);
    printf("Enter constants a & b of liquid_1: ");
    scanf("%lf %lf \n", &a1, &b1);
    printf("Enter constants a & b of liquid_2: ");
    scanf("%lf %lf \n", &a2, &b2);
    a12 = sqrt(a1*a2);
    am = (x1*x1*a1)+(2*(2*x1*x2*a12))+(x2*x2*a2);
    bm = (x1*b1)+(x2*b2);
    printf("am: %lf \t bm: %lf \n", am, bm);
    vg = (r*t)/p;
    printf("Molar Volume by Ideal Gas: %lf \n", vg);
    for (i=0; i<=noi; i++){
        fv = p*pow(vg, 3)-(pow(vg, 2)*(p*bm+r*t))+(vg*am)-(am*bm);
        fdv = 3*p*pow(vg, 2)-2*vg*(p*bm+r*t)+am;
        vnew = vg-(fv/fdv);
        printf("Trail[%d] = %lf", i, vnew);
        toi = fabs(vnew-vg)/vg;
        if(toi<acc){
            printf("Molar Volume: %lf", vnew);
            sv = vnew/mavg;
            printf("Specific Volume: %lf", sv);
            exit(0);
        }
        else
            vg = vnew;
    }
    printf("Number of Iteration is not Sufficient");
}
