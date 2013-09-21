
/*************************************************************************
    > File Name: Road.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 20:02:37
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

const int VN = 10005;
const int INF = 2000000000;
typedef  int Type;

const int N=10005;
const int M=100000;

void addedge(int u, int v, int  w) {
　　toV[cnt] = v;len[cnt] = w;
　　next[cnt] = fir[u];fir[u] = cnt++;
}
void init(int nv, int ne) {
	memset(fir, -1, sizeof(fir));
	cnt=0;
	int u,v,w;
	for (int i = 0; i < ne; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w); // 不加下面的为有向图
		addedge(v u, w); // 加下面额为无向图
	}
}

class Prim{
public:
    inline void init(int _n){
        n=_n; MSTsum = 0;
        for(int i=0; i<=n; ++i){
            w[i][i] = INF;
            for(int j=i+1; j<=n; ++j)
                w[i][j]=w[j][i]=INF;
        }
    }
    inline void insert(int u, int v, Type weight){
        if(w[u][v]>weight) w[u][v] = weight;
    }
    Type prim(){
        memset(vis, 0, sizeof(vis));
        memset(path, 0, sizeof(path));
        memset(used, 0, sizeof(used));
        vis[1] = true;
        for(int i=1; i<=n; ++i){
            key[i] = w[1][i]; pre[i] = 1;
        }
        for(int i=1; i<n; ++i){
            int u=-1;
            for(int j=1; j<=n; ++j)if(!vis[j]){
                if(u==-1||key[j]<key[u]) u=j;
            }
            if(w[pre[u]][u]==INF) return -1;
            used[pre[u]][u] = used[u][pre[u]] = true;
            MSTsum += w[pre[u]][u];
            vis[u] = true;
            for(int j=1; j<=n; ++j){
                if(vis[j]&&j!=u){
                    path[u][j]=path[j][u]=max(path[j][pre[u]],key[u]);
                }
                if(!vis[j]&&key[j]>w[u][j]){
                    key[j] = w[u][j]; pre[j] = u;
                }
            }
        }
        return MSTsum;
    }
    int is_unique(int &val){
        val= prim();
        if(val == -1)return -1;

        int tmp;
        for(int i=1; i<=n; ++i){
            for(int j=i+1; j<=n; ++j)if(!used[i][j]){
                tmp = MSTsum + path[i][j] - w[i][j];
                if(tmp==MSTsum){
                     return 1;
                }
            }
        }
        return 0;
    }

private:
    int fir[N],toV[M],next[M],cnt;
    Type len[M];
    Type MSTsum;
    Type w[VN][VN], key[VN];
    int pre[VN], path[VN][VN], n;
    bool vis[VN], used[VN][VN];
};
Prim G;

int main(){
    int T, n, m, a, b, c;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        G.init(n);
        for(int i=0; i<m; ++i){
            scanf("%d%d%d",&a,&b,&c);
            G.insert(a,b,c);
            G.insert(b,a,c);
        }
        int val;
        int ans = G.is_unique(val);
        if(ans==-1) puts("-1");
        else printf("%d %d\n", val,ans);
    }
    return 0;
}
