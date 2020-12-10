// 最小树形图(Chu-Liu/Edmonds) By 猛犸也钻地 @ 2012.09.13

/* 如果题目给定了树根，则直接使用此模板 //
   如果题目要求在结点a[1],a[2],..,a[k]中，必须且只能选择一个结点为根
       则建立超级根r，并连接至每个a[i]，权值为INF
       然后调用此模板，将返回值减去INF即为答案
       如果减去后的权值之和大于等于INF，则说明无解
       注意，这种情况下权值的类型必须是long long
   如果题目要求在结点a[1],a[2],..,a[k]中，可以选择任意数量个结点为根
       则建立超级根r，并连接至每个a[i]，权值为0
       然后调用此模板，所得返回值即为答案
// 复杂度O(n*m)，不支持输出方案 */

#include <vector>
#include <algorithm>
using namespace std;

class Edmonds {
public:
    static const int SIZE = 1005, INF = 1000000007;
    typedef int VAL;
    typedef pair<int,int> PII;
    typedef pair<PII,VAL> TPL;
    // 传入树根编号root，结点个数n及边集e，返回最小树形图中的边权之和
    // 无解时的返回值大于等于INF，默认类型下INF的值不要超过0x7FFFFFFF
    VAL gao(int root, int n, vector<TPL> e){
        VAL low[SIZE],ret=0;
        int src[SIZE],tag[SIZE],idx[SIZE],m=e.size();
        while(1){
            for(int i=0;i<n;i++) idx[i]=tag[i]=-1,low[i]=INF*2;
            for(int i=0;i<m;i++){
                int x=e[i].first.first;
                int y=e[i].first.second;
                if(x!=y && e[i].second<low[y]){
                    low[y]=e[i].second;
                    src[y]=x;
                }
            }
            for(int i=0;i<n;i++)
                if(i!=root && low[i]>INF) return INF*2;
            low[root]=0;
            int t,cnt=0;
            for(int i=0;i<n;i++){
                ret+=low[t=i];
                while(t!=root && idx[t]<0 && tag[t]!=i){
                    tag[t]=i;
                    t=src[t];
                }
                if(t!=root && idx[t]<0){
                    for(int x=src[t];x!=t;x=src[x]) idx[x]=cnt;
                    idx[t]=cnt++;
                }
            }
            if(!cnt) break;
            for(int i=0;i<n;i++) if(idx[i]<0) idx[i]=cnt++;
            for(int i=0;i<m;i++){
                int& x=e[i].first.first;
                int& y=e[i].first.second,t=y;
                x=idx[x],y=idx[y];
                if(x!=y) e[i].second-=low[t];
            }
            root=idx[root],n=cnt;
        }
        return ret;
    }
};
