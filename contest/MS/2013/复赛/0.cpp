/*************************************************************************
    > File Name: 0.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/14 14:02:18
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
/*==================================================*\
| Dinic 最大流 O(V^2 * E)
| INIT: ne=2; head[]置为0; addedge()加入所有弧;
| CALL: flow(n, s, t);
\*==================================================*/
#define typec long long // type of cost
const typec inf = 0x3f3f3f3f; // max of cost
const int E = 40001;
const int N = 201;
struct edge {
    int x, y, nxt;
    typec c;
} bf[E];
int ne, head[N], cur[N], ps[N], dep[N];
void addedge(int x, int y, typec c) {
    // add an arc(x -> y, c); vertex: 0 ~ n-1;
    bf[ne].x = x;
    bf[ne].y = y;
    bf[ne].c = c;
    bf[ne].nxt = head[x];
    head[x] = ne++;
    bf[ne].x = y;
    bf[ne].y = x;
    bf[ne].c = 0;
    bf[ne].nxt = head[y];
    head[y] = ne++;
}
typec flow(int n, int s, int t) {
    typec tr, res = 0;
    int i, j, k, f, r, top;
    while (1) {
        memset(dep, -1, n * sizeof(int));
        for (f = dep[ps[0] = s] = 0, r = 1; f != r; )
            for (i = ps[f++], j = head[i]; j; j = bf[j].nxt) {
                if (bf[j].c && -1 == dep[k = bf[j].y]) {
                    dep[k] = dep[i] + 1;
                    ps[r++] = k;
                    if (k == t) {
                        f = r;
                        break;
                    }
                }
            }
        if (-1 == dep[t]) break;
        memcpy(cur, head, n * sizeof(int));
        for (i = s, top = 0; ; ) {
            if (i == t) {
                for (k = 0, tr = inf; k < top; ++k)
                    if (bf[ps[k]].c < tr)
                        tr = bf[ps[f = k]].c;
                for (k = 0; k < top; ++k)
                    bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
                res += tr;
                i = bf[ps[top = f]].x;
            }
            for (j=cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
                if (bf[j].c && dep[i]+1 == dep[bf[j].y]) break;
            if (cur[i]) {
                ps[top++] = cur[i];
                i = bf[cur[i]].y;
            } else {
                if (0 == top) break;
                dep[i] = -1;
                i = bf[ps[--top]].x;
            }
        }
    }
    return res;
}


void init(){
    ne = 2;
    memset(head,0,sizeof(head));
}

int main() {
    int cas,n,m,old,from,to,val,i;
    scanf("%d",&cas);
    long long now;
    for(int ca=1; ca<=cas; ca++) {
        scanf("%d%d",&n,&m);
        printf("Case #%d:\n",ca);
        init();
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&from,&to,&val);
            addedge(from-1,to-1,val);
            addedge(to-1,from-1,val);
            now = flow(n,0,n-1);
            //printf("->%d ",now);
            if(now > 0){
                printf("%d %lld\n",i,now);
                //old = now;
            }
        }


    }

    return 0;
}
