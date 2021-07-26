/*************************************************************************
    > File Name: E003.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/14 22:51:56
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;


int n, m, uN, vN;
bool mp[MAXN][26];
bool g[MAXN][MAXN];
char bottom[1005];
int xM[MAXN], yM[MAXN];
bool chk[MAXN];

bool searchPath(int u) {
    int v;
    for(v = 0; v < vN; v++)
        if(g[u][v] && !chk[v]) {
            chk[v] = true;
            if(yM[v] == -1 || searchPath(yM[v])) {
                yM[v] = u;
                xM[u] = v;
                return true;
            }
        }
    return false;
}

int MaxMatch() {
    int u, ret = 0;
    memset(xM, -1, sizeof(xM));
    memset(yM, -1, sizeof(yM));
    for(u = 0; u < uN; u++)
        if(xM[u] == -1) {
            memset(chk, false, sizeof(chk));
            if(searchPath(u)) ret++;
        }
    return ret;
}

int main() {
    int cas, i, j, k, sum, d;

    scanf("%d", &cas);
    while(cas--) {
        memset(mp, 0, sizeof(mp));
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++) {
            scanf("%s", ip);
            for(j = 0; ip[j]; j++)
                mp[i][ip[j]-'A'] = 1;
        }
        sum = 0;
        vN = n;
        for(i = 0; i < m; i++) {
            memset(g, 0, sizeof(g));
            scanf("%s", bottom);
            for(j = 0; ip[j]; j++)
                for(k = 0; k < n; k++)
                    if(mp[k][bottom[j]-'A'])
                        g[j][k] = 1;
            uN = strlen(ip);
            if(MaxMatch() == uN)
                sum++;
        }

        printf("%d\n", sum);
    }
    return 0;
}

