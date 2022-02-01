#include"iostream"
#include"cstdlib"
using namespace std;
int n,h,f[30],d[30],t[30]={0};
int res[26][30];
int main(){
    int c=0;
    while(scanf("%d",&n)){
       if(n==0)break;
       scanf("%d",&h);
       for(int i=0;i<n;i++)scanf("%d",&f[i]);
       for(int i=0;i<n;i++)scanf("%d",&d[i]);
       for(int i=1;i<n;i++)scanf("%d",&t[i]);
       int total=h*12;
       memset(res,0,sizeof(res));
       int maxfi=-1,bestl=0;
       for(int max=1;max<=n;max++){
           int tu=0;
           for(int i=0;i<max;i++){
              tu+=t[i];
           }
           if(tu>total)break;
           tu=total-tu;
           int maxf,iu,fu,fe=0,ft;
           while(tu){
             maxf=0,iu=0;
             for(int i=0;i<max;i++){
                     ft=f[i]-d[i]*res[max][i];
                     if(ft<0)continue;
                 if(ft>maxf){
                    maxf=ft;
                    iu=i;
                 }
             }
             fe+=maxf;
             res[max][iu]++;
             tu--;
           }
           if(fe>maxfi){
              maxfi=fe;
              bestl=max;
           }
       }
       if(c)printf("\n");
       else c=1;
       for(int i=0;i<n;i++){
          if(i==n-1)printf("%d\n",res[bestl][i]*5);
          else printf("%d, ",res[bestl][i]*5);
       }
       printf("Number of fish expected: %d\n",maxfi);
    }
    return 0;
}
