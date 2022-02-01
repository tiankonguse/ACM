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
bitset <40000005> s;

int main() {
    s.reset();
    int n;
    cin >> n;
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    int nxt = 3;
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if (i == nxt) {
            ans += 8;
            s.set(nxt);
            ++idx;
            if (s.test(idx))
                nxt += 3;
            else
                nxt += 2;
        } else {
            ans += 4;
        }
    }
    cout << ans << endl;
}

