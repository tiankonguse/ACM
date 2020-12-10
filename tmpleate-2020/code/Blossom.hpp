// 一般图最大基数匹配(Gabow) By 猛犸也钻地 @ 2012.05.02

#include <vector>
#include <cstring>
using namespace std;

class Blossom {
public:
    static const int SIZE = 1005; // 最大结点个数
    int cnt,mate[SIZE]; // mate[]为配偶结点的编号，没有匹配上的点为-1
    // 传入结点个数n及各结点的出边e[]，返回匹配点对的数量cnt
    int gao(int n, const vector<int> e[]){ // 复杂度O(n^3)
        memset(mate,-1,sizeof(mate));
        for(int z=0;z<n;z++) if(mate[z]<0){
            for(int i=0;i<n;i++) tag[i]=-2;
            int q[SIZE],push=1,pop=0;
            tag[q[0]=z]=-1;
            while(push!=pop){
                int x=q[pop++%SIZE];
                for(size_t i=0;i<e[x].size();i++){
                    int y=e[x][i];
                    if(mate[y]<0 && z!=y){
                        modify(mate[y]=x,y,n);
                        i=push=pop=1234567890;
                    }else if(tag[y]>=-1){
                        memset(at,0,sizeof(at));
                        travel(x,n),travel(y,n);
                        for(int c=0;c<n;c++) if(at[c] && tag[c]<-1){
                            tag[c]=x+y*n+n;
                            q[push++%SIZE]=c;
                        }
                    }else if(tag[mate[y]]<-1){
                        tag[mate[y]]=x;
                        q[push++%SIZE]=mate[y];
                    }
                }
            }
        }
        for(int i=cnt=0;i<n;i++) if(mate[i]>i) cnt++;
        return cnt;
    }
private:
    int at[SIZE],tag[SIZE];
    void modify(int x, int y, int n){
        int z=mate[x]; mate[x]=y;
        if(z<0 || mate[z]!=x) return;
        if(tag[x]<n){
            mate[z]=tag[x];
            modify(mate[z],z,n);
        }else{
            y=tag[x]/n-1;
            z=tag[x]%n;
            modify(y,z,n);
            modify(z,y,n);
        }
    }
    void travel(int x, int n){
        int tmp[SIZE];
        memcpy(tmp,mate,sizeof(tmp));
        modify(x,x,n);
        for(int i=0;i<n;i++)
            if(mate[i]!=tmp[i]) at[i]^=1,mate[i]=tmp[i];
    }
};
