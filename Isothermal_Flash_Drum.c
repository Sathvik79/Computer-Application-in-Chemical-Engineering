#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    float a[10], b[10], c[10], k[10], p[10], z[10], x[10], y[10];
    float t, pt, acc, F, V, L, vnew, f, fd, pb, pd, sumf, sumfd, xx, yy;
    int i, j, n, noi;
    printf("Enter the number of components in the mixture\n");
    scanf("%d", &n);
    printf("Enter the temperature of the system\n");
    scanf("%f", &t);
    printf("Enter the value of feed F \n");
    scanf("%f", &F);
    for(i=1; i<=n; i++){
        printf("Enter the Antoine constants of a, b, c for components %d \n", i);
        scanf("%f %f %f", &a[i], &b[i], &c[i]);
        printf("Enter the mole fraction of the component %d \n", i);
        scanf("%f", &z[i]);
        
    }
    pb = 0.0; pd = 0.0;
    for(i=0; i<=n; i++){
        p[i] = exp(a[i]-(b[i]/(t+c[i])));
        pb = pb + z[i]*p[i];
        pd = pd + (z[i]/p[i]);
    }
    Pd= 1/pd;
    pt = (pb+pd)/2;
    for(i=1; i<=n; i++)
        k[i] = p[i]/pt;
printf("Enter the accuracy level and number of iterations\n");
scanf("%f %d", &acc, &noi);
printf("Enter the assumed moles of vapour \n");
scanf("%f", &V);

for(j=1; j<=noi; j++){
    sumf = 0.0; sumfd = 0.0;
    for(i=1; i<=n; i++){
        f = (F*z[i]*k[i])/(F+V*(k[i]-1));
        fd = -f*(k[i]-1)/(F+V*(k[i]-1));
        sumf = sumf + f;
        sumfd = sumfd + fd;
    }
    vnew = V - ((sumf-1)/(sumfd));
    if(fabs(vnew-V)/V<= acc){
        V = vnew;
        printf(" Moles of vapour is %f \n", V);
        L = F-V;
        printf("Moles of liquid is %f \n", L);
        xx = 0.0; yy = 0.0;
        for(i=1; i<=n; i++){
            y[i] = (F*z[i]*k[i])/(F+V*(k[i]-1));
            x[i] = y[i]/k[i];
            xx = xx + x[i];
            yy = yy + y[i];
            printf("Mole fraction of component %d in liquid phase = %f \n", i, x[i]);
            printf("Mole fraction of component %d in vapour phase = %f \n", i, y[i]);
        }
        printf("Sum of molefraction in liquid phase = %f", xx);
        printf("Sum of molefraction in vapour phase = %f", yy);
        exit(0);
    }
    V = vnew;
}
printf("Number of iterations are insufficient \n");
}
