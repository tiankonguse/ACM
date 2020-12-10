// 拓扑排序(BFS) By 猛犸也钻地 @ 2012.02.15

#include <vector>
using namespace std;

// 传入结点个数n及各结点的出边e[]，返回排序后的结点集合
// dir为false时处理的是无向图，否则为有向图，排序后返回不在环上的点
vector<int> tpsort(int n, const vector<int> e[], bool dir = true){
    vector<int> ret,deg(n);
    for(int x=0;x<n;x++)
        for(size_t i=0;i<e[x].size();i++) deg[e[x][i]]++;
    for(int x=0;x<n;x++) if(deg[x]==!dir) ret.push_back(x);
    for(size_t c=0;c<ret.size();c++){
        int x=ret[c];
        for(size_t i=0;i<e[x].size();i++)
            if(--deg[e[x][i]]==!dir) ret.push_back(e[x][i]);
    }
    return ret;
}
