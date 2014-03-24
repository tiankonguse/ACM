#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 46555
using namespace std;
typedef __int64 LL;


char x[maxn];
int prime[maxn];
int cnt;
void init() {
    memset(x,-1,sizeof(x));
    memset(prime,0,sizeof(prime));
    x[0]=0;
    x[1]=0;
    for(int i=2; i*i<maxn+1; i++) {
        if(!x[i])continue;
        for(int j=(i<<1); j<=maxn; j+=i) {
            x[j]=0;
        }
    }
    cnt=0;
    for(int i=0; i<maxn; i++) {
        if(x[i]) {
            prime[cnt++]=i;
        }
    }
}
bool isprime(int n){
	if(n<maxn){
		if(x[n]==-1)return 1;
		else return 0;
	}
	for(int i=0;;i++){
		if(prime[i]*prime[i]>n)return 1;
		if(n%prime[i]==0)return 0;
	}
}


int cut(int m) {
    int k = 0;
    while(m) {
        k += m%10;
        m/=10;
    }
    return k;
}


int solve(int n) {
    int tmp=0,t,i;
    for(i=2;n!=1;) {
        if(n%i==0) {
			tmp+=cut(i);
			n/=i;
			if(isprime(n)){
				tmp+=cut(n);
				return tmp;
			}
        }else {
			i++;
        }
    }
}


int main() {
    int n,i,j,k;
    init();
//    freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    while(scanf("%d",&n),n) {
        for(i=n+1;; i++) {
            if(isprime(i))continue;
            int tmp=cut(i);
            if(solve(i)==tmp)break;
        }
        printf("%d\n",i);
    }
    return 0;
}
