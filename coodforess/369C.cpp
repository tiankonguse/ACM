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

const int N=211111;
const int M=211111;

int fir[N],toV[M],len[M],next[M],cnt;

vector<int>ans;


void addedge(int u, int v, int w) {
    toV[cnt] = v;
    len[cnt] = w;
    next[cnt] = fir[u];
    fir[u] = cnt++;
}

void init(int nv, int ne) {
    memset(fir, -1, sizeof(fir));
    ans.clear();

    cnt=0;
    int u,v,w;
    for (int i = 0; i < ne; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w); // 不加下面的为有向图
        addedge(v,u, w); // 加下面额为无向图
    }
}

bool dfs(int from,int p, int lev, bool me) {
    int to;
	bool son = false;
    for(int now = fir[from]; now!=-1; now=next[now]) {
        to = toV[now];
        if(to == p) {
            continue;
        } else {
            if(dfs(to,from,lev+1,len[now] == 2)){
				son = true;
            }
        }
    }
    if(me && !son){
		ans.push_back(from);
    }
    return me || son;

}



int main() {
    int n,now;
    while(~scanf("%d",&n)) {
        init(n,n-1);
        dfs(1,-1,0, 0);

        printf("%d\n",ans.size());
        for(int i=0; i<ans.size(); i++) {
            printf(i?" %d":"%d",ans[i]);
        }
        puts("");

    }

    return 0;
}

/*
5
1 2 1
2 3 2
3 4 1
4 5 1
*/
