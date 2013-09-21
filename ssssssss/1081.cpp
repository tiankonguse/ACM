#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
typedef int LL;
LL gcd(LL a,LL b){
    if (a==0) return 1;
    if (a<0) return gcd(-a,b);
    while (b){
        LL t=a%b; a=b; b=t;
    }
    return a;
}

int main()
{
	int n,m,g;
	bool yes=false;
	while(cin>>m>>n){
		if(yes)cout<<endl;
		else yes=true;
		g=gcd(m,n);
		cout<<"The lowest common multiple of "<<m<<" and "<<n<<" is "<<(m*n/g)<<"."<<endl;
		cout<<"The greatest common divisor of "<<m<<" and "<<n<<" is "<<g<<"."<<endl;
	}
	return 0;
}
