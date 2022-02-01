#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 500555;
char name[maxn][12];
int num[maxn];
int rprim[35][2] = {
	498960,200,332640,192,277200,180,221760,168,166320,160,
	110880,144,83160,128,55440,120,50400,108,45360,100,
	27720,96,25200,90,20160,84,15120,80,10080,72,
	7560,64,5040,60,2520,48,1680,40,1260,36,
	840,32,720,30,360,24,240,20,180,18,
	120,16,60,12,48,10,36,9,24,8,
	12,6,6,4,4,3,2,2,1,1};

//1.bulid();
//2.query(a,b)
//3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

int sum[maxn<<2];
int n,k;
//根据题意做相关修改，询问时的操作 
int operate(int a,int b){
	return a+b;
}
void PushUp(int rt){
	sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}
void bulid(int l=1,int r=n,int rt=1){
	if(l==r){// 据题意做相关修改
		sum[rt]=1;return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}
void update(int p,int add=0,int l=1,int r=n,int rt=1){
	if(l==r){// 据题意做相关修改
		sum[rt]=add;k=l;
		//printf("k=%d\n",k);
		return ;
	}
	int m=(l+r)>>1;
	if(p<=sum[rt<<1])update(p,add,lson);
	else update(p-sum[rt<<1],add,rson);
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

int main(){
	int p,x,now,leftnum,rightnum,m;
	while(~scanf("%d%d",&n,&k)){
		p=0;
		while(n<rprim[p][0])p++;
		x=rprim[p][0];
		bulid();
		//printf("sum[1]=%d\n",sum[1]);
		for(int i=1;i<=n;i++){
			scanf("%s%d",name[i],&num[i]);
		}
		m=n;
		now=k;
		//printf("x=%d\n",x);
		for(int i=1;i<x;i++){
			update(now);//now出队 
			m--;
			//printf("m=%d\n",m);
			//转化为向左查多少人 
			if(num[k]%m==0){
				if(num[k]>0)num[k]=m;
				else num[k]=1;
			}else{
				num[k]%=m;
				if(num[k]<0)num[k]+=m+1;
			}
			leftnum=query(1,k);//找出now左边有多少个人 
			rightnum=m-leftnum;
			//printf("num[%d]=%d left=%d  right=%d\n",k,num[k],leftnum,rightnum);
			if(num[k]<=rightnum){
				now=leftnum+num[k];
			}else{
				now=num[k]-rightnum;
			}
		}
		update(now);
		printf("%s %d\n",name[k],rprim[p][1]);
		
	}
	
	return 0;
}
/*
4 1
Tom 2
Jack 4
Mary -1
Sam 1
*/
