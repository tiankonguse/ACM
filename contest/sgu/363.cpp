#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<queue>
using namespace std;

typedef long long LL;
#define N 105
int n , m;
int S[N] , T[N] , B[N];
queue<int> Q[N];
pair<int , int> ans[N];

int main(){
    //freopen("1.txt" , "r" , stdin);
    int i , j , x;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&S[i] , &T[i]);
        for (j = 1 ; j <= m ; ++ j) {
            while (!Q[j].empty()) {
                x = Q[j].front();
                if (B[x] + T[x] <= S[i]) {
                    Q[j].pop();
                    ans[x].second = B[x] + T[x];
                    if (!Q[j].empty())
                        B[Q[j].front()] = B[x] + T[x];
                } else
                    break;
            }
        }
        pair<int , int> res(1 << 30 , 1 << 30);
        for (j = 1 ; j <= m ; ++ j) {
            res = min(res , make_pair((int)Q[j].size() , j));
        }
        ans[i].first = res.second;
        if (Q[ans[i].first].empty())
            B[i] = S[i];
        Q[ans[i].first].push(i);
    }
    S[i] = 1 << 30;
        for (j = 1 ; j <= m ; ++ j) {
            while (!Q[j].empty()) {
                x = Q[j].front();
                if (B[x] + T[x] <= S[i]) {
                    Q[j].pop();
                    ans[x].second = B[x] + T[x];
                    if (!Q[j].empty())
                        B[Q[j].front()] = B[x] + T[x];
                } else
                    break;
            }
        }
    for (i = 1 ; i <= n ; ++ i)
        printf("%d %d\n" , ans[i].first , ans[i].second);
    return 0;
}
