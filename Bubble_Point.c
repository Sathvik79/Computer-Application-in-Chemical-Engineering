// Bubble Point for Multi-Component Mixture

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main(){
	float A[10],B[10],C[10],x[10],y[10],bp[10];
	float t,bt,acc,f,fd,p,sumf,sumfd;
	int i,j,k,n,noi;
	printf("Enter the number of components \n");
	scanf("%d",&n);
	printf("Enter the total pressure of the system \n");
	scanf("%f",&p);
	for(i=1;i<=n;i++)
	{ 
	printf("Enter the values of antione constants of component %d \n",i);
	scanf("%f %f %f",&A[i],&B[i],&C[i]);
	printf("Enter the liquid molefraction of component %d \n",i);
	scanf("%f",&x[i]);
	printf("Enter the boling point of component %d \n",i);
	scanf("%f",&bp[i]);
	}
    	t=0;
	for(i=1;i<=n;i++){
	 t=t+(bp[i]*x[i]);
	}
	printf("Enter the accuracy level and the number of iterations \n");
	scanf("%f %d",&acc,&noi);
	for(j=1;j<=noi;j++){
		sumf=0.0;sumfd=0.0;
		for(i=1;i<=n;i++){
			f=exp(A[i]-(B[i]/(t+C[i])))*x[i]/p;
			fd=f*(B[i]/pow(t+C[i],2));
			sumf=sumf+f;
			sumfd=sumfd+fd;
		}
		bt=t-((sumf-1)/sumfd);
		printf("bt at trail [%d]=%f \n",j,bt);
		if(fabs(bt-t)/t<=acc){
			printf("The bubble point temperature is %f \n",bt);
			printf("The bubble composition is \n");
			for(k=1;k<=n;k++){
				y[k]=exp(A[k]-(B[k]/(t+C[k])))*x[k]/p;
				printf("y %d=%f \n",k,y[k]);
			}
                        exit(0);
		}
		t=bt;
	}
	printf("Number of iterations are not sufficient \n");
}
