#include"iostream"
#include"cstdlib"
#define MAXN 4096
#define mod 100000000
using namespace std;
int M,N;
int map[13][13],lim[13];
int dp[13][MAXN];
bool judge[MAXN];
void init(){
   int t;
   bool flag;
   for(int i=0;i<MAXN;i++){
      t=i;
      flag=true;
      while(t){
         if((t&3)==3){flag=false;break;}
         t>>=1;
      }
      judge[i]=flag;
   }
}
int main(){
    int max_N,res,t;
    init();
    scanf("%d%d",&M,&N);
    max_N=1<<N;
    for(int i=0;i<M;i++){
       for(int j=0;j<N;j++){
          scanf("%d",map[i]+j);
          lim[i]=(lim[i]<<1)|(map[i][j]^1);
       }
    }
    for(int i=0;i<max_N;i++){
       if(judge[i] && !(i&lim[0]))dp[0][i]=1;
    }
    
    for(int i=1;i<M;i++){
       for(int j=0;j<max_N;j++){
          if(judge[j] && !(j&lim[i])){
             for(int k=0;k<max_N;k++){
                if(!(j&k)){
                   dp[i][j]=(dp[i-1][k]+dp[i][j])%mod;
                }
             }
          }
       }
    }
    res=0;
    for(int i=0;i<max_N;i++){
       res=(res+dp[M-1][i])%mod;
    }
    printf("%d\n",res);
    return 0;
}
