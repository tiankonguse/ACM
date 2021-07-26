/*************************************************************************
    > File Name: 五一的旅游003.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/17 8:57:14
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N = 3011;
const int inf = 1061109567;
typedef long long LL;
bool map[N][N];
set<LL>Set;
LL ll = N;

int n;
struct T{
    int node,fa,num;
    void init(int node, int fa, int num){
        this->node = node;
        this->fa = fa;
        this->num = num;
    }
}now,tmp;
queue<T>que;
bool check(int b){
    return Set.find(now.fa * ll * ll + now.node * ll + b) == Set.end();
}

void bfs() {
    int i;

    while(!que.empty())que.pop();
    now.init(1,0,0);
    que.push(now);

    bool ok;

    while (!que.empty()) {
        now = que.front();que.pop();
//        printf("---%d  %d  %d\n",now.fa,now.node,now.num);
        for (i = 1; i <= n; i++) {
            if (now.node == i)continue;
            ok = check(i);
//            printf("--ok=%d\n",ok);
            if (map[now.node][i] && ok){
//                printf("--i=%d\n",i);
                map[now.node][i] = false;
                tmp.init(i,now.node,now.num+1);
                que.push(tmp);
                if (i==n) {
                    printf("%d\n",now.num+1);
                    return;
                }
            }
        }
    }
    printf("-1\n");
}
int main() {
    int m,k,a,b,c;
    while(~scanf("%d%d%d",&n,&m,&k)) {
        memset(map,false,sizeof(map));
        while(m--) {
            scanf("%d%d", &a, &b);
            map[a][b] = true;
            map[b][a] = true;
        }
        Set.clear();
        while(k--) {
            scanf("%d%d%d", &a, &b, &c);
            Set.insert(a * ll * ll + b * ll + c);
        }
        bfs();
    }
    return 0;
}
