/**************************************************************************
 **      File Name: 1.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/31 18:27:12
/**************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

const int maxn=22;

int str[maxn][maxn];
int pos[maxn][maxn];

int main(){

    int N,K,i,j,k,t,ans;
    while(scanf("%d%d",&N,&K)!=EOF){

        for(j=1;j<=K;j++){
            scanf("%d",&pos[1][j]);
            str[1][j] = 0;
        }

        for(i=2;i<=N;i++){
            for(j=1;j<=K;j++){
                scanf("%d",&pos[i][j]);
                str[i][j] = str[i-1][1] + abs(pos[i][j] - pos[i-1][1]);
                for(k=2;k<=K;k++){
                    str[i][j] = min(str[i][j],str[i-1][k] + abs(pos[i][j] - pos[i-1][k]));
                }
            }
        }
        ans = str[N][1];
        for(k=2;k<=K;k++){
            ans = min(ans,str[N][k]);
        }
        printf("%d\n",ans);
    }

    return 0;
}
/*
2 2
1 10
4 9
3 5
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
*/
