#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#define maxn 1100
using namespace std;

char x[maxn];
char y[maxn];
char z[maxn];
long long int path[maxn][maxn];

int main(){
    long long int a,b,c,i,j,k,l1,l2,ans;
    long long int mod=1000000007;

    while(scanf("%s%s",x+1,y+1)!=EOF){

        memset(z,0,sizeof(z));
        memset(path,0,sizeof(path));
        l1=strlen(x+1);
        l2=strlen(y+1);

        if(l1>=l2){
            strcpy(z+1,x+1);
            strcpy(x+1,y+1);
            strcpy(y+1,z+1);
        }

        l1=strlen(x+1);
        l2=strlen(y+1);

        for(i=1;i<=l1;i++){
            for(j=1;j<=l2;j++){
                path[i][j]=path[i][j-1];
                if(x[i]==y[j]){
                    path[i][j]=(path[i-1][j-1]+1+path[i][j])%mod;
                }
            }
        }

        ans=0;
        for(i=1;i<=l1;i++){
            ans=(ans+path[i][l2])%mod;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
