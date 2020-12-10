// 无向图全局最小割(Stoer-Wagner) By 猛犸也钻地 @ 2012.08.22

#include <vector>
#include <algorithm>
using namespace std;

class StoerWagner {
public:
    typedef int VAL; // 权值的类型
    static const int SIZE = 505;        // 最大结点个数
    static const VAL INF = 1000000007;  // 最大权值之和
    VAL sum,e[SIZE][SIZE];
    // 传入结点个数n及权值矩阵a[][]，返回无向图全局最小割的边权之和sum
    // 对于矩阵a[][]中不存在的边，权值设为0
    VAL gao(int n, const VAL a[SIZE][SIZE]){
        vector<int> v,idx(n);
        for(int i=0;i<n;i++) copy(a[i],a[i]+n,e[idx[i]=i]);
        for(int i=0;i<n;i++) e[i][i]=0;
        for(sum=INF;idx.size()>=2;n=idx.size()){
            vector<VAL> s(n);
            for(int i=0;i<n;i++) v.push_back(i);
            int p=0,t=0;
            while(v.size()){
                int m=v.size(),x=-1;
                for(int i=0;i<m;i++) if(x<0 || s[x]<s[i]) x=i;
                for(int i=0;i<m;i++) s[i]+=e[idx[v[x]]][idx[v[i]]];
                v.erase(v.begin()+x);
                s.erase(s.begin()+x);
                swap(p=v[x],t);
            }
            VAL now=0;
            for(int i=0;i<n;i++) if(i!=t) now+=e[idx[t]][idx[i]];
            for(int i=0;i<n;i++){
                e[idx[i]][idx[p]]+=e[idx[i]][idx[t]];
                e[idx[p]][idx[i]]+=e[idx[t]][idx[i]];
            }
            idx.erase(idx.begin()+t);
            sum=min(sum,now);
        }
        return sum;
    }
};
