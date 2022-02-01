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
#include <cassert>
using namespace std;
typedef long long LL;
#define N 1005
#define M 100005

int cnt[10];
char s[N];
void work()
{
    int ans = 0;
    for (int i = 1 ; i <= 7 ; ++ i)
        scanf("%d", &cnt[i]);
    scanf("%s" , s);
    if (strcmp(s , "RED") == 0) {
        ans += 7;
    }
    if (!cnt[1]) {
        for (int i = 1 ; i <= 7 ; ++ i)
            ans += i * cnt[i];
    } else {
        ans += cnt[1] * 8;
        for (int i = 2 ; i <= 7 ; ++ i)
            ans += i * cnt[i];
    }
    cout << ans << endl;
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

