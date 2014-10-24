#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 20
#define foreach(it , A) for (typeof((A).begin()) it = (A).begin() ; it != (A).end() ; ++ it)
int n , m , K , num[N][N];
LL power[N] ;
map<LL , int> f[2];
char s[N][N];
int X[N] , Y[N] , dig[N];
void work()
{
    int i , j , k;
    K = 0;
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < m ; ++ j)
            num[i][j] = K ++;
    K = 0;
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , s[i]);
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j) {
            if (isdigit(s[i][j])) {
                X[K] = i , Y[K] = j , dig[K] = s[i][j] - '0';
                ++ K;
            }
        }
    }
    int cur = 0 , nxt = 1;
    f[cur].clear();
    f[cur][0] = 0;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j) {
            f[nxt].clear();
            foreach(it , f[cur]) {
                LL x = it -> first;
                for (k = 0 ; k < K ; ++ k) {
                    if (x / power[k] % 10 != dig[k] && num[i][j] - num[X[k]][Y[k]] > m + 1)
                        break;
                }
                if (k < K) continue;
                if (!f[nxt].count(it -> first))
                    f[nxt][it -> first] = it -> second;
                else
                    f[nxt][it -> first] = min(f[nxt][it -> first] , it -> second);
                if (s[i][j] == '.') continue;
                for (k = 0 ; k < K ; ++ k)
                    if (X[k] - 1 <= i && i <= X[k] + 1 && Y[k] - 1 <= j && j <= Y[k] + 1)  {
                        if (x / power[k] % 10 == dig[k])
                            break;
                        x += power[k];
                    }
                if (k < K) continue;
                if (!f[nxt].count(x))
                    f[nxt][x] = it -> second + 1;
                else
                    f[nxt][x] = min(f[nxt][x] , it -> second + 1);
            }
            swap(cur , nxt);
        }
    }
    LL x = 0;
    for (i = K - 1 ; i >= 0 ; -- i)
        x = x * 10 + dig[i];
    printf("%d\n" , f[cur][x]);
}


int main()
{
    freopen("1.txt" , "r" , stdin);
    power[0] = 1;
    for (int i = 1 ; i < 17 ; ++ i)
        power[i] = 10 * power[i - 1];
    while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}


