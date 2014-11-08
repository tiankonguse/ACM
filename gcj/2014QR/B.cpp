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
#include <cassert>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 100000000;
int Tc;

double C, F, X;

int main() {
    scanf("%d", &Tc);
    int cur = 0;
    rep (_, Tc) {
        printf("Case #%d: ", _ + 1);
        cin >> C >> F >> X;
        double ans = 1e100;
        double sum = 0;
        int mini = -1;
        rep (i, N) {
            if (sum + X / (2 + i * F) < ans) {
                ans = sum + X / (2 + i * F);
                mini = i;
            }
            sum += C / (2 + i * F);
        }
        fprintf(stderr, "%d\n", _ + 1);
        printf("%.7f\n", ans);
        cur = max(cur, mini);
    }
    fprintf(stderr, "%d\n", cur);
}

