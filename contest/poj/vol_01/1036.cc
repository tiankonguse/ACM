#include"iostream"
#include"cstdlib"
using namespace std;
struct gang{
   int t,s,p;
}gs[101];
int ab(int a){
    if(a>=0)return a;
    else return -a;
}
int cmp(const void *a,const void *b){
   if(((gang *)a)->t==((gang *)b)->t){
      return ((gang *)a)->p-((gang *)b)->p;    
   }
   else
   return ((gang *)a)->t-((gang *)b)->t;
}
int N,K,T,dp[101];
int fun(){
   int sum=0,max;
//   if(gs[0].s<=gs[0].t)dp[0]=gs[0].p;
   dp[0]=0;
   for(int i=1;i<=N;i++){
       max=0;
       for(int j=0;j<i;j++){
           if(gs[i].t-gs[j].t>=ab(gs[i].s-gs[j].s) &&(dp[j]!=0 || j==0)){
               if(dp[j]+gs[i].p>max)max=dp[j]+gs[i].p;
           /*    cout<<gs[i].t<<" "<<gs[j].t<<endl;
               cout<<gs[i].s<<" "<<gs[j].s<<endl;
               cout<<j<<endl;
               cout<<dp[j]<<"+"<<gs[i].p<<endl;*/
           }
       }
       dp[i]=max;
   }
 //  for(int i=0;i<=N;i++)printf("dp[%d]=%d\n",i,dp[i]);
   max=0;
   for(int i=0;i<=N;i++) if(dp[i]>max)max=dp[i];
   return max;
}
int main(){
    gs[0].p=gs[0].t=gs[0].s=0;
    scanf("%d%d%d",&N,&K,&T);
    for(int i=1;i<=N;i++)scanf("%d",&gs[i].t);
    for(int i=1;i<=N;i++)scanf("%d",&gs[i].p);
    for(int i=1;i<=N;i++)scanf("%d",&gs[i].s);
    qsort(gs,N+1,sizeof(gs[0]),cmp);
  /*  for(int i=2;i<=N;i++){
        if(gs[i].t==gs[i-1].t && gs[i].s==gs[i-1].s){
                gs[i-1].p+=gs[i].p;
                for(int j=i+1;j<=N;j++){
                         gs[j-1]=gs[j];
                }
                N--;
                i--;
        }
    }*/
   // for(int i=1;i<=N;i++)printf("%d %d %d\n",gs[i].t,gs[i].p,gs[i].s);
    printf("%d\n",fun());    
   // system("pause");
    return 0;
}
