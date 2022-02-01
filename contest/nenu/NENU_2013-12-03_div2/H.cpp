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
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int N=1111;
//行为上部,列为下部,挑最少的点,使得所有的边和挑的点相连。最小顶点覆盖。
int n1,n2;
//n1,n2 为二分图的顶点集,其中x∈n1,y∈n2
bool _map[N][N],vis[N];
int _link[N];//_link 记录n2 中的点y 在n1 中所匹配的x 点的编号

int tb[2][N];
int tbn[2];

int find(int x) {
    int i;
    for(i=0; i<n2; i++) {
        if(_map[x][i]&&!vis[i]) {//x->i 有边,且节点i 未被搜索
            vis[i] = true;//标记节点已被搜索

			//如果i 不属于前一个匹配M 或被i 匹配到的节点可以寻找到增广路
            if(_link[i]==-1 || find(_link[i])) {
                _link[i]=x;//更新
                return true;//匹配成功
            }
        }
    }
    return false;
}

int mach() {
    int ans = 0;
    memset(_link, -1, sizeof(_link));
    for (int i = 0; i < n1; i++) {
        memset(vis,false,sizeof(vis));
        if (find(i))ans++;// 如果从第i 个点找到了增光轨,总数加一
    }
    return ans;
}

int a,b;

bool ok(int t1, int t2) {
    int t = t2 - t1;
    return t1 <= t2 && (t <= b || t >= a);
}

int main() {

    int n,i,t,op,j;

    while(~scanf("%d%d",&a,&b)) {
        scanf("%d",&n);
        tbn[0] = tbn[1] = 0;
        for(i=0; i<n; i++) {
            scanf("%d%d",&t,&op);
            tb[op][tbn[op]++] = t;
        }
        n1 = tbn[0];
        n2 = tbn[1];
        if(n1 != n2) {
            puts("Liar");
            continue;
        }
        memset(_map,false,sizeof(_map));
        for(i=0; i<n1; i++) {
            for(j=0; j<n2; j++) {
                if(ok(tb[0][i], tb[1][j])) {
                    _map[i][j] = 1;
                }
            }
        }

        int ans = mach();
        if(ans == n1){
        	puts("No reason");
        	for(i=0;i<n2;i++){
				printf("%d %d\n",tb[0][_link[i]], tb[1][i]);
        	}
        }else{
			puts("Liar");
        }

    }


    return 0;
}
