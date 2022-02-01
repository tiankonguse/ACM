#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1001
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int N,sum,cost[MAXN];
int output[MAXN][6];
int main(){
    while(~scanf("%d",&N)){
        sum=0;
        for(int i=0;i<N;i++){
            scanf("%d",&cost[i]);
            sum+=cost[i];
        }
        sort(cost,cost+N);
        if(N==1)printf("%d\n%d\n",cost[N-1],cost[N-1]);
        else if(N==2){
            printf("%d\n%d %d\n",cost[1],cost[0],cost[1]);
        }
        else if(N==3){
            printf("%d\n%d %d\n%d\n%d %d\n",sum,
                    cost[0],cost[1],cost[0],cost[0],cost[2]);
        }
        else{
            int p=N-1,s=0,a,b,cnt=0;;
            while(p>2){
                a=2*cost[0]+cost[p]+cost[p-1];
                b=cost[0]+2*cost[1]+cost[p];
                if(a<b){
                    s+=a;
                    output[cnt][0]=0;
                    output[cnt][1]=p-1;
                    output[cnt][2]=0;
                    output[cnt][3]=0;
                    output[cnt][4]=p;
                    output[cnt][5]=0;
                  //  printf("%d %d\n%d\n%d %d\n%d\n",cost[0],cost[p-1],cost[0],cost[0],cost[p],cost[0]);
                }
                else{
                    s+=b;
                    output[cnt][0]=0;
                    output[cnt][1]=1;
                    output[cnt][2]=0;
                    output[cnt][3]=p-1;
                    output[cnt][4]=p;
                    output[cnt][5]=1;
                  //  printf("%d %d\n%d\n%d %d\n%d\n",cost[0],cost[1],cost[0],cost[p-1],cost[p],cost[1]);
                }
                cnt++;
                p-=2;
            }
            if(p==1)s+=cost[1];
            else s+=cost[0]+cost[1]+cost[2];
            printf("%d\n",s);
            for(int i=0;i<cnt;i++){
                printf("%d %d\n%d\n%d %d\n%d\n",cost[output[i][0]],cost[output[i][1]],cost[output[i][2]],
                                                cost[output[i][3]],cost[output[i][4]],cost[output[i][5]]);
            }
            if(p==1)printf("%d %d\n",cost[0],cost[1]);
            else printf("%d %d\n%d\n%d %d\n",cost[0],cost[1],cost[0],cost[0],cost[2]);
        }
    }
    return 0;
}
