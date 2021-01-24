// Isothermal Flash Drum

#include <stdio.h>
#include <math.h>
void main(){
	float T, F, pb, pd, pt, acc, sumf, sumfd, f, fd, vnew, L, xx, yy;
	float a[10], b[10], c[10], z[10], p[10], k[i];
	int n, i, noi;
	printf("no. Components: ");
	scanf("%d", n);
	printf("Temp: ");
	scanf("%f", &T);
	printf("Feed Value: ");
	scanf("%f", &F);
	for (i=1; i<=n; i++){
		printf("Antonie Const. a,b and c: ");
		scanf("%f %f %f", &a[i], &b[i], &c[i]);
		printf("Mole Fraction: ");
		scanf("%f", z[i]);
	}
	pd = pb = 0;
	for (i=1; i<=n; i++){
		p[i] = exp(a[i]-(b[i]/(t+c[i])));
		pb = pb+z[i]*p[i];
		pd = pb+z[i]/p[i];
	}
	pd = 1/pd;
	pt = (pb+pd)/2;
	for (i=1; 1<=n; i++)
		k[i] = p[i]/pt;
	printf("Accuarcy and No. Iteration: ");
	scanf("%f %d", &acc, &noi);
	printf("Molar Volume: ");
	scanf("%f", &V);
	for (j=1; j<=n; j++){
		sumf = sumfd = 0;
		for (i=1; i<=n; i++){
			f = (F*z[i]*(k[i]-1))/(F*V+(k[i]-1));
			fd = -f*(k[i]-1)/(F+V*(k[i]-1));
			sumf = sumf+f;
			sumfd = sumfd+fd;
		}
		vnew = V-((sumf-1)/sumfd);
		if (fabs(vnew-V)/V<=acc){
			V = vnew;
			printf("\n#############\n");
			printf("Moles of Vapour: %f", V);
			printf("\n#############\n");
			L = F-V;
			printf("Moles of Liquid: %f", L);
			xx = yy = 0;
			for (i=1; i<=n; i++){
				y[i] = (F*z[i]*(k[i]-1))/(F*V*(k[i]-1));
				x[i] = y[i]/k[i];
				xx = xx+x[i];
				yy = yy+y[i];
				printf("Mole Fraction of Components %d in Liquid Phase: %f", i, x[i]);
				printf("Mole Fraction of Components %d in Vapour Phase: %f", i, y[i]);
			}
			printf("\n#############\n");
			printf("Sum of Mole Fraction in Liquid Phase: %f", xx);
			printf("Sum of Mole Fraction in Vapour Phase: %f", yy);
			printf("\n#############\n");
			exit(0);
		}
		v = vnew;
	}
	printf("Iteration Not Sufficient");
}
