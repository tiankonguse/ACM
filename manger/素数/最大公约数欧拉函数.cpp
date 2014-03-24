#include <iostream>
using namespace std;

//最大公约数
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

//最小公倍数
inline int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

//求1..n-1中与n互质的数的个数
int eular(int n){
    int ret=1,i;
    for (i=2;i*i<=n;i++)
        if (n%i==0){
            n/=i,ret*=i-1;
            while (n%i==0)
                n/=i,ret*=i;
        }
    if (n>1)
        ret*=n-1;
    return ret;
}

int main()
{
	cout<<gcd(42,28)<<endl;
	cout<<lcm(42,28)<<endl;
	cout<<eular(9)<<endl;
	return 0;
}