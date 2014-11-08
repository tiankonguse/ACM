#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 100005;
const int Mod = 1e9 + 7;
int n;
int main() {
    scanf("%d", &n);
    rep (i, 1000000000) n += n;
    cout << n << "\n";
}
