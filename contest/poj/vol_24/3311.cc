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
#define maxn 11
using namespace std;
int mp[maxn][maxn];
int arr[maxn];
int main() {
    int n;
    while (scanf("%d", &n) && n) {
        ++n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &mp[i][j]);
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (k == i || i == j || j == k) continue;
                    mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) arr[i] = i;
        int ret = inf;
        do {
            int t = 0, p = 0;
            for (int i = 0; i < n; ++i) {
                t += mp[p][arr[i]];
                p = arr[i];
            }
            t += mp[p][0];
            ret = min(ret, t);
        } while (next_permutation(arr, arr + n));
        printf("%d\n", ret);
    }
    return 0;
}
