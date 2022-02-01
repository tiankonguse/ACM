#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 1050000;
int F(int x, int n) {
    return (((x & ((1 << (n / 2)) - 1)) << ((n + 1) / 2)) | (x >> (n / 2)));
}
void pr(int x, int n) {
	for (int i = n - 1; i >= 0; --i) printf("%d", x >> i & 1); putchar(' ');
}

char res[N];
int mx;
int st[N];
bool used[N];
int cur[N];

void dfs() {
    int top;
    st[top = 1] = 0;
    used[0] = true;
    res[0] = 0;
    for (int i = 0; i < mx; ++i) cur[i] = 0;

    int it, u, v;
    while (top > 0) {
        u = st[top];
        used[u] = true;
        res[top] = u % 2 + '0';
        if (top == mx) return;
        for (it = cur[u]; it < 2; ++it) {
            v = (u * 2 + it) % mx;
            if (!used[v]) {
                st[++top] = v;
                cur[u] = it + 1;
                break;
            }
        }

        if (it == 2) {
            cur[u] = 0;
            used[u] = false;
            --top;
        }
    }
}


void cal(int n) {
	mx = 1 << n;
	clr(used, 0);
    dfs();
    for (int i = 0; i < n - 1; ++i) putchar('0');
    res[mx + 1] = 0;
    puts(res + 1);
}

int main() {
	//rep(i, 5) {
		//rep(j, 1 << i) cout<<F(j,i)<<" ";//pr(F(j, i), i);
		//cout << endl;
	//}
	int n;
	while (~scanf("%d", &n)) {
		cal(n);
	}
	return 0;
}

