/**************************************************************************
 **      File Name: A.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/31 12:09:06
/**************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

//1.bulid();2.query(a,b)；3.update(a,b)

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef long long LL;
const int maxn = 100005;
LL sign[maxn<<2];//标记
LL sum[maxn<<2];
int n;
vector<int>g[N];


LL operate(LL a,LL b){
	return a+b;//根据题意做相关修改，询问时的操作
}
void PushUp(int rt){
	sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}
void PushDown(int rt,int m) {
	if (sign[rt]) {
		sign[rt<<1]   += sign[rt];
		sign[rt<<1|1] += sign[rt];
		sum[rt<<1] += (m - (m >> 1)) * sign[rt];
		sum[rt<<1|1] += (m >> 1) * sign[rt];
		sign[rt] = 0;
	}
}
void bulid(int l=1,int r=n,int rt=1){
	sign[rt] = 0;
	if(l==r){// 据题意做相关修改
		scanf("%lld",&sum[rt]);return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}
void update(int L,int R,int add,int l=1,int r=n,int rt=1){
	if(L<=l && r<=R){// 据题意做相关修改
		sign[rt]+=add;
		sum[rt]+=(LL)add*(r-l+1);return ;
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
	LL ret = 0;
	if (L <= m) ret += query(L , R , lson);
	if (m < R) ret += query(L , R , rson);
	return ret;
}


int main(){
    int n,m,i,j,p,node,oldoneCount;
    char s[2];
    while(scanf("%d%d",&n,&m)!=EOF) {

        for(i=1; i<=n; i++) {
            g[i].clear();
        }

        memset(have,0,sizeof(have));
        memset(mark,0,sizeof(mark));
        memset(childCount,0,sizeof(childCount));
        memset(oneCount,0,sizeof(oneCount));
        preNode[1] = 0;


        for(i=2; i<=n; i++) {
            scanf("%d",&p);
            preNode[i] = p;
            g[p].push_back(i);
        }


        childCount[1] = findChildCount(1);

        while(m--) {
            scanf("%s%d",&s,&node);
            if(s[0] == 'o') {
                mark[node] = !mark[node];
                oldoneCount = oneCount[node];
                oneCount[node] = childCount[node] - oldoneCount;
                update(preNode[node],oneCount[node] - oldoneCount);
//                for(i=1;i<=n;i++){
//                    printf("%d--->%d\n",i,oneCount[i]);
//                }

                //puts("");
            } else {
                printf("%d\n",query(node));
            }
        }
    }
    return 0;
}
