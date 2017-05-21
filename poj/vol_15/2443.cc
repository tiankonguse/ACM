#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 10005
using namespace std;
int mark[MAXN][35];
int main(){
    int N,Q,k,a,b;
    while(~scanf("%d",&N)){
        memset(mark,0,sizeof(mark));
        for(int i=0;i<N;i++){
            scanf("%d",&k);
            for(int j=0;j<k;j++){
                scanf("%d",&a);
                mark[a][i/32] |= (1<<(i%32));
            }
        }
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%d%d",&a,&b);
            bool flag=false;
            for(int i=0;i<32;i++){
                if((mark[a][i]&mark[b][i])){
                    flag=true;
                    break;
                }
            }
            if(flag)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
