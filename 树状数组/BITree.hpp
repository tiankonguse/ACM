// 树状数组 By 猛犸也钻地 @ 2011.11.24

/* 使用提示 //
   单点修改/区间查询：
       使P位置增加V           modify(P,V);
       查询[L,R]区间的和      getsum(R)-getsum(L-1);
   区间修改/单点查询：
       使[L,R]区间各增加V     modify(L,V),modify(R+1,-V);
       查询P位置的值          getsum(P);
   区间修改/区间查询(此时BIAS必须设为0)：
       使[0,R]区间各增加V     A.modify(R,R*V),B.modify(R,-V);
       查询[0,R]区间的和      A.getsum(R)+B.getsum(R)*R;
   多维树状数组和单维的类似，比如修改操作是这样的：
       for(int i=x+BIAS;i<SIZE;i++)
           for(int j=y+BIAS;j<SIZE;j++) u[i][j]+=v;
   模板里的BIAS用来避免下溢出，比如查询L-1时，可能会取到0或-1的位置
   因此SIZE通常设为最大结点数+2*BIAS，而BIAS通常设为5或10
// 另外，数组大小未知时，可用map代替，缺点是多了一个log的复杂度 */

#include <cstring>
using namespace std;

class BITree {
public:
    static const int SIZE = 100010, BIAS = 5;
    long long u[SIZE];
    void clear(){
        memset(u,0,sizeof(u));
    }
    void modify(int x, long long v){
        for(x+=BIAS;x<SIZE;x+=x&-x) u[x]+=v;
    }
    long long getsum(int x){
        long long s=0;
        for(x+=BIAS;x;x-=x&-x) s+=u[x];
        return s;
    }
};
