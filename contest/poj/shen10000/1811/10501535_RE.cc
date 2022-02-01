#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<ctime>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define INT __int64

//二进制法求乘方取模 
INT Pow(INT a, INT b, INT M){
	INT t=1;
	while(b){
		if(b&1)t=t*a%M;
		a=a*a%M;
		b>>=1;
	}
	return t;
}

//rabinmiller方法测试n是否为质数 
bool isprime(INT n){
	int pri[]={2,3,5,7,11,13,17,19,23,29};
	
	if(n<2)return false;
	if(n==2)return true;
	if(!(n&1))return false;
	INT k=0,i,j,m,a;
	m=n-1;
	while(m%2==0)m=m>>=1,k++;
	for(int i=0;i<10;i++){
		if(pri[i]>=n)return 1;
		a=Pow(pri[i],m,n);
		if(a==1)continue;
		for(j=0;j<k;j++){
			if(a==n-1)break;
			a=Pow(a,2,n);
		}
		if(j<k)continue;
		return false;
	}
	return true;
}

INT gcd(INT A,INT B){
	while(A!=0){
		INT C=B%A;
		B=A;
		A=C; 
	} 
	return B;
}


//pollard_rho分解，给出N的一个非1因数，返回N时为一个没有找到 
INT pollard_rho(INT C,INT N){
	
	INT I=1;
	INT X=rand()%N;
	INT Y=X;
	INT K=2;
	INT D;
	do{
		
		I++;
		D=gcd(N+Y-X,N);
		if(D>1 && D<N)return D;
		if(I==K)Y=X,K*=2;
		X=(Pow(X,2,N)+N-C)%N;
		
	}while(Y!=X);
	
	return N;
}


//找出N的最小质因数 
INT rho(INT N){
	if(isprime(N))return N;
	do{
		INT T=pollard_rho(rand()%(N-1)+1,N);
		if(T<N){
			INT A,B;
			A=rho(T);
			B=rho(N/T);
			return A<B?A:B;
		}
	}while(1);
}

int main(){
	int t;
	INT n,ans;
	scanf("%d",&t);
	srand(time(NULL));
	while(t--){
		scanf("%I64d",&n);
		ans=rho(n);
		if(ans==n)printf("Prime\n");
		else printf("%I64d\n",ans); 
	}

	return 0;
}
