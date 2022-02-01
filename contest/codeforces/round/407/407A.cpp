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
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;

int a, b;

int toInt(double x) {
    int tmp = (int)(x) - 2;
    while (fabs(tmp + 1 - x) < fabs(tmp - x)) tmp++;
    return tmp;
}

bool isInteger(double x) {
    return (fabs(toInt(x) - x) < 1e-6);
}

int main() {
    cin >> a >> b;
    for (int i = 1; i < a; i++) {
        int x = i;
        int y = sqrt(a * a - i * i) + 0.5;
        if (x * x + y * y == a * a) {
            double tx = -y, ty = x;
            tx *= b / (double)a;
            ty *= b / (double)a;
            if (isInteger(tx) && isInteger(ty)) {
                if (y == toInt(ty)) continue;
                puts("YES");
                printf("%d %d\n", 0, 0);
                printf("%d %d\n", x, y);
                printf("%d %d\n", toInt(tx), toInt(ty));
                return 0;
            }
        }
    }
    puts("NO");
}

