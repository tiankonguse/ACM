#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define PI acos(-1.0)
#define inf 0x3fffffff
#define maxn 100010
using namespace std;

typedef long long LL;
const int N = 1000000;
const int M = 1000000;

bool is[N];
int prm[M];
int num_pre;

LL ans[11];

int getprm(){
    int e = (int)(sqrt(1.0*N)+1),k=0,i;
    memset(is,1,sizeof(is));
//     printf("++%d\n",e);
    prm[k++]=2;
    is[0]=is[1]=0;
    for(i=4;i<N;i+=2)is[i]=0;
    for(i=3;i<e;i+=2){
        if(is[i]){
//                printf("++\n");
            prm[k++]=i;
            for(int s=i+i,j=i*i;j<N;j+=s)is[j]=0;

        }

    }

    for(;i<N;i+=2){
        if(is[i]){
            prm[k++]=i;

        }

    }
    return k;
}


void output(int n,LL a){
    LL sum = (a*a + a + 1);
    LL s[10];
    int i,k=0;
    for(i=0;i<10;i++)s[i]=1;

    for(i=0;;i++){
        if(sum%prm[i]==0){
            while(sum%prm[i]==0){
                sum /= prm[i];
                s[k] *= prm[i];
            }
            k++;
            if(sum == 1)break;
        }
    }

    for(i=k-1;i>=0;i--){
        printf("%lld\n",s[i]);
    }
//    printf("--%d\n",k);
    printf("%lld\n",a);

}

int main(){

    getprm();

    ans[2] = 4;
    ans[3] = 16;
    ans[4] = 100;
    ans[5] = 562;
    ans[6] = 2629;
    ans[7] = 49240;
    ans[8] = 588289;
    ans[9] = 2485492;

    int t;
    LL n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        output(n,ans[n]);
    }

    return 0;
}
