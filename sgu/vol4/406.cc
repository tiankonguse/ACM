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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 11
#define maxm 111
using namespace std;
int arr[maxn][maxm]; int ant[maxn];
int num[maxn][maxm];
int tmp[maxn][maxm];
bool mark[maxn];

int main() {
    int n, m;
    int k, a;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &ant[i]);
            for (int j = 0; j < ant[i]; ++j) {
                scanf("%d", &arr[i][j]);
                ++num[i][arr[i][j]];
            }
        }
        while (m--) {
            memset(mark, false, sizeof mark);
            memcpy(tmp, num, sizeof num);
            scanf("%d", &k);
            for (int i = 0; i < k; ++i) {
                scanf("%d", &a);
                if (a < 0) {
                    for (int j = 0; j < n; ++j) {
                        if (tmp[j][-a] != 0) mark[j] = true;
                    }
                }
                else {
                    for (int j = 0; j < n; ++j) {
                        if (tmp[j][a] == 0) mark[j] = true;
                        --tmp[j][a];
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; ++i) if (!mark[i]) ++cnt;
            printf("%d\n", cnt);
            for (int i = 0; i < n; ++i) {
                if (!mark[i]) {
                    printf("%d", ant[i]);
                    for (int j = 0; j < ant[i]; ++j) {
                        printf(" %d", arr[i][j]);
                    }
                    puts("");
                }
            }
        }
    }
    return 0;
}
