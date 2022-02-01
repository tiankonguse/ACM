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
#define maxn 333
using namespace std;
int const dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int const dy[8] = {-1, 1, -2, 2, 2, -2, 1, -1};

int main() {
    int T, n, x1, y1, x2, y2;
    for (scanf("%d", &T); T--; ) {
        scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
        vector< pair<int, int> > v;
        static int D[maxn][maxn];
        memset(D, 0x3f, sizeof D);
        D[x1][y1] = 0;
        v.push_back( make_pair(x1, y1) );
        for (int i = 0; i < v.size(); ++i) {
            int x = v[i].first;
            int y = v[i].second;
            if (x == x2 && y == y2) {
                printf("%d\n", D[x][y]);
                break;
            }
            for (int j = 0; j < 8; ++j) {
                int tx = x + dx[j];
                int ty = y + dy[j];
                if (tx >= 0 && tx < n && ty >= 0 && ty < n && D[tx][ty] == inf) {
                    D[tx][ty] = D[x][y] + 1;
                    v.push_back( make_pair(tx, ty) );
                }
            }
        }
    }
    return 0;
}
