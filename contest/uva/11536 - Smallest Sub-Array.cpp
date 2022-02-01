#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
#define N 1000005
int n , m , k , ca;
int cnt[101] , a[N];

void work()
{
    int i , j , ans = 1 << 30 , sum = 0;
    scanf("%d%d%d",&n,&m,&k);
    printf("Case %d: " , ++ ca);
    a[1] = 1 , a[2] = 2 , a[3] = 3;
    for (i = 4 ; i <= n ; ++ i)
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
    for (i = 1 ; i <= n ; ++ i)
        if (a[i] > k)
            a[i] = 0;
    memset(cnt , 0 , sizeof(cnt));
    for (i = 1 , j = 1 ; i <= n ; ++ i)
    {
        if (a[i] && !cnt[a[i]])
            ++ sum;
        ++ cnt[a[i]];

        while (j < i && (!a[j] || a[j] && cnt[a[j]] > 1))
            -- cnt[a[j]] , ++ j;
        if (sum == k)
            ans = min(ans , i - j + 1);
    }
    if (ans == 1 << 30)
        puts("sequence nai");
    else
        printf("%d\n" , ans);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}
