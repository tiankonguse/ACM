#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1001
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int N,sum,cost[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        sum=0;
        for(int i=0;i<N;i++){
            scanf("%d",&cost[i]);
            sum+=cost[i];
        }
        sort(cost,cost+N);
        if(N<=2)printf("%d\n",cost[N-1]);
        else if(N==3)printf("%d\n",sum);
        else{
            int p=N-1,s=0;
            while(p>2){
                s+=min(2*cost[0]+cost[p]+cost[p-1],cost[0]+2*cost[1]+cost[p]);
                p-=2;
            }
            if(p==1)s+=cost[1];
            else s+=cost[0]+cost[1]+cost[2];
            printf("%d\n",s);
        }
    }
    return 0;
}
