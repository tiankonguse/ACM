#include"iostream"
#include"cstdlib"
using namespace std;
char str[35];
int num[35][35];
__int64 dp[35][35];
int main(){
    int N;
    while(scanf("%d",&N)){
        if(N==-1)break;
        for(int i=0;i<N;i++){
            scanf("%s",str);
            for(int j=0;j<N;j++){
               num[i][j]=(int)(str[j]-'0');
            }
        }
        
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<N;i++){
           for(int j=0;j<N;j++){
              if(num[i][j]==0)continue;
              if(dp[i][j]>0){
                 if(i+num[i][j]<N)dp[i+num[i][j]][j]+=dp[i][j];
                 if(j+num[i][j]<N)dp[i][j+num[i][j]]+=dp[i][j];
              }
           }
        }
     /*   for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }*/
        printf("%I64d\n",dp[N-1][N-1]);
    }
    return 0;
}
