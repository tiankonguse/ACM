#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;
__int64 n,m,per,total;
__int64 s[130000],num[130000];

void totalnum(__int64 x){ //求质因子

	__int64 i,j;
	total=0;
	for(i=2;i*i<=x;i++){
		if(x%i==0){
			while(x%i==0)x=x/i;
			num[total]=i;
			total++;
		}
	}
	if(x!=1){
		num[total]=x;
		total++;
	}
}
__int64 por(__int64 x,__int64 y){//x^y
	__int64 i,k;
	k=x;
	for(i=1;i<y;i++)x=k*x;
	return x;
}
void get(__int64 a,__int64 b,__int64 c){//c：公共质因子个数；

	__int64 i;
	if(b==c){
		__int64 t=m;
		for(i=0;i<c;i++){
			t=t/s[i];
		}
		per+=por(t,n);
	}
	else{
		for(i=a;i<total;i++){
			s[b]=num[i];
			get(i+1,b+1,c);
		}
	}
}



int main()
{
	__int64 res,i;
	while(scanf("%I64d %I64d",&n,&m)!=EOF)
	{
		totalnum(m);
		res=por(m,n);
		for(i=0;i<total;i++){
			per=0;
			get(0,0,i+1);
			if(i%2==0){
				res-=per;
			}else{
				res+=per;
			}
		}
		printf("%I64d\n",res);
	}
	return 0;
}