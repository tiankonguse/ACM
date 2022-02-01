#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 1000100
#define maxm 1000100
using namespace std;

char res[maxn];
int mx;

int st[maxn];
bool used[maxn];
int cur[maxn];

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
        res[top] = u % 10 + '0';
        if (top == mx) return;
        for (it = cur[u]; it < 10; ++it) {
            v = (u * 10 + it) % mx;
            if (!used[v]) {
                st[++top] = v;
                cur[u] = it + 1;
                break;
            }
        }

        if (it == 10) {
//            for (int i = 0; i < 10; ++i) {
//                v = (u * 10 + i) % mx;
//                if (!used[v]) {
//                    cur[v] = 0;
//                }
//            }
            cur[u] = 0;
            used[u] = false;
            --top;
        }
    }
}


void cal(int n) {
    mx = 1;

    for (int i = 0; i < n; ++i) mx *= 10;

    memset(used, false, sizeof used);

    dfs();
    for (int i = 0; i < n - 1; ++i) putchar('0');
    res[mx + 1] = 0;
    puts(res + 1);
}
int main() {
    int n;
    while (scanf("%d", &n) && n) {
        cal(n);
    }
    return 0;
}
