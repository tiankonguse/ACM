/*************************************************************************
    > File Name: Dancing_Links.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/22 21:38:40
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int maxn = 10000;
int R[maxn], L[maxn], U[maxn], D[maxn], col[maxn], row[maxn];
int S[maxn];
int NV,sz,pre,first;

void init(int n){
    for(int i=0;i<=n;i++){
        U[i] = i, D[i] = i, S[i] = 0;
        L[i] = i-1, R[i] = i+1;
    }
    NV = n, sz= n+1, pre = -1, first = 0;
}

void insert(int i, int j){
    if(i != pre){
        R[sz - 1] = first, L[first] = sz - 1;
        pre = i, first = sz;
    }

    D[U[j]] = sz, L[sz] = sz-1, R[sz] = sz+1;
    D[sz] = j, U[sz] = U[j], U[j] = sz;
    row[sz] = i, col[sz++] = j, S[j]++;
}

void remove(int &c) {
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for(int i = D[c]; i != c ; i = D[i]) {
        for(int j = R[i]; j != i ; j = R[j]) {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            --S[Col[j]];
        }
    }
}
void resume(int &c) {
    for(int i = U[c];i != c;i = U[i]) {
        for(int j = L[i]; j != i ; j = L[j]) {
            ++S[Col[j]];
            U[D[j]] = j;
            D[U[j]] = j;
        }
    }
    L[R[c]] = c;
    R[L[c]] = c;
}

bool dfs() {
    if(R[0] == 0) {
        return true;
    }
    int i , j;
    int idx,minnum = 999999;
    for(i = R[0];i != 0 ; i = R[i]) {
        if(S[i] < minnum) {
            minnum = S[i];
            idx = i;
        }
    }
    remove(idx);
    for(i = D[idx]; i != idx; i = D[i]) {
        ans[deep++] = Row[i];
        for(j = R[i]; j != i ; j = R[j]) {
            remove(Col[j]);
        }
        if(dfs()) {
            return true;
        }
        deep --;
        for(j = L[i]; j != i ; j = L[j]) {
            resume(Col[j]);
        }
    }
    resume(idx);
    return false;
}

int main() {

    return 0;
}
