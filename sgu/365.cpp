#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;

LL f[30][10],g[30][10];

int main(){
    f[0][0]=1;
    for (int i=1; i<=20; ++i)
        for (int j=0; j<10; ++j)
            for (int k=0; k<=j; ++k)
                f[i][j]=f[i][j]+f[i-1][k];
    for (int i=1; i<=20; ++i)
        for (int j=0; j<10; ++j)
            for (int k=0; k<j; ++k)
                g[i][j]=g[i][j]+f[i-1][k];
    int n;
    scanf("%d",&n);
    LL ans=0;
    for (int N=1; N<=n; ++N){
        if (N==1) {
            ans=ans+10;
            continue;
        }
        for (int L=0; L<10; ++L)
            for (int k1=1; k1<=N; ++k1){
                LL z1,z2;
                z1=g[k1][L];
                z2=g[N-k1+1][L];
                ans=ans+z1*z2;
                //printf("%d %d %d %lld %lld\n",L,k1,N-k1+1,z1,z2);
            }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
