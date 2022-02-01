#include"iostream"
#include"cstdio"
#include"string"
#define MAXN 105
#define max(a,b) (a>b?a:b)
using namespace std;
int dp[MAXN][MAXN];
int N1,N2,a[MAXN],b[MAXN];
int main(){
    int T,s1,s2,t1,t2,res;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N1,&N2);
        for(int i=1;i<=N1;i++)scanf("%d",&a[i]);
        for(int i=1;i<=N2;i++)scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));
        res=0;
        bool flag;
        for(t1=1;t1<=N1;t1++){
            for(t2=1;t2<=N2;t2++){
                dp[t1][t2]=max(dp[t1-1][t2-1],max(dp[t1-1][t2],dp[t1][t2-1]));
                if(a[t1]==b[t2])continue;
                flag=false;
                for(s1=t1-1;s1>=1;s1--){
                    if(a[s1]==b[t2]){
                        for(s2=t2-1;s2>=1;s2--){
                            if(b[s2]==a[t1]){
                                flag=true;
                                if(dp[s1-1][s2-1]+2>dp[t1][t2]){
                                    dp[t1][t2]=dp[s1-1][s2-1]+2;
                                    if(dp[t1][t2]>res)res=dp[t1][t2];
                                }
                                break;
                            }
                        }
                        if(flag)break;
                    }
                }
            }
        }
        printf("%d\n",res);
    }
   // system("pause");
    return 0;
}

