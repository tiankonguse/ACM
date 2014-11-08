// 二分图最大基数匹配(Hungary) By 猛犸也钻地 @ 2011.11.24

#include <vector>
#include <cstring>
using namespace std;

class Hungary {
public:
    static const int SIZE = 1005; // 最大的单侧点个数
    int cnt,pos[SIZE],neg[SIZE]; // pos[]为左侧点所匹配到的右侧点编号
                                 // neg[]反之，没有匹配到对应的点则为-1
    // 传入左侧点个数n和左侧点至右侧点的边表e[]，返回匹配点对的数量cnt
    int gao(int n, const vector<int> e[]){ // 复杂度O(n*m)
        memset(pos,-1,sizeof(pos));
        memset(neg,-1,sizeof(neg));
        for(int i=cnt=0;i<n;i++){
            memset(v,0,sizeof(v));
            if(aug(i,e)) cnt++;
        }
        return cnt;
    }
private:
    bool v[SIZE];
    bool aug(int x, const vector<int> e[]){
        int y;
        for(size_t i=0;i<e[x].size();i++) if(!v[y=e[x][i]]){
            v[y]=true;
            if(~neg[y] && !aug(neg[y],e)) continue;
            pos[neg[y]=x]=y;
            return true;
        }
        return false;
    }
};
