// 稀疏表 By 猛犸也钻地 @ 2012.05.30

#include <algorithm>
using namespace std;

class SparseTable {
public:
    static const int SIZE = 100005, BIT = 17; // 要保证SIZE<2^BIT
    typedef int VAL;  // VAL为表中数据的类型
    VAL u[BIT][SIZE]; // u[i][j]表示[j,j+2^i)的区间最小值
    void init(int n, const VAL a[]){
        for(int i=0;i<n;i++) u[0][i]=a[i];
        for(int c=0;c+1<BIT;c++) for(int i=0;i<n;i++)
            u[c+1][i]=i+(1<<c)<n?min(u[c][i],u[c][i+(1<<c)]):u[c][i];
    }
    VAL query(int x, int y){ // 查询[x,y)的区间最小值，注意是左闭右开
        int c=-__builtin_clz(y-x)+31;
        return min(u[c][x],u[c][y-(1<<c)]);
    }
};
