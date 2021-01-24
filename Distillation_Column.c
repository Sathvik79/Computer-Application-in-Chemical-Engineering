// Distillation Column

#include<stdio.h>
#include<math.h>
void main()
 {
	float d,xd,xf,f,xb,b,lr, vr,rr,ls,vs,alfa,q,xi,yi,yb;
	int i,j;
	printf("\n Enter the values of feed flow rate and composition : ");
	scanf("%f %f", &f, &xf);
	printf("\n Enter the composition of distillate and bottom : ");
	scanf("%f %f",&xd,&xb);
	printf("\n Enter the values of reflux ration,q and relative volatility: ");
	scanf("%f %f %f", &rr,&q,&alfa);
	d=f*(xf-xb)/(xd-xb);
	b=f-d;
	lr=rr*d;
	vr=lr+d;
	ls=lr+ q*f;
	vs=ls-b;
	i=0;
	yb= (alfa*xb)/(1+(alfa-1)*xb);
	printf("\n Table giving the tray number and composition of liquid and vapour in stripping section \n");
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
	printf("\n Tray number \t xi \t yi \n");
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
	printf("%d \t %f \t %f \n",i,xb,yb);
	xi=xb;
	yi=yb;
	while(xi<xf){
		i=i+1;
		xi=((yi*vs)+(xb*b))/ls;
		yi=(alfa*xi)/(1+((alfa-1)*xi));
		printf("%d \t %f \t %f \n",i,xi,yi);
	}
	j=0;
	printf("\n Table giving tray number and composition of liquid and vapour in rectifying section \n");
	printf("\n - - - - - - - - - - - - - - - - - -  - - - - -- - -  - - - - -- -  - - - - -- -  - - \n");
	printf("\n Tray number \t xi \t yi \n");
	printf("\n - - - - - - - -- - - - -- - - - - - - - - - - - - - - - - - - - - - - - - -- -  -- - \n");
	while (yi<xd){
		i=i+1;
		j=j+1;
		xi=((yi*vr)+(xb*b)-(xf*f))/lr;
		yi=(alfa*xi)/(1+((alfa-1)*xi));
		printf("%d \t %f \t %f \n", i, xi,yi);
	}
	printf("\n The number of trays in stripping section= %d \n", i-j);
	printf("\n The number of trays in rectifying section= %d \n",j);
	printf("\n The total number of trays for the given column= %d \n",i);
}
