// 二分图最大权值匹配(Kuhn-Munkras) By 猛犸也钻地 @ 2012.02.02

#include <cstring>
#include <algorithm>
using namespace std;

class KuhnMunkras {
public:
    typedef int VAL; // 权值的类型
    static const int SIZE = 1005;       // 最大单侧点个数
    static const int INF = 1000000007;  // 小于等于-INF的边当作不存在
    VAL sum;  // sum为最大权值之和，cnt为匹配点对的数量
    int cnt,pos[SIZE],neg[SIZE]; // pos[]为左侧点所匹配到的右侧点编号
                                 // neg[]反之，没有匹配到对应的点则为-1
    // 传入单侧点个数n及权值矩阵e[][]，返回匹配的最大边权之和sum
    // 如果左右两侧的点数不等，可添加孤立点，使得两侧点的个数均为n
    // 如果求的是最小权值匹配，可以将所有存在的边的权值取成负数
    VAL gao(int n, const VAL e[SIZE][SIZE]){ // 复杂度O(n^3)
        memset(pos,-1,sizeof(pos));
        memset(neg,-1,sizeof(neg));
        for(int i=0;i<n;i++) lx[i]=*max_element(e[i],e[i]+n);
        fill_n(ly,cnt=n,sum=0);
        for(int x=0;x<n;x++){
            fill(gap,gap+n,VAL(INF));
            while(1){
                memset(vx,0,sizeof(vx));
                memset(vy,0,sizeof(vy));
                if(aug(x,e)) break;
                VAL c=*min_element(gap,gap+n);
                for(int i=0;i<n;i++){
                    if(vx[i]) lx[i]-=c;
                    if(vy[i]) ly[i]+=c;
                }
            }
        }
        for(int x=0,y;x<n;x++)
            if(e[x][y=pos[x]]<=-INF) cnt--,pos[x]=neg[y]=-1;
                                else sum+=e[x][y];
        return sum;
    }
private:
    VAL gap[SIZE],lx[SIZE],ly[SIZE];
    bool vx[SIZE],vy[SIZE];
    bool aug(int x, const VAL e[SIZE][SIZE]){
        vx[x]=true;
        for(int y=0;y<cnt;y++) if(!vy[y]){
            VAL c=lx[x]+ly[y]-e[x][y];
            if(!c){ // 若权值为浮点数，就改成fabs(c)<=EPS
                vy[y]=true;
                gap[y]=INF;
                if(~neg[y] && !aug(neg[y],e)) continue;
                pos[neg[y]=x]=y;
                return true;
            }else{
                if(c<gap[y]) gap[y]=c;
            }
        }
        return false;
    }
};
