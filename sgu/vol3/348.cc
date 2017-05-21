#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 70
using namespace std;
typedef __int64 ll;
int num[maxn];
int tmp[maxn];

bool check(int a[], int len) {
    ll t;
    ll r = 0;
    for (int i = 0; i < len; ++i) {
        r = r << 1LL | a[i];
    }
    ll mi = r;
    for (int i = 1; i < len; ++i) {
        if (a[i] == 1) {
            t = 0;
            for (int j = 0; j < len; ++j) {
                t = t << 1LL | a[(i + j) % len];
            }
            mi = min(mi, t);
        }
    }
    return r == mi;
}

int main() {
    ll n;

    while (cin >> n) {
        int len = 0;
        ll s = n;
        while (s) {
            tmp[len++] = s % 2;
            s >>= 1;
        }
        for (int i = 0; i < len; ++i) {
            num[i] = tmp[len - i - 1];
        }
        if (check(num, len)) cout << n << endl;
        else {
            ll ret;
            for (int i = len - 1; i > 0; --i) {
                if (num[i] == 1) {
                    memcpy(tmp, num, sizeof num);
                    tmp[i] = 0;
                    for (int j = i + 1; j < len; ++j) tmp[j] = 1;
                    if (check(tmp, len)) {
                        ret = 0;
                        for (int j = 0; j < len; ++j) {
                            ret =  ret << 1LL | tmp[j];
                        }
                        break;
                    }
                }
            }
            cout << ret << endl;
        }
    }
    return 0;
}

