#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
typedef __int64 ll;
ll c[101];
map <ll, int> mp;

int main()
{
    for (int i = -50; i <= 50; ++i)
        c[i + 50] = i * i * i;

    ll a[6];
    for (int i = 1; i <= 5; ++i)
        scanf("%I64d", a + i);
    int ret = 0;
    ll s1, s2, s3;
    for (ll x1 = -50; x1 <= 50; ++x1)
    {
        if (x1 == 0) continue;
        s1 = a[1] * c[x1 + 50];
        for (ll x2 = -50; x2 <= 50; ++x2)
        {
            if (x2 == 0) continue;
            s2 = s1 + a[2] * c[x2 + 50];
            mp[s2]++;
        }
    }
    for (ll x3 = -50; x3 <= 50; ++x3)
    {
        if (x3 == 0) continue;
        s1 = a[3] * c[x3 + 50];
        for (ll x4 = -50; x4 <= 50; ++x4)
        {
            if (x4 == 0) continue;
            s2 = s1 + a[4] * c[x4 + 50];
            for (ll x5 = -50; x5 <= 50; ++x5)
            {
                if (x5 == 0) continue;
                s3 = s2 + a[5] * c[x5 + 50];
                if (mp.find(-s3) != mp.end())
                {
                    ret += mp[-s3];
                }
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}
