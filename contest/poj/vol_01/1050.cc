#include"iostream"
#include"cstdlib"
using namespace std;
int main(){
    int N,m=-200000;
    int a[101][101];
    int dp[101],temp[101];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
       for(int j=0;j<N;j++){
           scanf("%d",&a[i][j]);
       }
    }
    for(int i=0;i<N;i++){
       memset(temp,0,sizeof(temp));
       for(int j=i;j<N;j++){
           for(int k=0;k<N;k++){
              temp[k]+=a[j][k];
           }
           dp[0]=temp[0];
           int max=dp[0];
           for(int k=1;k<N;k++){
              dp[k]=temp[k];
              if(dp[k-1]>0)dp[k]+=dp[k-1];
              if(dp[k]>max)max=dp[k];
           }
           if(max>m)m=max;
       }
    }
    printf("%d\n",m);
 //   system("pause");
    return 0;
}
