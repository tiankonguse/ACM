/*
 * J.cpp
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
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 105;
struct State {
    ll sum;
    State *prev;
    vector <ll> v;
    
    State() {
        sum = 0;
        prev = NULL;
    }
    
    State(int n) {
        v = vector <ll> (n, 1);
        sum = n;
        prev = NULL;
    }
    
    State* append(int n) {
        int m = v.size();
        State &res = *(new State());
        vector <ll> &rv = res.v;
        rv = vector <ll> (n);
        ll s = 0, srv = 0;
        for (int i = m - 1; i >= 0; i--) {
            s += v[i];
            if (i < n) {
                rv[i] = s;
                srv += s;
            }
        }
        res.sum = srv + sum;
        res.prev = this;
        return &res;
    }
    
    bool operator < (const State &oth) const {
        if (sum > oth.sum) return 0;
        ll lhs = 0, rhs = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            lhs += v[i];
            rhs += oth.v[i];
            if (lhs > rhs) return 0;
        }
        return 1;
    }
};

int n;
vector <State*> f[N][N];

void update(vector <State*> &v, State *c) {
    bool flag = 1;
    rep (i, v.size()) {
        if (*v[i] < *c) {
            v.erase(v.begin() + i--);
        } else if (*c < *v[i]) {
            flag = 0;
            break;
        }
    }
    if (flag) v.push_back(c);
}

void output(int i, int j, State *s) {
    if (s->prev) {
        int ti = i - j, tj = s->prev->v.size();
        foreach (it, f[ti][tj]) {
            if ((*it)->v == s->prev->v) {
                output(ti, tj, *it);
                goto FINISH;
            }
        }
        assert(0);
    }
FINISH:;
    cout << j << " ";
}

void search() {
    State *rs;
    int ri, rj;
    ll ans = -1;
    for (int j = n; j >= 1; j--) {
        for (int i = j; i <= n; i++) {
    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= i; j++) {
            if (i == j) {
                f[i][j].push_back(new State(i));
            }
            vector <State*> &v = f[i][j];
            foreach (it, v) {
                for (int k = 1; i + k <= n && k <= j; k++) {
                    update(f[i + k][k], (*it)->append(k));
                }
                if (i == n && (*it)->sum > ans) {
                    ans = (*it)->sum;
                    ri = i;
                    rj = j;
                    rs = *it;
                }
            }
        }
    }
    cout << ans << endl;
    output(ri, rj, rs);
}

int main() {
    freopen("young.in", "r", stdin);
    //freopen("young.out", "w", stdout);
    cin >> n;
    search();
    return 0;
}

