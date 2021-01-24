// Newton Rapson Method:

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main(){
    float p, t, r, mavg, acc, x1, x2, a1, a2, b1, b2;
    float a12, am, bm, vg, vnew, fv, fdv, sv;
    int noi, i, toi;
    printf("Enter Pressure and Temperature: ");
    scanf("%f %f", &p, &t);
    printf("Enter Univesal Gas Constant for Temperature: ");
    scanf("%f", &r);
    printf("Enter Avgerage Molecular weight og the given Mixture: ");
    scanf("%f", &mavg);
    printf("Enter total Number of Iteration and Accuracy Level: ");
    scanf("%d %f", &noi, &acc);
    printf("Enter Mole Fraction of CO2 and n-Butane: ");
    scanf("%f %f", &x1, &x2);
    printf("Enter Molar Constant a & b of CO2: ");
    scanf("%f %f", &a1, &b1);
    printf("Enter Molar Constant a & b of n-Buatne: ");
    scanf("%f %f", &a2, &b2);
    a12 = sqrt(a1*a2);
    am = (x1*x1*a1)+(2*x1*x2*a12)+(x2*x2*a2);
    bm = (x1*b1)+(x2*b2);
    printf("am: %f \t bm: %f", am, bm);
    vg = (r*t)/p;
    printf("\nThe Molar Volume by Ideal Gas Law: %f", vg);
    for (i=1; i<=noi; i++){
        fv = p*pow(vg, 3)-pow(vg, 2)*(p*bm+r*t)+(vg*am)-(am*bm);
        fdv = 3*p*pow(vg, 2)-2*vg*(p*bm+r*t)+am;
        vnew = vg-(fv/fdv);
        printf("\nTrail [%d]: %f", i, vnew);
        toi = fabs(vnew-vg)/vg;
        if(toi<acc){
            printf("\nMolar Volume: %f", vnew);
            sv = vnew/mavg;
            printf("\nSpecific Volume: %f", sv);
            exit(0);
        }
        else
            vg = vnew;
    }
    printf("Number of Iteration is not Sufficient");
}
