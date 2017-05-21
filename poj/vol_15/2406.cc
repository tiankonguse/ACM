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
    for (int i = 1, j = fail[0] = -1; i < len; fail[i++] = j += p[j + 1] == p[i])
        while (j >= 0 && p[j + 1] != p[i]) j = fail[j];
}
int main()
{
    while (scanf(" %s", s) && s[0] != '.')
    {
        len = strlen(s);
        buildF(s);
        printf("%d\n", len % (len - 1 - fail[len - 1]) ? 1 : len / (len - 1 - fail[len - 1]));
    }
    return 0;
}
