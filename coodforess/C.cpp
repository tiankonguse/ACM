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
using namespace std;

//1.bulid();2.query(a,b)；3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef int LL;
const int maxn = 3*100055;
LL sign[maxn<<2];//标记
LL sum[maxn<<2];
int n;
LL operate(LL a,LL b) {
    return max(a,b);//根据题意做相关修改，询问时的操作
}
void PushUp(int rt) {
    sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}
void PushDown(int rt,int m) {
    if (sign[rt]) {
        sign[rt<<1] = sign[rt];
        sign[rt<<1|1] = sign[rt];
        sum[rt] = -1;
        sum[rt<<1] = -1;
        sum[rt<<1|1] = -1;
        sign[rt] = 0;
    }
}
void bulid(int l=1,int r=n,int rt=1) {
    sign[rt] = 0;
    if(l==r) { // 据题意做相关修改
        sum[rt] = l;
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
}
void update(int L,int R,int add,int l=1,int r=n,int rt=1) {
    if(L<=l && r<=R) { // 据题意做相关修改
        if(add == 1) {
            sum[rt] = l;
        } else {
            sign[rt] = 1;
            sum[rt] = -1;
        }
        return ;
    }
    PushDown(rt,r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , add , lson);
    if (R > m) update(L , R , add , rson);
    PushUp(rt);
}
LL query(int L,int R,int l=1,int r=n,int rt=1) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    PushDown(rt , r - l + 1);
    int m = (l + r) >> 1;
    LL left = -1 ,right = -1;
    if (L <= m) left = query(L , R , lson);
    if (m < R) right= query(L , R , rson);
    return max(left ,right);
}
int ans[maxn];
int pre[maxn];
int next[maxn];

int main(int argc, char* argv[]) {

    int m,l,r,x,first,tmp_pre,tmp_next;
    scanf("%d%d",&n,&m);
    bulid();
    memset(ans,0,sizeof(ans));
    for(int i=1; i<=n; i++) {
        pre[i] = i-1;
        next[i] = i+1;
    }
    pre[n+1] = n;
    next[0] = 1;
//    printf("n=%d m=%d\n",n,m);
    while(m--) {
        scanf("%d%d%d",&l,&r,&x);
        first = query(l,r);
        update(l,r,0);
        update(x,x,1);
        while(first >= l) {
            if(first != x) {
                if(ans[first] == 0) {
                    ans[first] = x;
//                    printf("\n-- %d\n",first);
                }
                pre[next[first]] = pre[first];
                next[pre[first]] = next[first];
            }
            first = pre[first];

//            printf("%d",ans[1]);
//            for(int i=2; i<=n; i++) {
//                printf(" %d",ans[i]);
//            }
//            puts("");

        }
//        printf("m=%d\n",m);
    }
    printf("%d",ans[1]);
    for(int i=2; i<=n; i++) {
        printf(" %d",ans[i]);
    }
    printf("\n");

    return 0;
}






