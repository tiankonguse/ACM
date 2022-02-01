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
#define maxn 205
#define maxi 10010
using namespace std;
int L[maxi],R[maxi],U[maxi],D[maxi],C[maxi];
int S[maxn];
int idx, K;

struct node {
    int x, y, l, d;
    node (int _x, int _y, int _l, int _d) { x = _x, y = _y, l = _l, d = _d; }
    node () {}
} O[maxi], W[maxi];

void remove(int c){
    for(int i=D[c];i!=c;i=D[i]){
        for(int j=R[i];j!=i;j=R[j]){
            U[D[j]]=U[j];
            D[U[j]]=D[j];
            S[C[j]]--;
        }
    }
    L[R[c]]=L[c];
    R[L[c]]=R[c];
}
void resume(int c){
    L[R[c]]=R[L[c]]=c;
    for(int i=U[c];i!=c;i=U[i]){
        for(int j=L[i];j!=i;j=L[j]){
            U[D[j]]=D[U[j]]=j;
            S[C[j]]++;
        }
    }
}
bool dfs(){
    if(R[0]==0) {
        return true;
    }
    int s(inf),c;
    for(int i=R[0];i!=0;i=R[i]){
        if(S[i]<s){
            s=S[i];
            c=i;
        }
    }
    remove(c);
    for(int i=D[c];i!=c;i=D[i]){
        O[K]=W[i];
        for(int j=R[i];j!=i;j=R[j]){
            remove(C[j]);
        }
        K++;
        if (dfs()) return true;
        K--;
        for(int j=L[i];j!=i;j=L[j]){
            resume(C[j]);
        }
    }
    resume(c);
    return false;
}


int arr[10];
void init(int len) {
    idx = 0;
    for(int i=0;i<=len;i++){
        L[idx]=idx-1;
        R[idx]=idx+1;
        U[idx]=D[idx]=idx;
        idx++;
    }
    L[0]=idx-1;
    R[idx-1]=0;
}
char mat[44][44];


int main() {
    int n, m, k;
    int s, a, x, y, id;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        memset(S, 0, sizeof S);
        idx = 0;
        for (int i = 0; i < k; ++i) {
            scanf("%d", &arr[i]);
        }
        int len = n * m;
        init(len);
        for (int _t = 0; _t < k; ++_t) {
            //h
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j + arr[_t] <= m; ++j) {
                    s = idx;
                    L[idx] = R[idx] = s;
                    for (int l = 0; l < arr[_t]; ++l) {
                        x = i, y = j + l;
                        id = x * m + y + 1;
                        a = id; S[a]++;
                        W[idx] = node(i, j, arr[_t], 0);
                        C[idx]=a;U[idx]=U[a];D[idx]=a;D[U[a]]=idx;
                        U[a]=idx;L[idx]=L[s];R[idx]=s;R[L[s]]=idx;L[s]=idx;
                        idx++;
                    }
                }
            }
            //v
            for (int i = 0; i < m; ++i) {
               for (int j = 0; j + arr[_t] <= n; ++j) {
                    s = idx;
                    L[idx] = R[idx] = s;
                    for (int l = 0; l < arr[_t]; ++l) {
                        x = j + l, y = i;
                        id = x * m + y + 1;
                        a = id; S[a]++;
                        W[idx] = node(j, i, arr[_t], 1);
                        C[idx]=a;U[idx]=U[a];D[idx]=a;D[U[a]]=idx;
                        U[a]=idx;L[idx]=L[s];R[idx]=s;R[L[s]]=idx;L[s]=idx;
                        idx++;
                    }
                } 
            }
        }

        K = 0;
        bool flag = dfs();
        if (!flag) puts("NO");
        else {
            char ch = 'a';
            for (int i = 0; i < K; ++i) {
                x = O[i].x, y = O[i].y;
                for (int j = 0; j < O[i].l; ++j) {
                    mat[x][y] = ch;
                    if (O[i].d == 0) ++y;
                    else ++x;
                }
                ch++;
                if (ch > 'z') ch = 'a';
            }
            puts("YES");
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    putchar(mat[i][j]);
                }
                puts("");
            }
        }
    }
    return 0;
}
