/*************************************************************************
    > File Name: E 五一的旅游.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 18:04:08
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

const int N = 3011;
const int inf = 1061109567;
typedef long long LL;
int path[N][N];
set<LL>Set;
//make_pair
int main() {

    int n,m,k,from,mid,to,i,j,tmp;
    LL l=N*N;
    while(~scanf("%d%d%d",&n,&m,&k)) {
        memset(path,0x3f3f,sizeof(path));
        Set.clear();
        while(m--) {
            scanf("%d%d",&from,&to);
            path[from][to] = path[to][from] = 1;
        }
        while(k--) {
            scanf("%d%d%d",&from,&mid,&to);
            Set.insert(mid*l+from * N + to);
        }

        for(k=1; k<=n; k++) {
            for(i=1; i<=n; i++) {
                if(path[i][k] == inf)continue;
                for(j=1; j<=n; j++) {
                    if(path[k][j] != inf && path[i][j]>path[i][k]+path[k][j] && Set.find(k*l+i * N + j) == Set.end())path[i][j]=path[i][k]+path[k][j];
                }
            }
        }

        printf("%d",path[1][n] == inf?-1:path[1][n]);

    }
    return 0;
}
