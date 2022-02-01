#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 100010;
int sum[maxn<<2];
int n;

void PushUp(int rt){
		sum[rt]=sum[rt<<1]?sum[rt<<1]:sum[rt<<1|1];
}
void bulid(int l=1,int r=n,int rt=1){
	if(l==r){
		sum[rt]=l;
		return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}
void update(int p,int l=1,int r=n,int rt=1){
	if(l==r){
			sum[rt]=l-sum[rt];
			return ;
	}
	int m=(l+r)>>1;
	if(p<=m)update(p,lson);
	else update(p,rson);
	PushUp(rt);
}




int main(){  b
	char ops[11];
	int op;
	while(~scanf("%d",&n)){
		bulid();
		for(int i=0;i<n;i++){
			scanf("%s %d",ops,&op);
			if(ops[0]=='i'){
				update(sum[1]);
				printf("-->%d\n",sum[1]);
			}else if(ops[0]=='r'){

			}else{

			}
		}


	}


	return 0;
}

