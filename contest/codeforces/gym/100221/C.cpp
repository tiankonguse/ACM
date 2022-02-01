/*
 * C.cpp
 * 
 * Copyright edward_mj
 * 
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;

class Gabow {
public:
    static const int SIZE = 100005; // 最大结点个数
    int cnt,idx[SIZE]; // idx[]为结点所在的强联通分量的编号
    // 传入结点个数n及各结点的出边e[]，返回强联通分量的个数cnt
    int gao(int n, const vector<int> e[]){
        Pc=Qc=-1;
        for(int i=cnt=0;i<n;i++) idx[i]=tag[i]=-1;
        for(int i=use=0;i<n;i++) if(tag[i]<0) dfs(i,e);
        return cnt;
    }
private:
    int tag[SIZE],P[SIZE],Q[SIZE],use,Pc,Qc;
    void dfs(int x, const vector<int> e[]){
        tag[P[++Pc]=Q[++Qc]=x]=use++;
        for(size_t i=0;i<e[x].size();i++){
            int y=e[x][i];
            if(~idx[y]) continue;
            if(~tag[y]) while(tag[y]<tag[Q[Qc]]) Qc--;
            else dfs(y,e);
        }
        if(Q[Qc]==x) Qc--; else return;
        do idx[P[Pc]]=cnt; while(P[Pc--]!=x);
        cnt++;
    }
}G;

class TrieGraph {
public:
    static const int SIZE = 20005; // 最大结点总数，约为模板串长度之和
    static const int LEAF = 6;     // 每个结点下的叶子数量
    // next[]指向了含有相同后缀但更短的一个字符串，n为当前存在的结点总数
    int next[SIZE],e[SIZE][LEAF],n; // e[][]为结点的各个叶子的编号
    bool data[SIZE]; // data[]一般用位标记维护当前的串匹配上了哪些模式串
    TrieGraph(){n=SIZE;}    // 别忘了写上这行
    void init(){
        fill_n(next,n,0);
        fill_n(data,n,0);
        memset(e,-1,n*sizeof(e[0]));
        n=1;
    }
    void insert(const char* s){
        int x=0;
        for(int i=0;s[i];i++){
            int c=s[i]-'a'; // 根据题目的字符集修改这里的映射方式
            x=~e[x][c]?e[x][c]:e[x][c]=n++;
        }
        data[x] = 1;
    }
    void make(){
        static int q[SIZE],m;
        next[0]=m=0;
        for(int c=0;c<LEAF;c++)
            if(~e[0][c]) next[q[m++]=e[0][c]]=0; else e[0][c]=0;
        for(int i=0;i<m;i++){
            int x=q[i];
            data[x] |= data[next[x]];
            for(int c=0;c<LEAF;c++){
                int t=e[next[x]][c];
                if(~e[x][c]) next[q[m++]=e[x][c]]=t; else e[x][c]=t;
            }
        }
    }
}T;
const int N = 20005;
int n, m, vn, gn;
vector <int> E[N], groupE[N];
int groupEdgeCount[N], groupSize[N];
ll f[N][2];

void buildGraph() {
    vn = T.n;
    rep (i, vn) rep (c, n) {
        if (!T.data[i] && !T.data[T.e[i][c]]) {
            E[i].push_back(T.e[i][c]);
            //printf("E %d %d\n", i, T.e[i][c]);
        }
    }
    gn = G.gao(T.n, E);
    //printf("gn = %d\n", gn);
    fill_n(groupEdgeCount, gn, 0);
    fill_n(groupSize, gn, 0);
    rep (u, vn) {
        foreach (it, E[u]) {
            int x = G.idx[u], y = G.idx[*it];
            if (x == y) {
                groupEdgeCount[x]++;
            } else {
                //printf("addedge %d %d\n", x, y);
                groupE[x].push_back(y);
            }
        }
        groupSize[G.idx[u]]++;
    }
}

ll dynamicProgramming() {
    rep (i, gn) {
        if (groupEdgeCount[i] > groupSize[i]) {
            return -1;
        }
    }
    rep (i, gn) {
        if (groupEdgeCount[i]) {
            f[i][0] = 1;
        }
    }
    ll ans = 0;
    for (int i = gn - 1; i >= 0; i--) {
        if (groupEdgeCount[i]) {
            ans += f[i][0];
            ans += f[i][1];
        }
        foreach (it, groupE[i]) {
            assert(*it < i);
            rep (o, 2) if (f[i][o]) {
                if (groupEdgeCount[*it] && o) return -1;
                f[*it][o + !!groupEdgeCount[*it]] += f[i][o];
            }
        }
    }
    return ans;
}

int main() {
    freopen("forbidden.in", "r", stdin);
    //freopen("forbidden.out", "w", stdout);
    scanf("%d%d", &n, &m);
    T.init();
    rep (i, m) {
        static char buf[15];
        scanf("%s", buf);
        T.insert(buf);
    }
    T.make();
    buildGraph();
    cout << dynamicProgramming() << endl;
    return 0;
}