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
const int Mod = 1000000007;
int n;
int a[N];
int f[N][N];

int rec(int i, int j) {
    if (i == j) return 0;
    int &res = f[i][j];
    if (res != -1) return res;
    return res = (rec(i, j - 1) + rec(a[j - 1], j - 1) + 2) % Mod;
}

int main() {
    scanf("%d", &n);
    rep (i, n) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    memset(f, 0xff, sizeof(f));
    cout << rec(0, n) << endl;
}