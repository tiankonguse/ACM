#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;

/*
平常的线段树是从上到下分配节点的，这样的线段树的叶子的位置是未知的，也就是叶子可能在最深那一层，也可能在次深那一层。
zwk 线段树是从下往上分配，就像哈夫曼树一样，两个两个合并，而且保证有2^h个叶子，这样就是一个完全二叉树了，而且每个叶子的位置都是固定的了。

首先声明一下
1.储存时，下标从1开始。
2.zwk使用开区间，所以总的节点左边和右边要增加一个空的节点。(作用下面可能会讲，若未将，则可以看代码画画图就知道了.)
3.假设区间共有n个节点，加上左右两个空节点，共有n+2节点，所以树的高度h需要满足 2^(h-1)< n+2 <=2^h.
4.由于有h层，所以非叶子节点有2^h-1个，所以叶子节点下标从m=2^h开始。
5.第一个叶子是空节点，所以有效节点从m+1开始，到m+n结束，m+n+1也是空叶子节点。
6.zwk的操作都是从叶子开始向上操作的。
*/

//1.bulid();2.query(a,b)；3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

const int maxn = 100055;
LL sign[maxn<<1];//标记
LL sum[maxn<<1];
int n,h,m;


void PushDown(int rt) {
    for (int i=h,p; i; i--) {
        if (sign[p=rt>>i]) { // 自顶向下下放标记
            sign[p]>>=1;//b[p]为节点增加总量，子节点增加一半
            sum[p<<1]+=sign[p];
            sum[p<<1|1]+=sign[p];
            sign[p<<1]+=sign[p];
            sign[p<<1|1]+=sign[p];
            sign[p]=0;
        }
    }
}



void bulid() {
    for (m=1,h=0; m-2<n; m+=m,h++); //h为树的高度，根高度为0
    memset(sum,0,sizeof(sum));
    memset(sign,0,sizeof(sign));

    for (int i=1,j=m+1; i<=n; i++,j++) {
        scanf("%lld",&sum[j]);
    }
    for (int i=m-1; i; i--) { //建树
        sum[i]=sum[i<<1]+sum[i*2+1];
    }
}

void update(int l,int r, int k) {
    int ll,rr;
    PushDown(l += m-1);
    PushDown(r += m+1);
    ll=l>>1;
    rr=r>>1;

    for (; l^r^1; l>>=1,r>>=1,k<<=1) { //k为当前层每个节点需增加的数
        if (~l&1) sum[l^1]+=k,sign[l^1]+=k;//r是左儿子
        if (r&1) sum[r^1]+=k,sign[r^1]+=k;//r是右儿子
    }
    for (i=ll; i; i>>=1) sum[i]=sum[i<<1]+sum[i*2+1]; //向上更新
    for (i=rr; i; i>>=1) sum[i]=sum[i<<1]+sum[i*2+1];
}



LL query(int l,int r) {
    LL ans = 0;
    PushDown(l += m-1);
    PushDown(r += m+1);
    for (; l^r^1; l>>=1,r>>=1) {//判断l和r是不是左右儿子
        if (~l&1) ans+=sum[l^1];
        if (r&1) ans+=sum[r^1];
    }
    return ans;
}


int main() {
    printf("%d\n",1<<1|1);

    return 0;
}
