#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 405;
int n, m;
int a[N][N];
short f[400][400][400];
int tag[160000];
int idx[160000];

short access(int x, int t) {
    return tag[x] == t ? idx[x] : n;
}

void modify(int x, int v, int t) {
    tag[x] = t;
    idx[x] = v;
}

int main() {
    scanf("%d%d", &m, &n);
    rep (i, m) rep (j, n) {
        scanf("%d", &a[i][j]);
        a[i][j]--;
    }
    int ans = 0;
    rep (d, m) {
        rep (i, m - d) {
            int j = i + d;
            int curTag = i * m + j + 1;
            for (int k = n - 1; k >= 0; k--) {
                short &e = f[i][j][k];
                e = n;
                if (i < j) {
                    e = min(e, f[i][j - 1][k]);
                    e = min(e, f[i + 1][j][k]);
                    if (a[j][k] == a[i][k]) e = k;
                }
                if (k + 1 < n) {
                    e = min(e, f[i][j][k + 1]);
                }
                e = min(e, access(a[i][k], curTag));
                e = min(e, access(a[j][k], curTag));
                modify(a[i][k], k, curTag);
                modify(a[j][k], k, curTag);
                if ((d + 1) * (e - k) > ans) {
                    ans = (d + 1) * (e - k);
                    //cout << i << ", " << j << "," << k << " = " << f[i][j][k] << endl;
                }
            }
        }
    }
    printf("%d\n", ans);
}

