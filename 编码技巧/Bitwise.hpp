// 二进制位运算 By 猛犸也钻地 @ 2012.02.04

/* 常用位运算操作 //
   把右数第i位置0                     x & ~(1 << i)
   把右数第i位置1                     x | (1 << i)
   把右数第i位取反                    x ^ (1 << i)
   得到右树i位的值                    (x >> i) & 1
   得到最右边的i位                    x & (1 << i) – 1
   把最右边的1置0                     x & (x – 1)
   把最右边的0置1                     x | (x + 1)
   得到最右边的1的掩码                x & -x
   得到最右边的0的掩码                ~x & (x + 1)
   把最右边连续的0串置1               x | (x – 1)
   把最右边连续的1串置0               ((x | (x – 1)) + 1) & x
   得到最右边连续的0串的掩码          ~x & (x – 1)
   得到最右边连续的1串的掩码          x ^ (((x | (x – 1)) + 1) & x)
   得到最右边的1及右边连续的0串的掩码 x ^ (x - 1)
   下舍入到2^i倍数                    x & (-1 << i)
   上舍入到2^i倍数                    t = (1 << i) - 1, x = (x + t) & ~t
// 另外需注意，比较操作低于移位，但高于位运算的与或操作 */

/* gcc内置位运算函数 //
   __builtin_ffs(unsigned int x) 末起首个1的位置(1-based)，x为0时返回0
   __builtin_clz(unsigned int x) 前导连续0的个数，x不能为0
   __builtin_ctz(unsigned int x) 末尾连续0的个数，x不能为0
   __builtin_popcount(unsigned int x) 二进制中1的个数
   __builtin_parity(unsigned int x)   二进制中1的个数的是否为奇数
// 64位整数的版本的函数就是上面那些的函数名最后直接加上ll */

#include <vector>
using namespace std;

// 求低位连续0的个数，效果同__builtin_ctz，用于没有gcc的环境
inline int ctz(int x){
    static int table[32]={0,1,28,2,29,14,24,3,30,22,20,15,25,17,4,8,
                          31,27,13,23,21,19,16,7,26,12,18,6,11,5,10,9};
    return table[unsigned(x&-x)*0x077CB531>>27];
}

// 测试x乘y时是否可能会超出LL范围，如果可能超出则返回true
// 如果要测试无符号类型，则下面的不等式改成<=63
bool overflow(long long x, long long y){
    return __builtin_clzll(x)+__builtin_clzll(y)<=64;
}

// 根据掩码mask和当前的子集掩码sub，以递减序的方式返回下一个子集掩码
inline int next_subset(int sub, int mask){
    return (sub-1)&mask;
}

// 根据当前掩码mask，以递增序返回下一个含有相同数量1的掩码，mask不能为0
inline int next_samebit(int mask){
    int lowbit=mask&-mask;
    int slack=lowbit+mask;
    return slack|(mask^slack)/lowbit/4;
}

// 高速Zeta变换，计算a'[x]=sum(a[t])，其中所有的集合t均是集合x的子集
void zeta(int n, int a[]){
    int mask=(1<<n)-1;
    for(int i=0;i<n;i++) for(int s=0;s<=mask;s++)
        if(s&1<<i) a[s]+=a[s^1<<i];
}

// 序号转格雷码
inline int index_to_gray(int mask){
    return mask^mask>>1;
}

// 格雷码转序号
inline int gray_to_index(int mask){
    mask^=mask>>16;
    mask^=mask>>8;
    mask^=mask>>4;
    mask^=mask>>2;
    return mask^mask>>1;
}

// 生成所有n位的格雷码
vector<int> make_gray(int n){
    vector<int> ret;
    int m=1<<n,mask=0;
    for(int i=0;i<m;i++) ret.push_back(mask^=i&-i);
    return ret;
}
