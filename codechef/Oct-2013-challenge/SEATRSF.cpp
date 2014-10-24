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

#define N 1005
LL Q = 1e9 + 7;
LL power(LL a , LL b)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a , ans %= Q;
        a *= a , a %= Q , b >>= 1;
    }
    return ans;
}

void work()
{
    LL ans = 0 , X , Y , Z , K;
    cin >> X >> Y >> Z >> K;
    if (Y <= Z)
        puts("0");
    else
    {
        ans = power(Z + 1 , X) + power(Z - 1 , X) - power(Z , X) * 2 + Q + Q;
        ans %= Q;
        ans *= (Y - Z);
        ans %= Q;
        cout << ans << endl;
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //freopen("~output.txt" , "w" , stdout);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
