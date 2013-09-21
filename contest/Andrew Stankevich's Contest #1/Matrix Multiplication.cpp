/*************************************************************************
    > File Name: Matrix Multiplication.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 18:19:48
 ************************************************************************/

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
const int N = 100000;
int row[N],col[N];

int main() {
    int tmp = 100000;
    int a=2;
    for(int i=0;i<tmp;i++){
        for(int j=0;j<tmp;j++){
            if(i&1)a++;
            else a--;
        }
    }

    int cas,n,m,from,to;
    long long  ans;
    scanf("%d",&cas);
    for(int ca=0;ca<cas;ca++){
        if(ca)puts("");
        scanf("%d%d",&n,&m);
        memset(row,0,sizeof(int)*(n+2));
        memset(col,0,sizeof(int)*(n+2));
        for(int i=0;i<m;i++){
            scanf("%d%d",&from,&to);
            row[from]++;
            row[to]++;
            col[from]++;
            col[to]++;
        }
        ans = 0;
        for(int i=1;i<=n;i++){
            ans += row[i] * col[i];
        }
        printf("%lld\n",ans);

    }
    return 0;
}
