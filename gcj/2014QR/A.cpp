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
#include <cassert>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 4;
int a[N][N], b[N][N], c, d;

int getRow(int (&a)[N][N], int x) {
    rep (i, 4) rep (j, 4)
        if (a[i][j] == x)
            return i;
    assert(0);
}

int main() {
    int Tc;
    scanf("%d", &Tc);
    rep (_, Tc) {
        printf("Case #%d: ", _ + 1);
        scanf("%d", &c);
        rep (i, 4) rep (j, 4) scanf("%d", &a[i][j]);
        scanf("%d", &d);
        rep (i, 4) rep (j, 4) scanf("%d", &b[i][j]);
        c--; d--;
        vector <int> ans;
        rep (i, 16) {
            int x = i + 1;
            if (getRow(a, x) == c && getRow(b, x) == d) {
                ans.push_back(x);
            }
        }
        if (ans.empty()) {
            printf("Volunteer cheated!\n");
        } else if (ans.size() > 1) {
            printf("Bad magician!\n");
        } else {
            printf("%d\n", ans[0]);
        }
    }
}

