/*
 * 396B.cpp
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
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef std::pair <ll, ll> PII;

//(nxt * nxt2 - pre * nxt2) / (nxt * pre * nxt2) + (nxt2 * pre - nxt * pre) / (pre * nxt2 * nxt)
//(nxt2 - pre) / (pre * nxt2)

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int getPrev(int n) {
    while (!isPrime(n)) n--;
    return n;
}

int getNext(int n) {
    ++n;
    while (!isPrime(n)) n++;
    return n;
}

void fix(ll &u, ll &d) {
    if (u == 0) {
        d = 1;
    } else {
        ll g = std::__gcd(u, d);
        u /= g;
        d /= g;
    }
}

PII add(ll u0, ll d0, ll u1, ll d1) {
    fix(u0, d0);
    fix(u1, d1);
    ll g = std::__gcd(d0, d1);
    PII res = PII(u0 * (d1 / g) + u1 * (d0 / g), d0 / g * d1);
    fix(res.first, res.second);
    return res;
}

int main() {
    int Tc;
    scanf("%d", &Tc);
    rep (_, Tc) {
        int n;
        scanf("%d", &n);
        int prev = getPrev(n);
        int next = getNext(n);
        ll u, d;
        u = prev - 2;
        d = prev * 2;
        PII res = add(u, d, n + 1 - prev, prev * (ll)next);
        std::cout << res.first << "/" << res.second << std::endl;
    }
}

