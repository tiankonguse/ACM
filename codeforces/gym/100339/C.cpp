/*
 * C.cpp
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
const int N = 10005;
set <int> os[N], xs[N];

int n;

void init() {
    int m;
    scanf("%d%d", &n, &m);
    rep (i, m) {
        int x, y, o;
        scanf("%d%d%d", &x, &y, &o);
        auto &s = o ? xs : os;
        
    }
}

int main() {
    freopen("hex.in", "r", stdin);
    freopen("hex.out", "w", stdout);
    init();
    return 0;    
}

