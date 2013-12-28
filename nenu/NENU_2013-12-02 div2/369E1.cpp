#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int N = 1010000;

struct Edge {
    int l,r;
    bool operator<(Edge p)const {
        return this->l>p.l||(this->l == p.l && this->r < p.r);
    }
} edge[N],now;
int n;

int sum[N];
int node[N];

void add(int x, int val) {
    for (; x<=S; x+=x&-x) sum[x] += val;
}

int sum(int x) {
    int d=0;
    for (; x; x-=x&-x) d+=sum[x];
    return d;
}

int main() {
    int m,i,j,cnt,ans;
    int maxP,l,r;
    while(~scanf("%d%d",&n,&m)) {
        S=1e6+1;
        for(i=0; i<n; i++) {
            scanf("%d%d",&edge[i].l, &edge[i].r);
        }
        sort(edge,edge+n);

        while(m--) {
            scanf("%d",&cnt);
            maxP = 0;
            node[0] = 0;
            for(i=1; i<=cnt; i++) {
                scanf("%d",&node[i]);
            }
            node[i] = S-1;

            i=cnt;j=0;
            now.l = node[i]+1;
            now.r = S - 1;
            for(; ;){

            }




        }
    }

    return 0;
}
