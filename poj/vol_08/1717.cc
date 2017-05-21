#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAXN 1005
#define MAXD 15005
using namespace std;
int domino[MAXN][2];
int dp[MAXD];
int main(){
    int N;
    while(~scanf("%d",&N)){
        int sum=0,ban,d,p;
        for(int i = 0; i < N; i++) {
            scanf("%d%d",&domino[i][0],&domino[i][1]);
            sum += domino[i][0] + domino[i][1];
        }
        ban = sum/2;
        memset(dp,0xff,sizeof(dp));
        dp[domino[0][1]]=1;
        dp[domino[0][0]]=0;
        for(int i = 1; i < N; i++){
            for(int j = sum; j>=0; j--){
                if(dp[j]== -1)continue;
                if(dp[j+domino[i][0]]== -1 || dp[j] < dp[j+domino[i][0]] ) dp[j+domino[i][0]] = dp[j];
                if(dp[j+domino[i][1]]== -1 || dp[j]+1 < dp[j+domino[i][1]] ) dp[j+domino[i][1]] = dp[j]+1;
                if(domino[i][0]==0)continue;
                else if(domino[i][1]==0)dp[j]++;
                else dp[j]=-1;
            }
          //  for(int j=0;j<=sum;j++)printf("%d ",dp[j]);printf("\n");system("pause");
        }
       // for(int i=0;i<=sum;i++)printf("%d ",dp[i]);printf("\n");
        for(int i=ban,p=0;i-p>=0 && i+p<sum;p++){
            if(dp[i-p]!=-1 && dp[i+p]!=-1){
                printf("%d\n",min(dp[i-p],dp[i+p]));
                break;
            }
        }
    }
    return 0;
}
