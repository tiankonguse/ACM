/*************************************************************************
    > File Name: F 1476.Euler Numbers.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 14:55:54
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<cstdlib>

typedef int  LL;
const LL MOD = 1000000007;
LL up[1010][1010];
LL down[1010][1010];

LL getUp(int n, int m);

LL getDown(int n, int m){
    if(down[n][m] != -1){
        return down[n][m];
    }

    if(m <= 1){
        return down[n][m] = 0;
    }

    return down[n][m] = (getDown(n,m-1) + getUp(n-1,m-1))%MOD;
}

LL getUp(int n, int m){
    if(up[n][m] != -1){
        return up[n][m];
    }
    if(n <= m){
        return up[n][m] = 0;
    }

    return up[n][m] = (getUp(n,m+1) + getDown(n-1,m)) % MOD;
}

int main() {
    memset(up,-1,sizeof(up));
    memset(down,-1,sizeof(down));

    int cas;
    int n,i,j;
    LL ans[1010],tmp;
    memset(ans,0,sizeof(ans));
    up[1][1] = 1;
    down[1][1] = 1;
    for(i=1;i<=1000;i++){
        for(j=1;j<=i;j++){
            tmp = getUp(i,j);
//            printf("--%d\n",tmp);
            ans[i] = (ans[i] + tmp)%MOD;

        }
//        printf(",%d",ans[i]);
    }
//    printf("--\n");
    scanf("%d",&cas);
//    for(i=1;i<=1000)

    while(cas--){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }

    return 0;
}
