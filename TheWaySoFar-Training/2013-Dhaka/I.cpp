#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define N 2505
int n , m , pre[N] , mcnt , S;
struct edge {
    int x , next;
}e[50005];
bool f[N];
int ans[N * 10] , ca;
pair<int , int> E[N * 10];

void work() {
    int i , j , x , y , z;
    scanf("%d%d%d",&n,&m,&S);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        E[i] = make_pair(x , y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    memset(f , 0 , sizeof(f));
    memset(ans , 0 , sizeof(ans));
    queue<int> Q;
    Q.push(S) , f[S] = 0 , mcnt = 0;
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x;
            if (!ans[i >> 1])
                ans[i >> 1] = ++ mcnt;
            if (!f[y])
                f[y] = 1 , Q.push(y);
        }
    }
    printf("Case %d:\n" , ++ ca);
    for (i = 0 ; i < m ; ++ i) {
        printf("%d %d %d\n" , E[i].first , E[i].second , ans[i]);
    }
}

int main(){
    //freopen("1.txt" , "r" , stdin);
    int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}
