#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int f[30][200][11];

int main(){
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    for (int i=1; i<=20; ++i)
        for (int j=0; j<=155; ++j)
            for (int k=0; k<=10; ++k){
                f[i][j][k]=f[i-1][j][k];
                if (k>0 && j>=i) f[i][j][k]=f[i][j][k]+f[i-1][j-i][k-1];
            }
    int n,k,s;
    while (scanf("%d%d%d",&n,&k,&s), n || k || s) printf("%d\n",f[n][s][k]);
}
