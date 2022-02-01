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
#define maxn 110000
#define eps 1e-7
using namespace std;
#define N 12345
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
int x[N<<1];
int y[N<<1];
int main() {
    int i,j,k;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int a,b,c;
    memset(x,1,sizeof(x));
    x[0]=0;
    x[1]=0;

    for(i=2; i<=sqrt(N)+1; i++) {
        if(!x[i])continue;
        for(j=(i<<1); j<=N; j+=i) {
            x[j]=0;
        }
    }

    j=1;
    x[1]=1;
    for(i=1; i<N; i++) {
        if(x[i])y[j++]=i;
    }

    while(scanf("%d%d",&a,&b)!=EOF) {
        printf("%d  %d:",a,b);
        for(i=1;; i++) {
            if(y[i]>a)break;
        }
        k=i-1;

        if(k%2==1) {
            if(b*2-1>=k) {
                for(i=1; i<=k; i++) {
                    printf(" %d",y[i]);
                }
            } else {
                for(i=(k+1)/2-(b-1); i<=(k+1)/2+(b-1); i++) {
                    printf(" %d",y[i]);
                }
            }
        } else {
            if(b*2>=k) {
                for(i=1; i<=k; i++) {
                    printf(" %d",y[i]);
                }
            } else {
                for(i=(k+1)/2-(b-1); i<=(k+1)/2+(b-1)+1; i++) {
                    printf(" %d",y[i]);
                }
            }
        }
        puts("");
        puts("");
    }
    return 0;
}
