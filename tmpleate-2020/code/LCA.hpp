// 最近公共祖先(倍增算法) By 猛犸也钻地 @ 2012.07.23

#include <vector>
#include <cstring>
using namespace std;

class LCA {
public:
    static const int SIZE = 100005, BIT = 17; // 要保证SIZE<=2^BIT
    int fa[SIZE][BIT]; // fa[][]表示结点的父亲、父亲^2、父亲^4...
    int lv[SIZE]; // lv[]是结点的层次，从1开始
    // 传入结点个数n及各结点的出边e[]，对树或森林建立fa[][]和lv[]数组
    void init(int n, const vector<int> e[]){
        memset(lv,0,sizeof(lv));
        for(int i=0;i<n;i++) if(!lv[i]) build(i,i,e);
    }
    // 求x和y的最近公共祖先，不在同一棵树上则返回-1，复杂度O(logN)
    int lca(int x, int y){
        int c=lv[x]-lv[y];
        if(c>0) for(int i=0;i<BIT;i++) if(+c&1<<i) x=fa[x][i];
        if(c<0) for(int i=0;i<BIT;i++) if(-c&1<<i) y=fa[y][i];
        if(x==y) return x;
        for(int i=BIT-1;~i;i--)
            if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
        return fa[x][0]!=fa[y][0]?-1:fa[x][0];
    }
private:
    void build(int x, int src, const vector<int> e[]){
        fa[x][0]=src;
        lv[x]=lv[src]+1;
        for(int i=1;i<BIT;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
        for(size_t i=0;i<e[x].size();i++)
            if(e[x][i]!=src) build(e[x][i],x,e);
    }
};
