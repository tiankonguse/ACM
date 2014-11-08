/*
 * E.cpp
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
#include <cmath>
#include <iomanip>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
typedef pair <double, double> PDD;
const int N = 1005;
const double pi = acos(-1.0);
int n;
struct Node {
    double x, y;
    int id;
}a[N];

bool cmp(Node a, Node b) {
    return a.x < b.x;
}

double getAngle(double x[], double y[], double z[]) {
    double dot = x[0] * x[1] + y[0] * y[1] + z[0] * z[1];
    return acos(dot);
}

int curi;

double dist(Node a, Node b) {
    double a1 = a.y;
    double b1 = a.x;
    double a2 = b.y;
    double b2 = b.x;
    return 6371 * acos( cos(b1)*cos(b2)*cos(a1-a2)+sin(b1)*sin(b2) );
    double x[2], y[2], z[2];
    x[0] = sin(a.x) * cos(a.y);
    y[0] = sin(a.x) * sin(a.y);
    z[0] = cos(a.x);
    x[1] = sin(b.x) * cos(b.y);
    y[1] = sin(b.x) * sin(b.y);
    z[1] = cos(b.x);
    double angle = getAngle(x, y, z);
    double d;
    if (a.y <= b.y)
        d = b.y - a.y;
    else
        d = b.y - a.y + 2 * pi;
    //if (curi == 5) angle = 2 * pi - angle;
    return angle * 6371;
}

int main() {
    cin >> n;
    rep (i, n) {
        cin >> a[i].x >> a[i].y;
        a[i].x = a[i].x / 180 * pi;
        a[i].y = a[i].y / 180 * pi;
//        a[i].x = pi / 2 - a[i].x;
        a[i].id = i;
    }
    //sort(a, a + n, cmp);
    a[n] = a[0];
    double ans = 0;
    vector <int> v;
    v.push_back(a[n].id);
    rep (i, n) {
        curi = i;
        ans += dist(a[i + 1], a[i]);
        v.push_back(a[i + 1].id);
    }
    cout << fixed << setprecision(6) << ans << endl;
    rep (i, v.size()) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << endl;
    return 0;
}

