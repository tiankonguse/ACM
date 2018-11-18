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
const int N = 100005;
int n;
PII a[N];
vector <PII> row[N], col[N], cross[N + N];

bool ok(int len, const PII &p, vector <PII> &u, vector <PII> &v, vector <PII> &w, int o) {
    if (o != 0 && !binary_search(u.begin(), u.end(), PII(p.first, p.second - len))) return 0;
    if (o != 1 && !binary_search(v.begin(), v.end(), PII(p.first - len, p.second))) return 0;
    if (o != 2 && !binary_search(w.begin(), w.end(), PII(p.first - len, p.second - len))) return 0;
    return 1;
}

int main() {
    scanf("%d", &n);
    rep (i, n) {
        scanf("%d%d", &a[i].first, &a[i].second);
        row[a[i].first].push_back(a[i]);
        col[a[i].second].push_back(a[i]);
        cross[a[i].first - a[i].second + N].push_back(a[i]);
    }
    rep (i, N) {
        sort(row[i].begin(), row[i].end());
        sort(col[i].begin(), col[i].end());
    }
    rep (i, N + N) {
        sort(cross[i].begin(), cross[i].end());
    }
    int ans = 0;
    rep (i, n) {
        vector <PII> &u = row[a[i].first];
        vector <PII> &v = col[a[i].second];
        vector <PII> &w = cross[a[i].first - a[i].second + N];
        int usz = lower_bound(u.begin(), u.end(), a[i]) - u.begin();
        int vsz = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        int wsz = lower_bound(w.begin(), w.end(), a[i]) - w.begin();
        if (usz <= vsz && usz <= wsz) {
            rep (j, usz) {
                int len = a[i].second - u[j].second;
                if (ok(len, a[i], u, v, w, 0)) ans++;
            }
        } else if (vsz <= usz && vsz <= wsz) {
            rep (j, vsz) {
                int len = a[i].first - v[j].first;
                if (ok(len, a[i], u, v, w, 1)) ans++;
            }
        } else {
            rep (j, wsz) {
                int len = a[i].first - w[j].first;
                if (ok(len, a[i], u, v, w, 2)) ans++;
            }
        }
    }
    printf("%d\n", ans);
}

