#include"iostream"
#include"algorithm"
using namespace std;
struct stick{
   int l,w;
}st[5001];
int cmp(stick a,stick b){
   if(a.l==b.l)return a.w>b.w;
   else return a.l>b.l;
}
int dp[5001];
int main(){
    int T,N;
    scanf("%d",&T);
    while(T--){
       scanf("%d",&N);
       for(int i=0;i<N;i++)scanf("%d%d",&st[i].l,&st[i].w);
       sort(st,st+N,cmp);
       int max,maxx=0;
       for(int i=0;i<N;i++){
           max=0;
           for(int j=0;j<i;j++){
              if(st[j].w<st[i].w && dp[j]>max)max=dp[j];
           }
           dp[i]=max+1;
           if(dp[i]>maxx)maxx=dp[i];
       }
       printf("%d\n",maxx);
    }
  //  system("pause");
    return 0;
}
