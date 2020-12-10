// 有向图强联通分量(Gabow) By 猛犸也钻地 @ 2011.11.24

#include <vector>
using namespace std;

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
};
