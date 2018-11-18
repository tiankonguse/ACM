#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair <int, int> PII;
int n, m;
int f[1005][1005];

int main() {
    memset(f, 0xff, sizeof(f));
    scanf("%d%d", &n, &m);
    f[n][0] = 0;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == -1) continue;
            
        }
    }
}