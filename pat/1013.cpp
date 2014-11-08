/*
 * 1013.cpp
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
const int N = 300000;
bitset <N + 5> v;
vector <int> a;

int main() {
    v.set();
    v.reset(1);
    v.reset(0);
    for (int i = 2; i < N; i++)
        for (int j = i + i; j <= N; j += i)
            v.reset(j);
    rep (i, N) if (v.test(i)) a.push_back(i);
    int cnt = 0;
    int l, r;
    scanf("%d%d", &l, &r);
    bool first = 0;
    for (int i = l; i <= r; i++) {
        if (!i) continue;
        ++cnt;
        if (first) {
            if (cnt == 11) {
                cnt = 1;
                printf("\n");
            } else {
                printf(" ");
            }
        }
        first = 1;
        printf("%d", a[i - 1]);
    }
    return 0;
}

