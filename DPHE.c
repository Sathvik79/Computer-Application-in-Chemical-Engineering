#include<stdio.h>
#include<math.h>
float L;
int main(){
  float htc(float, float, float, float);
  //defining global variables
  float mh, mc, th1, th2, tc2, tc1, roh, muh, cph, kh,k, roc, muc, cpc, kc, dii, dio, Doi, Doo, lmtd, vc, vh, hi;
  float hi0, h0, ud, uc, ac, ah, rec, reh, prc, prh, de, q, a, rd, deh, n, ft, fp, le, dpt, fsh, ln, dfa, dfl, dpsh;
  //obtaining the required input from user
  printf("Enter the inlet and outlet temperature of the hot fluid:");
  scanf("%f %f", &th1, &th2);
  printf("Enter the inlet and outlet temperature of the cold fluid:");
  scanf("%f %f", &tc1, &tc2);
  printf("Enter the mass flowrate of hot fluid:");
  scanf("%f", &mh);
  printf("Enter ro, mu, cp and k for hot fluid at average fluid temperature %f:", (th1+th2)/2);
  scanf("%f %f %f %f", &roh, &muh, &cph, &kh);
  printf("Enter ro, mu, cp and k for cold fluid at average fluid temperature %f:", (tc1+tc2)/2);
  scanf("%f %f %f %f", &roc, &muc, &cpc, &kc);
  printf("Enter inner and outer dia of inner pipe (tube):");
  scanf("%f %f", &dii, &dio);
  printf("Enter inner and outer dia of outer pipe (shell):");
  scanf("%f %f", &Doi, &Doo);
  printf("Enter the value of dirt coefficient (rd) and length of the pipe (L):");
  scanf("%f %f", &rd, &L);
  // calculation of mass flowrate of cold fluid, mc
  mc = mh*cph*(th1-th2)/(cpc*(tc2-tc1));
  //assuming counter-current flow for calculating LMTD
  lmtd = ((th1-tc2)-(th2-tc1))/log((th1-tc2)/(th2-tc1));
  // calculation for tube inside area, ah
  ah = 3.14*dii*dii/4;
  vh = mh/(roh*ah);
  reh = roh*dii*vh/muh;
  prh = cph*muh/kh;
  hi = htc(reh, prh, dii, kh);
  hi0 = hi*dii/dio;
  printf("\n Details on tube side:\n");
  printf("\n vh = %f \t \t reh=%f \t \t hi=%f \t \t hio=%f", vh, reh, hi, hi0);
  de =Doi-dio;
  ac = 3.14*(pow(Doi,2)-pow(dio,2))/4;
  vc= mc/(roc*ac);
  rec= roc*de*vc/muc;
  prc = cpc*muc/kc;
  //calculation of dia for heat flow, deh
  deh = (pow(Doi,2)-pow(dio,2))/dio;
  h0 = htc(rec, prc, deh, kc);
  printf("\n Details on outer pipe(shell side):");
  printf("\n vc = %f \t \t rec=%f \t \t ho=%f", vc, rec, h0);
  uc = (h0*hi0/(h0+hi0));
  ud = (1/h0) + (1/hi0) + rd;
  ud = 1/ud;
  q = mh*cph*(th1-th2);
  a = q/(ud*lmtd);
  printf("\n Area of heat transfer = %f", a);
  n = a/(3.148*dio*L);
  printf("\n Number of tubes = %f", n);
  //calculation of pressure drop
  ft = 0.0035 + 0.264/pow(reh, 0.42);
  le = 9.5*dii*2*(n-1)+n*L;
  printf("\n ft = %f \t le = %f", ft, le);
  dpt = ((4*ft*vh*vh*roh*roh*le)/(2*9.81*dii*roh*roh))*roh;
  printf("\n Pressure drop at tube side = %f", dpt);
  fsh = 0.0035 + 0.264/pow(rec, 0.42);
  ln=n*L;
  printf("\n fsh = %f \t ln=%f", fsh, ln);
  dfa = (2*fsh*vc*vc*roc*roc*ln)/(9.81*roc*roc*de);
  dfl = (3*vc*vc*n)/(2*9.81);
  dpsh=(dfa+dfl)*roc;
  printf("\n Pressure drop at shell side = %f", dpsh);
}
float htc(float re, float pr, float d, float k){
  float h;
  if(re>10000)
  h=0.023*pow(re,0.8)*pow(pr,0.33)*k/d;
  else if(re<2100)
  h = 1.86*pow((re*pr*L/d),0.33)*k/d;
  else
  h=0.116*(pow(re,2/3)-125)*pow(pr,1/3)*(1+pow((d/1),2/3));
  return(h);
}
