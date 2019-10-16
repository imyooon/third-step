#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int double_comp(const void* x,const void* y) {
	const double* a=(const double*)x;
	const double* b=(const double*)y;
	if(*a>*b)return -1;
	if(*a<*b)return 1;
	return 0;
}

  int main()
  {
    double s_score[30]={65.0,80.0,67.0,35.0,58.0,60.0,72.0,75.0,68.0,92.0,36.0,50.0,2.0,58.5,46.0,42.0,78.0,62.0,84.0,70.0};
    double e_score[30]={44.0,87.0,100.0,63.0,52.0,60.0,58.0,73.0,55.0,86.0,29.0,56.0,89.0,23.0,65.0,84.0,64.0,27.0,86.0,84.0};
    double s_sum=0,s_ave,s_sd,s_disp,s_dv[30],s_score2[30],e_sum=0,e_ave,e_sd,e_disp,e_dv[30],e_score2[30],a=0,b=0;

    for(int i=0;i<20;i++){
       s_sum+=s_score[i];
       e_sum+=e_score[i];
      }
      s_ave=s_sum/20.0;
      e_ave=e_sum/20.0;

      for(int i=0;i<20;i++){
         a+=pow(s_score[i]-s_ave,2.0);
         b+=pow(e_score[i]-e_ave,2.0);
        }
      s_disp=a/20.0;
      e_disp=b/20.0;
      s_sd=sqrt(a/20.0);
      e_sd=sqrt(b/20.0); 
      for(int i=0;i<20;i++){
         if(s_score[i]>s_ave)s_dv[i]=50.0+(s_score[i]-s_ave)*10/s_sd;
         else if(s_score[i]<s_ave)s_dv[i]=50.0-(s_ave-s_score[i])*10/s_sd;
         else s_dv[i]=50.0;

         if(e_score[i]>e_ave)e_dv[i]=50.0+(e_score[i]-e_ave)*10/e_sd;
         else if(e_score[i]<e_ave)e_dv[i]=50.0-(e_ave-e_score[i])*10/e_sd;
         else e_dv[i]=50.0;

        }

      printf("理科の合計点=%f 理科の平均点=%f 理科の標準偏差=%f\n",s_sum,s_ave,s_sd);
      printf("英語の合計点=%f 英語の平均点=%f 英語の標準偏差=%f\n",e_sum,e_ave,e_sd);
      for(int i=0;i<20;i++){
         printf("%d番の人の偏差値は%fと%fです\n",i+1,s_dv[i],e_dv[i]);
        }

       qsort(s_score, 20, sizeof(s_score[0]), double_comp);
       qsort(e_score,20,  sizeof(e_score[0]), double_comp);
      printf("理科　点数高い順\n");  
      for(int i=0;i<20;i++){
         printf("%f\n",s_score[i]);
        }
      printf("\n");
      printf("英語　点数高い順\n");
      for(int i=0;i<20;i++){
         printf("%f\n",e_score[i]);
        } 
      return 0;
  }
