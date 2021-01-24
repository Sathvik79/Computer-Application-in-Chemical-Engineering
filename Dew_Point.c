#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
 float A[10],B[10],C[10],y[10],bp[10],x[10];
 float t,dt,acc,f,fd,p,sumf,sumfd;
 int i,j,n,k,noi;
 printf("\n Enter the number of components : ");
 scanf("%d",&n);
 printf("\n Enter total pressure of the system : ");
 scanf("%f",&p);
 for (i=1;i<=n;i++){
  printf("\n Enter the vapor molefraction of component = %d ",i);
  scanf("%f",&y[i]);
  printf("\n Enter the value of antonie constants of component = %d ",i);
  scanf("%f %f %f",&A[i],&B[i],&C[i]);
  printf("\n Enter the boiling point of component = %d ",i);
  scanf("%f",&bp[i]);
 }
 t=0;
 for (i=1;i<=n;i++){
  t=t+bp[i]*y[i];
 }
 printf("\n Enter the accuracy level and number of iterations : ");
 scanf("%f %d",&acc,&noi);
 for(j=1;j<=noi;j++){
  sumf=0.0; sumfd=0.0 ;
  for(i=1;i<=n;i++){
   f= (p* y[i])/(exp(A[i]-B[i]/(t+C[i])));
   fd=-f*(B[i]/pow(t+C[i],2));
   sumf=sumf+f;
   sumfd=sumfd+fd;
  }
  dt=t-((sumf-1)/sumfd);
  printf("\n dt at trial[%d] = %f \n",j,dt);
  if(fabs(dt-t)/t<=acc){
    printf("\n THE DEW POINT TEMPERATURE IS %f \n",dt);
    printf("\n The dew composition is \n"); 
    for (k=1;k<=n;k++){
     x[k]=(y[k]*p)/(exp(A[k]-(B[k]/(t+C[k]))));
     printf("\n Component %d = %f \n",k,x[k]);
    }
    exit(0);
   }
   t=dt;
  }
  printf("\n Number of iterations not sufficient \n");
 }
