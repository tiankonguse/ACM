#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
#define maxn 10010
using namespace std;

char str[maxn][300];
int h;
int solve(char *s1, char *s2) {
    int p1 = 0, p2 = 0, t = 0;
    while (s1[p1] && s2[p2] && s1[p1] == s2[p2]) {
        ++t;
        ++p1, ++p2;
    }
    return t;
}
int main(){
    int n;
    while (~scanf("%d", &n)) {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            scanf(" %s", str[i]);
            s += strlen(str[i]);
        }

        h = inf;
        for (int i = 1; i < n; ++i) {
            s -= solve(str[i], str[i - 1]) - 1;

        }

        printf("%d\n", s);
    }
    return 0;
}
