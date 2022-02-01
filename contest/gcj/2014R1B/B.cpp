#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;
ll f[32][8];
ll A, B, K;

ll gao(int i, int mask) {
    if (i < 0) return 1;
    ll &res = f[i][mask];
    if (res != -1) return res;
    res = 0;
    rep (j, 2) rep (k, 2) {
        if ((mask & 1) && !(A & 1 << i) && j) continue;
        if ((mask & 2) && !(B & 1 << i) && k) continue;
        if ((mask & 4) && !(K & 1 << i) && j && k) continue;
        int tmp = 0;
        tmp |= ((mask & 4) && (j && k) == !!(K & 1 << i)) << 2;
        tmp |= ((mask & 2) && k == !!(B & 1 << i)) << 1;
        tmp |= ((mask & 1) && j == !!(A & 1 << i)) << 0;
        res += gao(i - 1, tmp);
    }
    return res;
}

int main() {
    int Tc;
    cin >> Tc;
    rep (ri, Tc) {
        printf("Case #%d: ", ri + 1);
        cin >> A >> B >> K;
        A--; B--; K--;
        memset(f, 0xff, sizeof(f));
        cout << gao(31, 7) << endl;
    }
}

