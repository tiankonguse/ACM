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
const int N = 205;
int n, m;
int a[N];

int main() {
    scanf("%d%d", &n, &m);
    rep (i, n) {
        scanf("%d", &a[i]);
    }
    int ans = -1e9;
    rep (i, n) {
        vector <int> b, c;
        int sum = 0;
        for (int j = i; j < n; j++) {
            b.push_back(a[j]);
            sum += a[j];
            sort(b.begin(), b.end());
            c.clear();
            rep (k, n) {
                if (k < i || k > j) {
                    c.push_back(a[k]);
                }
            }
            sort(c.begin(), c.end());
            reverse(c.begin(), c.end());
            int tmp = sum;
            rep (k, min(min(c.size(), b.size()), (size_t)m)) {
                if (c[k] > b[k]) {
                    tmp += c[k] - b[k];
                }
            }
            if (tmp > ans) ans = tmp;
        }
    }
    printf("%d\n", ans);
}

