// Isothermal Flash Drum

#include <stdio.h>
#include <math.h>
void main(){
	float T, F, pd, pb, pt, acc, V, sumf, sumfd, f, vnew, L, xx, yy;
	float a[10], b[10], c[10], z[10], p[10], k[10], x[10], y[10];
	int n, i, noi;
	printf("Enter the number of components: ");
	scanf("%d", &n)
	printf("Enter the Tepmerature: ");
	scanf("%f", &T);
	printf("Enter the value of Feed: ");
	scanf("%f", &F);
	for (i=1; i<=n; i++){
		printf("Enter the Antonie constants A, B and C for components [%d]: ", i);
		scanf("%f %f %f", &a[i], &b[i], &c[i]);
		printf("Enter the Mole Fraction of Component [%d]: ", i);
		scanf("%f", &z[i]);
	}
	pd = pb = 0;
	for (i=0; i<=n; i++){
		p[i] = exp(a[i]-(b[i]/(t+c[i])));
		pb = pb+z[i]*p[i];
		pd = pd+z[i]/p[i];
	}
	pd = 1/pd;
	pt = (pb+pd)/2;
	for (i=1; i<=n; i++)
		k[i] = p[i]/pt;
	printf("Enter the accuracy level and number of Iteration: ");
	scanf("%f %d", &acc, &noi);
	printf("Enter the assumed moles of Vapour: ");
	scanf("%f", &V);
	for (j=1; j<=n; j++){
		sumf = sumfd = 0;
		for (i=1; i<=n; i++){
			f = (F*z[k[i]-1)/(F*V+(k[i]-1));
			fd = -f*(k[i]-1)/(F+V*(k[i]-1));
			sumf = sumf+f;
			sumfd = sumfd+fd;
		}
		vnew = V-((sumf-1)/(sumfd));
		if (fabs(vnew-V)/v <= acc){
			V = vnew;
			printf("\n#################\n");
			printf("Moles of Vapour: %f", V);
			printf("\n#################\n");
			L = F-V;
			printf("Moles of Liquid: %f", L);
			xx = yy = 0;
			for (i=1; i<=n; i++){
				y[i] = (F*z[i]*k[i])/(F+V*(k[i]-1));
				x[i] = y[i]/k[i];
				xx = xx + x[i];
				yy = yy + y[i];
				printf("Mole Fraction of Components %d in Liquid Phase: %f", i, x[i]);
				printf("Mole Fraction of Components %d in Vapour Phase: %f", i, y[i]);
			}
			printf("\n#################\n");
			printf("Sum of Mole fraction in Liquid Phase: %f", xx);
			printf("Sum of Mole Fraction in Vapour Phase: %f", yy);
			printf("\n#################\n");
			exit(0);
		}
		V = vnew;
	}
	printf("Number of Iteration is Not Sufficient");
}