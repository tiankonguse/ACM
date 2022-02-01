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
int const maxn = 400400;
char s[maxn];
int fail[maxn], len;
int ans[maxn];
void buildF(char *p)
{
    for (int i = 1, j = fail[0] = ~0; i < len; fail[i++] = j += p[j + 1] == p[i])
        while (~j && p[j + 1] != p[i]) j = fail[j];
}
int main()
{
    while (gets(s))
    {
        len = strlen(s);
        buildF(s);
        ans[0] = len;
        int ant = 1;
        for (int p = len - 1; ~fail[p]; p = fail[p])
        {
            ans[ant++] = fail[p] + 1;
        }
        for (int i = ant - 1; ~i; --i)
        {
            if (i == 0) printf("%d\n", ans[i]);
            else printf("%d ", ans[i]);
        }
    }
    return 0;
}
