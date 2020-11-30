/*
 * 406B.cpp
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
const int N = 1000001;
int n, x[N];

int main() {
    scanf("%d", &n);
    int cnt = 0;
    rep (i, n) {
        int v;
        scanf("%d", &v);
        x[v] = 1;
        if (x[N - v]) cnt++;
    }
    printf("%d\n", n);
    for (int i = 1; i < N; i++) {
        if (x[i] && !x[N - i]) {
            printf("%d ", N - i);
        } else if (!x[i] && !x[N - i] && cnt) {
            cnt--;
            printf("%d %d ", i, N - i);
        }
    }
    puts("");
}

