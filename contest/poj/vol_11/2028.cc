#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXD 105
using namespace std;
int cnt[MAXD];
int main(){
    int N,M,Q,a,res,mx;
    while(scanf("%d%d",&N,&Q)&& N){
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<N;i++){
            scanf("%d",&M);
            for(int j=0;j<M;j++){
                scanf("%d",&a);
                cnt[a]++;
            }
        }
        res=0;
        mx=0;
        for(int i=1;i<=100;i++){
            if(cnt[i]>=Q && cnt[i]>mx){
                mx=cnt[i];
                res=i;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
