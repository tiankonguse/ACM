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
#define maxn 325
#define maxi 236197
using namespace std;
int const _col = 324;
int const _row = 729;

int L[maxi], R[maxi], U[maxi], D[maxi], C[maxi], W[maxi];
int S[maxn], I[maxn], O[81];
int n, m;
int K, idx;
bool h[maxn];
char mp[10][10];
void remove(int c) {
    for (int i = D[c]; i != c; i = D[i]) {
        for (int j = R[i]; j != i; j = R[j]) {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            S[C[j]]--;
        }
    }
    L[R[c]] = L[c];
    R[L[c]] = R[c];
}
void resume(int c) {
    L[R[c]] = R[L[c]] = c;
    for (int i = U[c]; i != c; i = U[i]) {
        for (int j = L[i]; j != i; j = L[j]) {
            U[D[j]] = D[U[j]] = j;
            S[C[j]]++;
        }
    }
}
bool dfs() {
    if (R[0] == 0) return true;
    int s(inf), c;
    for (int i = R[0]; i != 0; i = R[i]) {
        if (S[i] < s) {
            s = S[i];
            c = i;
        }
    }
    remove(c);
    for (int i = D[c]; i != c; i = D[i]) {
        O[K] = W[i];
        for (int j = R[i]; j != i; j = R[j]) {
            remove(C[j]);
        }
        K++;
        if (dfs()) return true;
        K--;
        for (int j = L[i]; j != i; j = L[j]) {
            resume(C[j]);
        }
    }
    resume(c);
    return false;
}

int num[4];
inline void addLine(int c, int len) {
    for (int i = 0; i < len; ++i) if (num[i] == -1) return;
    int s = idx, a;
    L[s] = R[s] = s;
    for (int i = 0; i < len; ++i) {
        a = num[i]; ++S[a];
        W[idx] = c; // record the answer
        C[idx] = a;
        U[idx] = U[a]; D[idx] = a; D[U[a]] = idx; U[a] = idx;
        L[idx] = L[s]; R[idx] = s; R[L[s]] = idx; L[s] = idx;
        ++idx;
    }
}
void init() {
    memset(S, 0, sizeof S);
    memset(h, 0, sizeof h);
    memset(I, 0xff, sizeof I);
    //mark the existed states
    int d;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (mp[i][j] != '0') {
                d = mp[i][j] - '0';
                h[i * 9 + j + 1] = true;
                h[81 + i * 9 + d] = true;
                h[162 + j * 9 + d] = true;
                h[243 + (i / 3 * 3 + j / 3) * 9 + d] = true;
            }
        }
    }
    idx = 0;
    for (int i = 0; i <= _col; ++i) {
        if (h[i]) continue;
        L[idx] = idx - 1;
        R[idx] = idx + 1;
        U[idx] = D[idx] = idx;
        I[i] = idx;
        ++idx;
    }
    L[0] = idx - 1;
    R[idx - 1] = 0;
    //build
    int x, y;
    for (int i = 1; i <= 729; ++i) {
        d = i % 9; if (d == 0) d = 9;
        y = (i - d) % 81 / 9;
        x = (i - d - 9 * y) / 81;
        num[0] = I[x * 9 + y + 1];
        num[1] = I[81 + x * 9 + d];
        num[2] = I[162 + y * 9 + d];
        num[3] = I[243 + (x / 3 * 3 + y / 3) * 9 + d];
        addLine(i, 4);
    }

}
int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        for (int i = 0; i < 9; ++i) scanf(" %s", mp[i]);
        init();
        K = 0;
        dfs();
        int d, x, y;
        for (int i = 0; i < K; ++i) {
            int j = O[i];
            d = j % 9; if (d == 0) d = 9;
            y = (j - d) % 81 / 9;
            x = (j - d - 9 * y) / 81;
            mp[x][y] = '0' + d;
        }
        for (int i = 0; i < 9; ++i) puts(mp[i]);
    }
    return 0;
}
