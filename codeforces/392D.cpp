/*
 * 392D.cpp
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
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 300005;
const int INF = 100000000;
int n, m;
int a[3][N];
int idx[3][N];

void init() {
    scanf("%d", &n);
    vector <int> c;
    rep (j, 3) rep (i, n) {
        scanf("%d", &a[j][i]);
        c.push_back(a[j][i]);
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    m = c.size();
    memset(idx, 0xff, sizeof(idx));
    rep (j, 3) rep (i, n) {
        int w = a[j][i] = lower_bound(c.begin(), c.end(), a[j][i]) - c.begin();
        if (idx[j][w] == -1) idx[j][w] = i;
    }
}

set <PII> s;
multiset <int> value;

void eraseV(int x) {
    value.erase(value.find(x));
}

void add(int x, int y) {
    pair <set<PII>::iterator, bool> res = s.insert(PII(x, y));
    if (!res.second) return;
    set <PII>::iterator it, it2;
    if (++(it = res.first) != s.end()) {
        if (it->second >= y) {
            s.erase(res.first);
            return;
        }
    }
    it2 = it = res.first;
    if (++it2 != s.end()) {
        if (it == s.begin()) {
            eraseV(it2->second);
        } else {
            --it;
            eraseV(it->first + it2->second);
        }
    }
    if (res.first != s.begin()) {
        it = res.first;
        --it;
        while (it->second <= y) {
            if (it == s.begin()) {
                eraseV(it->second);
                s.erase(it);
                break;
            } else {
                it2 = it;
                --it2;
                eraseV(it2->first + it->second);
                s.erase(it--);
            }
        }
    }
    if (res.first == s.begin()) {
        value.insert(y);
    } else {
        it = res.first;
        --it;
        value.insert(it->first + y);
    }
    it = res.first;
    ++it;
    if (it != s.end()) {
        value.insert(x + it->second);
    }
}

int getSum() {
    return *value.begin();
}

void addNumber(int x) {
    if (idx[1][x] == -1 && idx[2][x] == -1) {
        add(INF, INF);
    } else if (idx[1][x] == -1) {
        add(INF, idx[2][x] + 1);
    } else if (idx[2][x] == -1) {
        add(idx[1][x] + 1, INF);
    } else {
        add(idx[1][x] + 1, idx[2][x] + 1);
    }
}

int main() {
    init();
    int ans = INF;
    add(0, 0);
    rep (i, m)
        if (idx[0][i] == -1)
            addNumber(i);
    ans = min(ans, getSum() + n);
    for (int i = n - 1; i >= 0; i--) {
        if (idx[0][a[0][i]] == i)
            addNumber(a[0][i]);
        ans = min(ans, getSum() + i);
    }
    
    rep (i, m) swap(idx[1][i], idx[2][i]);
    s.clear();
    value.clear();
    add(0, 0);
    rep (i, m)
        if (idx[0][i] == -1)
            addNumber(i);
    ans = min(ans, getSum() + n);
    for (int i = n - 1; i >= 0; i--) {
        if (idx[0][a[0][i]] == i)
            addNumber(a[0][i]);
        ans = min(ans, getSum() + i);
    }
    cout << ans << endl;
    return 0;
}

