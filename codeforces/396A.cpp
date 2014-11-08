/*
 * 396A.cpp
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
const int N = 505;
const int M = 14500;
const int Mod = 1000000007;
int n;
int a[N];
int f[N][14505];
map <int, int> mp;

void add(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            mp[i] += cnt;
        }
    }
    if (x != 1) mp[x]++;
}

void add(int &t, int x) {
    t += x;
    if (t >= Mod) t-= Mod;
}

void init() {
    f[0][0] = 1;
    rep (i, n) {
        int sum = 0;
        for (int j = 0; j <= M; j++) {
            add(sum, f[i][j]);
            f[i + 1][j] = sum;
        }
    }
}

int main() {
    scanf("%d", &n);
    rep (i, n) {
        scanf("%d", &a[i]);
        add(a[i]);
    }
    init();
    ll ans = 1;
    foreach (it, mp) {
        ans *= f[n][it->second];
        ans %= Mod;
    }
    cout << ans << endl;
    return 0;
}

