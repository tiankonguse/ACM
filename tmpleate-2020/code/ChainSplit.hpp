// 树链剖分 By 猛犸也钻地 @ 2012.02.10

#include <vector>
#include <cstring>
using namespace std;

class ChainSplit {
public:
    static const int SIZE = 100005; // SIZE为最大结点数+1
    int sz[SIZE],lv[SIZE]; // sz[]为子树的总结点数，lv[]为结点的深度
    int rt[SIZE],fa[SIZE]; // rt[]为所在的树的树根，fa[]为结点的父亲
    // seg[]为结点所在的链的编号，idx[]为结点在链上的位置
    // low[]为链首结点，top[]为链尾结点的父亲，len[]为链上结点的个数
    int cnt,seg[SIZE],idx[SIZE],low[SIZE],top[SIZE],len[SIZE];
    // 遍历某条链的方法：for(int x=low[u];x!=top[u];x=fa[x])
    // 传入结点个数n及各结点的出边e[]，对树或森林进行剖分，返回链数cnt
    int init(int n, const vector<int> e[]){
        memset(len,cnt=0,sizeof(len));
        memset(lv,0,sizeof(lv));
        for(int i=0;i<n;i++) if(!lv[i]){
            split(rt[i]=fa[i]=i,e);
            top[seg[i]]=fa[i]=SIZE-1; // 指向虚根
        }
        return cnt;
    }
    // 求x和y的最近公共祖先，不在同一棵树上则返回-1，复杂度O(logN)
    int lca(int x, int y){
        if(rt[x]!=rt[y]) return -1;
        while(seg[x]!=seg[y]){
            int p=top[seg[x]],q=top[seg[y]];
            if(lv[p]>lv[q]) x=p; else y=q;
        }
        return lv[x]<lv[y]?x:y;
    }
private:
    void split(int x, const vector<int> e[]){
        int y,t=-1;
        sz[x]=1;
        rt[x]=rt[fa[x]];
        lv[x]=lv[fa[x]]+1;
        for(size_t i=0;i<e[x].size();i++) if(e[x][i]!=fa[x]){
            fa[y=e[x][i]]=x;
            split(y,e);
            sz[x]+=sz[y];
            if(t<0 || sz[y]>sz[t]) t=y;
        }
        seg[x]=~t?seg[t]:cnt;
        idx[x]=~t?idx[t]+1:0;
        if(t<0) low[cnt++]=x;
        len[seg[x]]++;
        top[seg[x]]=fa[x];
    }
};
