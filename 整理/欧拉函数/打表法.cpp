#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N=5000010;
typedef unsigned long long  LLU;
LLU phi[N+10];
void ruler() {
    int i,j;
    for (i = 1; i <= N; i++) phi[i] = i;
    for (i = 2; i <= N; i += 2) phi[i] /= 2;
    for (i = 3; i <= N; i += 2)
        if(phi[i] == i) {
            for (j = i; j <= N; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
}

int main() {
    int i,j,t,a,b;
//    printf("%llu\n",~0u);
    ruler();
    phi[1]=0;
    for(i=2; i<N; i++){
        phi[i]=phi[i-1]+phi[i]*phi[i];
    }
    int cas=0;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        printf("Case %d: %llu\n",++cas,phi[b]-phi[a-1]);
    }
}
/*
18446744069414584319
17843739680365513000
17843739680365512704
*/
