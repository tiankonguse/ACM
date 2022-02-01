#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 81
#define MAXM 10005
using namespace std;
const int p=9937;
int dp[MAXN][MAXM];
void init(){
    dp[1][0]=1;
    int k;
    for(int i=2;i<MAXN;i++){
        k=i*i;
        for(int j=k;j>=i-1;j--){
            dp[i][j]=(dp[i-1][j-1]*2+(i-2)*dp[i-1][j-2])%p;
        }
    }
}
int main(){
    int N,M,k;
    init();
    while(scanf("%d%d",&N,&M) && N){
        k=N*N;
        if(M<N-1 || M>k)printf("0\n");
        else printf("%d\n",dp[N][M]);
    }
    return 0;
}
