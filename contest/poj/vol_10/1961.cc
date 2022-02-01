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
int const maxn = 1000100;
char s[maxn];
int fail[maxn], len;
void buildF(char *p)
{
    for (int i = 1, j = fail[0] = ~0; i < len; fail[i++] = j += p[j + 1] == p[i])
        while (~j && p[j + 1] != p[i]) j = fail[j];
}
int main()
{
    for (int ca = 1; scanf("%d", &len) && len; ++ca)
    {
        scanf(" %s", s);
        buildF(s);
        printf("Test case #%d\n", ca);
        for (int i = 2; i <= len; ++i)
        {
            if (i % (i - 1 - fail[i - 1]) == 0 && fail[i - 1] != -1)
            {
                printf("%d %d\n", i, i / (i - 1 - fail[i - 1]));
            }
        }
        puts("");
    }
    return 0;
}
