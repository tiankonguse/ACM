/*
 * 396D.cpp
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
const int N = 1000005;
const int Mod = 1000000007;
int n;
int a[N], Tr[N];
int f[N], fac[N];

void add(int i, int x) {
    i++;
    for (; i < N; i += i & -i)
        Tr[i] += x;
}

int get(int i) {
    i++;
    int res = 0;
    for (; i; i -= i & -i)
        res += Tr[i];
    return res;
}

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", &a[i]);
    fac[0] = fac[1] = 1;
    f[0] = 0;
    f[1] = 0;
    for (int i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * (ll)i % Mod;
        f[i] = (ll)(i) * f[i - 1] % Mod + i * (ll)(i - 1) / 2 % Mod * (ll)fac[i - 1] % Mod;
        f[i] %= Mod;
    }
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        int v = a[i - 1];
        ll idx = v - get(v);
        idx--;
        ans += f[n - i] * idx % Mod + idx * (idx - 1) / 2 % Mod * (ll)fac[n - i] % Mod;
        ans %= Mod;
        ans += sum * fac[n - i] % Mod * idx % Mod;
        ans %= Mod;
        sum += v - 1 - get(v);
        sum %= Mod;
        add(v, 1);
    }
    ans += sum;
    ans %= Mod;
    cout << ans << endl;
}

