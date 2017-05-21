#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 100100

using namespace std;
__int64 s[MAXN]={0};
__int64 num[MAXN];
int used[MAXN];
int main(){
    int c,n;
    while(scanf("%d%d",&c,&n)){
        if(c==0 && n==0)break;
        for(int i=1;i<=n;i++){
            scanf("%I64d",&num[i]);
        }
        memset(used,0xff,sizeof(used));
        used[0]=0;
        for(int i=1;i<=n;i++){
            s[i]=(s[i-1]+num[i]) % c;
            if(used[s[i]]!=-1){
                int f=used[s[i]]+1;
                printf("%d",f);
                for(int j=f+1;j<=i;j++)printf(" %d",j);
                printf("\n");
                break;
            }
            used[s[i]]=i;
        }
    }
    return 0;
}
