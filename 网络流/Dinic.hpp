// 网络流(Dinic) By 猛犸也钻地 @ 2013.04.02

#include <cstring>
#include <algorithm>
using namespace std;

class Dinic {
public:
    static const int INF = 1000000007, SIZE = 205;
    int c[SIZE][SIZE]; // c[][]为容量，n为总点数，s为源，t为汇
    int n,s,t,l[SIZE],e[SIZE];  // l[]为层次标号，e[]为当前弧
    int flow(int maxf = INF){   // 增广，上限为maxf，返回流量
        int left=maxf;
        while(build()) left-=push(s,left);
        return maxf-left;
    }
    int push(int x, int f){
        if(x==t) return f;
        int& y=e[x],sum=f;
        for(;y<n;y++) if(c[x][y]>0 && l[x]+1==l[y]){
            int cnt=push(y,min(sum,c[x][y]));
            c[x][y]-=cnt;
            c[y][x]+=cnt;
            sum-=cnt;
            if(!sum) return f;
        }
        return f-sum;
    }
    bool build(){
        int m=0;
        memset(l,255,sizeof(l));
        l[e[m++]=s]=0;
        for(int i=0;i<m;i++) for(int y=0;y<n;y++)
            if(c[e[i]][y]>0 && l[y]<0) l[e[m++]=y]=l[e[i]]+1;
        memset(e,0,sizeof(e));
        return l[t]>=0;
    }
};
