/*
 * 403A.cpp
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
const int N = 25;
PII d[N];
int mat[N][N];

int main() {
    int Tc;
    scanf("%d", &Tc);
    while (Tc--) {
        int n, p;
        scanf("%d%d", &n, &p);
        memset(mat, 0, sizeof(mat));
        memset(d, 0, sizeof(d));
        int idx = 0;
        rep (i, n) d[i].second = i;
        rep (_, (2 * n + p) * 2) {
            d[idx++].first++;
            if (idx == n) idx = 0;
        }
        sort(d, d + n);
        for (int i = n - 1; i >= 0; i--) {
            sort(d, d + i);
            int j = i - 1;
            while (d[i].first) {
                printf("%d %d\n", d[j].second + 1, d[i].second + 1);
                d[i].first--;
                d[j].first--;
                j--;
            }
        }
    }
}

