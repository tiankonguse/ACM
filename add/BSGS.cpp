//方程ax + by = c有c / gcd(a, b)个解，且等间距分布
template <class T>T ext_gcd(T a,T b,T& x,T& y){
	T t,ret;
	if (!b){
		x=1,y=0;
		return a;
	}
	ret=ext_gcd(b,a%b,x,y);
	t=x,x=y,y=t-a/b*y;
	return ret;
}
int inval(int a,int b,int n){
	int x,y,e;
	ext_gcd(a,n,x,y);
	e=(LL)x*b%n;
	return e<0?e+n:e;
}
int BabyStep(int A,int B,int C){
	map<int,int> Hash;
	LL buf=1%C,D=buf,K;
	int i,d=0,tmp;
	for(i=0;i<=100;buf=buf*A%C,++i)if(buf==B)return i;
	while((tmp=GCD(A,C))!=1){
		if(B%tmp)return -1;
		++d;
		C/=tmp;
		B/=tmp;
		D=D*A/tmp%C;
	}
	Hash.clear();
	int M=(int)ceil(sqrt((double)C));
	for(buf=1%C,i=0;i<=M;buf=buf*A%C,++i)if(Hash.find((int)buf)==Hash.end())Hash[(int)buf]=i;
	for(i=0,K=PowMod((LL)A,M,C);i<=M;D=D*K%C,++i){
		tmp=inval((int)D,B,C);
		if(tmp>0&&Hash.find(tmp)!=Hash.end())return i*M+Hash[tmp]+d;
	}
	return -1;
}