/*
 * 406A.cpp
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
const int N = 1005;
int n, ans;
int a[N][N];

int main() {
    int n;
    scanf("%d", &n);
    rep (i, n) rep (j, n) scanf("%d", &a[i][j]);
    int ans = 0;
    rep (i, n) {
        ans ^= a[i][i] & 1;
    }
    int Q;
    scanf("%d", &Q);
    rep (_, Q) {
        int t, i;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &i);
            ans ^= 1;
        } else if (t == 2) {
            scanf("%d", &i);
            ans ^= 1;
        } else {
            printf("%d", ans);
        }
    }
}

