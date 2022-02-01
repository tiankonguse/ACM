#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;

void output(LL a){
	char s[65];
	LL in = a;
	s[64] = '\0';
	for(int i=63;i>=0;i--){
		s[i] = (in&1) + '0';
		in >>= 1;
	}
	printf("%s %lld\n",s,a);
}


int main(int argc, char* argv[]) {

	LL a = 1;
	for(int i=1;i<=62;i++){
		a = a<<1;
		output(a);
	}

    return 0;
}






