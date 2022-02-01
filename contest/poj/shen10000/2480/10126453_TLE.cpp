#include<stdio.h>
#define myint long long
myint kgcd(myint a,myint b)
{
    if(!a || !b)return a?a:b;
    else if(!(a&1) && !(b&1))return kgcd(a>>1,b>>1) <<1;
    else if(!(b&1)) return kgcd(a,b>>1);
    else if(!(a&1)) return kgcd(a>>1,b);
    else return kgcd(b,a%b);
}
int main()
{
myint n;
while(scanf("%lld",&n)!=EOF)
{
	myint sum=0;
	for(myint i=1;i<=n;i++)
	{
		sum+=kgcd(i,n);
	}
	printf("%lld\n",sum);
}
return 0;	
}
