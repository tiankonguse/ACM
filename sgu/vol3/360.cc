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
#define maxn 55
#define maxm 1010
#define maxs 10100
using namespace std;
char mp[maxn][maxn];
char dat[maxs];
map<char, int> fmp, mpf[maxn]; int fid;
vector<char> fun[maxn];
char oplist[maxm]; int ont;

void dfs(int f_id, vector<char> prs) {
    int len = fun[f_id].size();
    char ch;
    int tid; vector<char> tv;

    for (int i = 0; i < len && ont < 1000; ++i) {
        if (fun[f_id][i] == 'L' || fun[f_id][i] == 'R' || fun[f_id][i] == 'C') {
            oplist[ont++] = fun[f_id][i];
            if (ont >= 1000) return;
        }
        else if (fun[f_id][i] >= 'A' && fun[f_id][i] <= 'Z') {
            oplist[ont++] = prs[ mpf[f_id][fun[f_id][i]] ];
            if (ont >= 1000) return;
        }
        else {
            ch = 0;
            while (fun[f_id][i] != '(') ch = fun[f_id][i++]; ++i;
            tid = fmp[ch];
            tv.clear();
            ch = 0;
            while (fun[f_id][i] != ')') {
                if (fun[f_id][i] == ',') {
                    if (ch == 'L' || ch == 'R' || ch == 'C') tv.push_back(ch);
                    else tv.push_back(prs[ mpf[f_id][ch] ]);
                }
                else ch = fun[f_id][i];
                ++i;
            }
            if (ch == 'L' || ch == 'R' || ch == 'C') tv.push_back(ch);
            else if (ch != 0) tv.push_back(prs[ mpf[f_id][ch] ]);
            dfs(tid, tv);
        }
    }
}

int n, m;
int const dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
inline bool check(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
bool mark[maxn][maxn];
int trea[maxn * maxn][2], tnt;


int main() {
    int idx; char buf;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf(" %s", mp[i]);
        }
        idx = 0;
        while((buf = getchar()) != EOF) {
            if (buf != ' ' && buf != '\n') dat[idx++] = buf;
        }
        fid = 0;
        char ch;
        fmp.clear();
        int tid;
        for (int i = 0; i < idx; ++i) {
            if (dat[i] != 'L' && dat[i] != 'R' && dat[i] != 'C') {
                ch = 0;
                while (dat[i] != '(') ch = dat[i++];++i;
                    fmp[ch] = fid++;
                tid = fmp[ch];
                mpf[tid].clear();
                int cnt = 0;
                ch = 0;
                while (dat[i] != ')') {
                    if (dat[i] == ',') {
                        mpf[tid][ch] = cnt++;
                    }
                    else ch = dat[i];
                    ++i;
                }
                if (ch != 0) mpf[tid][ch] = cnt++;
                while (dat[i] != '{') ++i; ++i;

                fun[tid].clear();
                while (dat[i] != '}') {
                    fun[tid].push_back( dat[i++] );
                }
            }
        }
        ont = 0;
        dfs(fmp['m'], vector<char>());
        int sx = -1, sy;
        for (int i = 0; i < n && sx == -1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 'R') {
                    sx = i, sy = j;
                    break;
                }
            }
        }
        int tx, ty, d = 0;
        tnt = 0; memset(mark, false, sizeof mark);
        for (int i = 0; i < ont; ++i) {
            if (oplist[i] == 'L') d = (d + 3) % 4;
            else if (oplist[i] == 'R') d = (d + 1) % 4;
            else {
                tx = sx + dir[d][0];
                ty = sy + dir[d][1];
                if (check(tx, ty)) {
                    sx = tx, sy = ty;
                    if (mp[tx][ty] == '*' && !mark[tx][ty]) {
                        mark[tx][ty] = true;
                        trea[tnt][0] = tx + 1;
                        trea[tnt][1] = ty + 1;
                        ++tnt;
                    }
                }

            }
        }
        printf("%d\n", tnt);
        for (int i = 0; i < tnt; ++i) {
            printf("%d %d\n", trea[i][0], trea[i][1]);
        }
    }
    return 0;
}

