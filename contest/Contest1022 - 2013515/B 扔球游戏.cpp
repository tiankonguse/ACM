/*************************************************************************
    > File Name: B 扔球游戏.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 18:03:31
 ************************************************************************/

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
//1.bulid();
//2.query(a,b)
//3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 55555;
int sum[maxn<<2];
int n;
//根据题意做相关修改，询问时的操作
int operate(int a,int b){
  return max(a,b);
}
void PushUp(int rt){
  sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}
void bulid(int l=1,int r=n,int rt=1){
	if(l==r){// 据题意做相关修改
		scanf("%d",&sum[rt]);return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}
void update(int p,int add,int l=1,int r=n,int rt=1){
	if(l==r){// 据题意做相关修改
			sum[rt]+=add;return ;
	}
	int m=(l+r)>>1;
	if(p<=m)update(p,add,lson);
	else update(p,add,rson);
	PushUp(rt);
}

int query(int L,int R,int l=1,int r=n,int rt=1){
	if(L<=l && r<=R){
		return sum[rt];
	}
	int m=(l+r)>>1;
	int ret=0;
	if(L<=m)ret=operate(ret,query(L,R,lson));
	if(R> m)ret=operate(ret,query(L,R,rson));
	return ret;
}
int main() {
    int a,b,ans,i,now ;
    while(~scanf("%d",&n)){
        bulid();
        ans = 0;
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            if(a+1 == b || a- 1 == b){
                ans++;
            }else{
                now = a;
                if(a>b)swap(a,b);
                if(query(a+1,b-1) <= query(now,now)){
                    ans++;
                }
            }

        }
        printf("%d\n",n-ans);
    }
    return 0;
}
