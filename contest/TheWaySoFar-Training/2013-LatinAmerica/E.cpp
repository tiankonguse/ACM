#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;
#define N 105
char s[N];
int n , m , Q = 1e9 + 7;
int f[11][N][11];
int sum[12],a[12];
int C[N][N];

void swap(int &a,int &b){
    int t=a; a=b; b=t;
}

void work() {
    n = strlen(s);
    memset(sum,0,sizeof(sum));
    memset(a,0,sizeof(a));
    for (int i=0; i<n; ++i)
        ++a[s[i]-'0'];
    for (int i=0; i<5; ++i) swap(a[i],a[9-i]);
    sum[0]=a[0];
    for (int i=1; i<10; ++i) sum[i]=sum[i-1]+a[i];
    memset(f,0,sizeof(f));
    int n0=n/2,n1=n-n0;
    f[0][0][0]=1;
    for (int i=0; i<10; ++i)
        for (int j=0; j<=n1; ++j)
            for (int k=0; k<11; ++k){
                if (!f[i][j][k]) continue;
                //printf("%d %d %d\n",9-i,j,k);
                int j1=(i==0)?0:sum[i-1];
                j1-=j;
                for (int l=0; l<=a[i]; ++l){
                    int l1=l,l2=a[i]-l;
                    if (j+l1>n0) continue;
                    if (j1+l2>n1) continue;
                    int p=f[i][j][k];
                    if (!(n & 1) &&i==9) p=(LL)p*C[j+l1-1][l1]%Q;
                    else p=(LL)p*C[j+l1][l1]%Q;
                    if ((n & 1) && i==9) p=(LL)p*C[j1+l2-1][l2]%Q;
                    else p=(LL)p*C[j1+l2][l2]%Q;
                    int J=j+l1,K=(k+l1*(9-i)-l2*(9-i)+11*10000)%11;
                    f[i+1][J][K]=(f[i+1][J][K]+p)%Q;
                }
            }
    printf("%d\n",f[10][n0][0]);
 }

int main() {
    int n;
    C[0][0]=1;
    for (int i=1; i<=100; ++i)
        for (int j=0; j<=i; ++j)
            C[i][j]=(j==0)?1:(C[i-1][j]+C[i-1][j-1])%Q;
    while (~scanf("%s" , s))
        work();
    return 0;
}
