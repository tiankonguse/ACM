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

typedef __int64 LL;
const int N = 10000000;
const int M = 1000000;

bool is[N];
int prm[M];
int num_pre;

LL ans[11];
int prime_num;
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


int find(LL a){
    LL sum = (a*a + a + 1);
    int i,k=0;
//    printf("sum=%lld a=%lld\n",sum,a);
    for(i=0;;i++){
        if(i >= prime_num)return 0;
        if(sum%prm[i]==0){
            while(sum%prm[i]==0){
                sum /= prm[i];
            }
            k++;
            if(sum == 1)break;
        }
    }

//    for(i=k-1;i>=0;i--){
//        printf("%lld\n",s[i]);
//    }
//    printf("--%d\n",k);
//    printf("%lld\n",a);
    return k;
}

int main(){
//    freopen("out.txt","+w",stdout);
    prime_num = getprm();
    printf("prime_num=%d\n",prime_num);
    LL a;

    int k = 1;
    int num;
    int ans[11];
    for(a = 1; ;a++){
//        printf("%d\n",a);
        num = find(a);
        for(;k<=num;k++){
            ans[k] = a;
            printf("k=%d a=%d\n",k,ans[k]);
        }
        if(k > 9)break;
    }
    for(k=2;k<9;k++){
        printf("k=%d a=%d\n",k,ans[k]);
    }
//
//    int t;
//    LL n;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%lld",&n);
//        output(n,ans[n]);
//    }

    return 0;
}
