/*
 * 403B.cpp
 * 
 * Copyright edward_mj
 * 
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 5005;
int n, m;
int a[N];
int g[N];
unordered_set <int> s;
bool isP[32005];
vector <int> pr;

int calcv(int x) {
    int res = 0;
    rep (i, pr.size()) {
        int u = pr[i];
        if (u * u > x) break;
        int cnt = 0;
        while (x % u == 0) {
            x /= u;
            cnt++;
        }
        if (s.count(u)) 
            res -= cnt;
        else
            res += cnt;
    }
    if (x != 1) {
        if (s.count(x))
            res--;
        else
            res++;
    }
    return res;
}

int main() {
    memset(isP, 1, sizeof(isP));
    isP[0] = isP[1] = 0;
    for (int i = 2; i <= 32000; i++)
        for (int j = 2; i * j <= 32000; j++)
            isP[i * j] = 0;
    for (int i = 2; i <= 32000; i++)
        if (isP[i])
            pr.push_back(i);
    scanf("%d%d", &n, &m);
    rep (i, n) scanf("%d", &a[i]);
    rep (i, m) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    ll ans = 0;
    rep (i, n) {
        if (i) {
            g[i] = __gcd(g[i - 1], a[i]);
        } else {
            g[i] = a[i];
        }
        ans += calcv(a[i]);
    }
    //cout << ans << endl;
    int d = 1;
    for (int i = n - 1; i >= 0; i--) {
        g[i] /= d;
        int tmp = calcv(g[i]);
        if (tmp < 0) {
            ans -= tmp * (i + 1);
            d *= g[i];
        }
    }
    cout << ans << endl;
}

