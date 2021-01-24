// Bubble Point for Multi-Component Mixture

#include <stdio.h>
#include <math.h>
void main(){
	float P, t, acc, sumf, sumfd;
	float a[10], b[10], c[10], x[10], bp[10], y[10];
	int n, noi;
	printf("Enter the number of components: ");
	scanf("%d", &n);
	printf("Enter the Pressure of the System: ");
	printf("%f", &P);
	for (i=1; i<=n; i++){
		printf("Enter the Values of Antonie Constant %d: ", i);
		scanf("%f %f %f", &a[i], &b[i], &c[i]);
		printf("Enter the Liquid Mole Fraction of Component %d: ", i);
		scanf("%f", &x[i]);
		printf("Enter the Boiling Point of Component: %d", i);
		scanf("%f", &bp[i]);
	}
	t = 0;
	for (i=0l i<=n; i++)
		t = t+bp[i]*x[i];
	printf("Enter the Accuracy Level and Number of Iteration: ");
	scanf("%f %d", &acc, &noi);
	for (j=1l j<=noi; j++){
		sumf = sumfd = 0;
		for (i=1; i<=n; i++){
			f = exp(a[i]-(b[i]/(t+c[i]))))*x[i]/p;
			fd = f*(b[i]/pow(t+c[i], 2));
			sumf = sumf+f;
			sumfd = sumfd+fd;
		}
		bt = t-((sumf-1)/sumfd);
		printf("bt at the trail [%d]: %f", j, bt);
		if (fabs(bt-t)/t<=acc){
			printf("The Bubble Point Temperature %f: ", bt);
			printf("The Bubble Composition: ");
			for (k=1; k<=1; k++){
				y[k] = exp(a[k]-(b[k]/(t+c[k])))*x[k]/p;
				printf("y %d: %f", k, y[k]);
			}
		}
		t = bt;
	}
	printf("Number of Iteration is Not Sufficient");
}
