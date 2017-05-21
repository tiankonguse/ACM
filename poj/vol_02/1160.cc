#include"iostream"
using namespace std;
int dp[31][301],cost[301][301];
int dist[301];
int main(){
    int V,P,mid;
    while(~scanf("%d%d",&V,&P)){
       for(int i=0;i<V;i++){
           scanf("%d",&dist[i]);
       }
       for(int i=0;i<V;i++){
          for(int j=i;j<V;j++){
              mid=(i+j)>>1;
              for(int k=i;k<mid;k++)cost[i][j]+=dist[mid]-dist[k];
              for(int k=mid+1;k<=j;k++)cost[i][j]+=dist[k]-dist[mid];  
        //      printf("%d ",cost[i][j]);
          }
       //   printf("\n");
       }
       for(int i=0;i<V;i++)dp[1][i]=cost[0][i];
       int min;
       for(int i=2;i<=P;i++){
           for(int j=i-1;j<V;j++){
              min=INT_MAX;
              for(int k=i-1;k<j;k++){
              //   printf("dp[%d][%d]+cost[%d][%d]\n",i-1,k,k+1,j);
                 if(dp[i-1][k]+cost[k+1][j]<min)min=dp[i-1][k]+cost[k+1][j];
              }
             // printf("dp[%d][%d]=%d\n",i,j,min);
              dp[i][j]=min;
           }
       }
       printf("%d\n",dp[P][V-1]);
    }
    return 0;    
}
