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
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 100005
int n , L;
char s[N];
double a[N] , eps = 1e-7;
pair<int , int> res;

bool check(double val)
{
    int i , l , r;
    double ans = -1e60;
    pair<double , int> x(1e60 , 0);
    for (i = 1 ; i <= n ; ++ i)
        a[i] = a[i - 1] + (s[i] - '0') - val;
    for (i = L ; i <= n ; ++ i)
    {
        x = min(x , make_pair(a[i - L] , L - i));
        double val = a[i] - x.fi;
        int len = i + x.se , top = -x.se;
        if (val > ans + eps)
            ans = val , l = top , r = top + len;
        else if (val > ans - eps && len < r - l)
            ans = val , l = top , r = top + len;
        else if (val > ans - eps && len == r - l && top < l)
            ans = val , l = top , r = top + len;
    }
    if (ans >= -eps)
    {
        res = make_pair(l + 1 , r);
        return 1;
    }
    return 0;
}
void work()
{
    scanf("%d%d",&n,&L);
    scanf("%s" , s + 1);
    double l = 0 , r = 1 , m;
    res = make_pair(1 << 30 , 1 << 30);
    while (r - l > 1e-10)
    {
        m = .5 * (l + r);
        if (check(m))
            l = m;
        else
            r = m;
    }
    printf("%d %d\n" , res.fi , res.se);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
