/*
 * 392A.cpp
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

int n;

bool inRange(ll x, ll y) {
    return x * x + y * y <= n * (ll)n;
}

int main() {
    int pre = 0;
    for (n = 1; n <= 200; n++) {
        int cnt = 0;
        for (int i = -n - 1; i <= n + 1; i++) {
            for (int j = -n - 1; j <= n + 1; j++) {
                if (inRange(i, j)) {
                    if (!inRange(i, j + 1) || !inRange(i, j - 1) || !inRange(i - 1, j) || !inRange(i + 1, j)) {
                        cnt++;
                    }
                }
            }
        }
        int cnt2 = 0;
        for (int i = -n - 1; i <= n + 1; i++) {
            for (int j = -n - 1; j <= n + 1; j++) {
                if (!inRange(i, j)) {
                    if (inRange(i, j + 1) || inRange(i, j - 1) || inRange(i - 1, j) || inRange(i + 1, j)) {
                        cnt2++;
                    }
                }
            }
        }
        //if (cnt - pre != 4)
        cout << n << ", " << cnt << ", " << cnt2 << endl;
        pre = cnt;
    }
}

