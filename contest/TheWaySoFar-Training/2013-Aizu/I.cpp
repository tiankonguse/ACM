#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int f[2][300001];
int a[1015],b[1015];
int bo[1015],bo1[1000015];
int sum[1015];

int main(){
    int n;
    for (int i=1; i<=1000000; i<<=1) bo1[i]=1;
    while (scanf("%d",&n), n){
        for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
        memset(bo,0,sizeof(bo));
        int ans=0;
        for (int I=1; I<=500; ++I)
            if (!bo[I]){
                for (int J=I; J<=500; J<<=1) bo[J]=1;
                int N=0;
                for (int i=1; i<=n; ++i)
                    if (a[i]%I==0 && bo1[a[i]/I]) b[++N]=a[i]/I;
                for (; N;){
                    sum[0]=0;
                    for (int i=1; i<=N; ++i) sum[i]=sum[i-1]+b[i];
                    f[0][0]=0;
                    int net=1,cur=0;
                    for (int i=1; i<=N; ++i){
                        for (int j=0; j<=sum[i]; ++j){
                            f[net][j]=-100000;
                            if (j>sum[i-1]) f[cur][j]=-100000;
                        }
                        for (int j=0; j<=sum[i]; ++j){
                            f[net][j]=f[cur][j];
                            if (b[i] && j>=b[i] && (((b[i]-1) & (j-b[i])))==0)
                                f[net][j]=max(f[net][j],f[cur][j-b[i]]+1);
                        }
                        swap(net,cur);
                    }
                    for (int i=1; i<=sum[N]; ++i)
                        if (bo1[i]) ans=max(f[cur][i],ans);
                    for (int i=1; i<=N; ++i) b[i]/=2;
                    int k=0;
                    for (int i=1; i<=N; ++i)
                        if (b[i]) ++k;
                    if (!k) break;
                }
            }
        printf("%d\n",ans);
    }
}
