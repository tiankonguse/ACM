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
const int Mod = 1e9 + 7.5;
int Tc;
ll n;

ll powMod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return res;
}

ll all(ll n) {
    return n % Mod * (n + 1) % Mod * powMod(2, Mod - 2) % Mod;
}

int main() {
    cin >> Tc;
    rep (i, Tc) {
        cin >> n;
        //cout << all(n) << endl;
        ll sum = all(n) * all(n) % Mod * all(n) % Mod;
        for (int i = 1; i <= n; i++) {
            ll m = n + 1 - i;
            sum -= (m * m % Mod * (all(n) - m) % Mod) * 3;
        }
        sum %= Mod;
        sum += Mod;
        sum %= Mod;
        cout << "Case " << i + 1 << ": " << sum << "\n";
    }
}

