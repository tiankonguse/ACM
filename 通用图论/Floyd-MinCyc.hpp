// 最小环(Floyd) By 猛犸也钻地 @ 2012.09.13

#include <vector>
#include <cstring>
using namespace std;

class Floyd {
public:
    typedef int VAL; // 权值的类型
    static const int SIZE = 1005;
    vector<int> path;
    VAL len[SIZE][SIZE],ans;
    int src[SIZE][SIZE];
    // 传入结点个数n及权值矩阵a[][]，返回最小环的长度ans，方案记在path中
    // 对于矩阵a[][]中不存在的边，权值设为1e9+7或0x7F7F7F7F之类的极大值
    VAL gao(int n, const VAL a[SIZE][SIZE]){
        ans=1e9+7;  // 若最后的返回值大于等于1e9，则不存在最小环
        memset(src,-1,sizeof(src));
        memcpy(len, a,sizeof(len));
        for(int k=0;k<n;k++){
            for(int i=0;i<k;i++) for(int j=i+1;j<k;j++){
                VAL tmp=a[k][i]+a[j][k];
                if(len[i][j]>=ans-tmp) continue;
                path.clear();
                getpath(i,j);
                path.push_back(k);
                path.push_back(i);
                ans=tmp+len[i][j];
            }
            for(int i=0;i<n;i++) for(int j=0;j<n;j++){
                VAL tmp=len[i][k]+len[k][j];
                if(tmp>=len[i][j]) continue;
                len[i][j]=tmp;
                src[i][j]=k;
            }
        }
        return ans;
    }
private:
    void getpath(int i, int j){
        int k=src[i][j];
        if(~k){
            getpath(i,k);
            getpath(k,j);
        }else{
            path.push_back(j);
        }
    }
};
