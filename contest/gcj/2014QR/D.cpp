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
const int N = 1005;
int Tc, n;
double a[N], b[N];

int main() {
    cin >> Tc;
    rep (ri, Tc) {
        printf("Case #%d: ", ri + 1);
        cin >> n;
        rep (i, n) cin >> a[i];
        rep (i, n) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        int ans = 0;
        int st = 0;
        for (int i = n - 1, j = n - 1; i >= st;) {
            if (a[i] > b[j]) {
                ans++;
                i--;
                j--;
            } else {
                j--;
                st++;
            }
        }
        printf("%d ", ans);
        ans = n;
        int j = 0;
        rep (i, n) {
            while (j < n && a[i] >= b[j]) j++;
            if (j < n) {
                ans--;
                j++;
            }
        }
        printf("%d\n", ans);
    }
}

