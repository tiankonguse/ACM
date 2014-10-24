#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 500005;
int n , s[N];
bool f[26][26][26][26];

bool dfs(int k , int a , int b , int c) {
    if (k == n)
        return 1;
    bool* p = f[a][b][c];
    for (int i = 0 ; i < 26 ; ++ i)
        if (!p[i]) {
            p[i] = 1;
            s[k] = i;
            if (dfs(k + 1 , b , c , i))
                return 1;
            p[i] = 0;
        }
    return 0;
}

void work()
{
    if (n <= 4) {
        for (int i = 0 ; i < n ; ++ i)
            putchar('a');
        puts("");
        return;
    }
    if (n >= 456980) {
        puts("Impossible");
        return;
    }
    s[0] = s[1] = s[2] = 0;
    memset(f , 0 , sizeof(f));
    dfs(3 , 0 , 0 , 0);
    for (int i = 0 ; i < n ; ++ i)
        putchar(s[i] + 'a');
    puts("");
}

int main()
{
    while (~scanf("%d",&n))
        work();
    return 0;
}
