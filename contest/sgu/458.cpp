#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;

#define N 100005
#define M 1000005
int n , w[N];
pair<int , int> a[M] , b[M] , c[M] , ans , f[N];
bool v[N];

void print(int x) {
    if (!x) return;
    print(f[x].second);
    printf("%d%c" , w[x] - 1 , " \n"[x == ans.second]);
}

void work()
{
    int i , j;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&w[i]) , ++ w[i];
    for (i = 1 ; i <= n ; ++ i) {
        pair<int , int>& res = f[i] , ret;
        for (j = w[i] + 2 ; j < M ; j += j & -j)
            res = max(res , a[j]);
        for (j = w[i] - 2 ; j > 0 ; j -= j & -j)
            res = max(res , b[j]);
        res = max(res , c[w[i]]);
        ret = make_pair(res.first + 1 , i);
        ans = max(ans , ret);
        for (j = w[i] ; j > 0 ; j -= j & -j)
            a[j] = max(ret , a[j]);
        for (j = w[i] ; j < M ; j += j & -j)
            b[j] = max(ret , b[j]);
        c[w[i]] = max(ret , c[w[i]]);
    }
    printf("%d\n" , n - ans.first);
    print(ans.second);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}
