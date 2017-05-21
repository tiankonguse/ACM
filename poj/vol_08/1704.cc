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
#define maxn 1010
using namespace std;
int a[maxn];
int main(){
    int T, n;
    for (scanf("%d", &T); T--; ) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);

        int t = 0;
        if (n & 1) {
            for (int i = 0; i < n; i += 2) {
                if (i == 0) t ^= a[i] - 1;
                else t ^= a[i] - a[i - 1] - 1;
            }
        }
        else {
            for (int i = 1; i < n; i += 2) {
                t ^= a[i] - a[i - 1] - 1;
            }
        }
        if (t == 0) puts("Bob will win");
        else puts("Georgia will win");
    }
    return 0;
}
