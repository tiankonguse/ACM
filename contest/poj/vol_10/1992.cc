#include"iostream"
using namespace std;
char map[1001][1001];
__int64 dp[1001][1001];
int main(){
    int T,R,S;
    bool flag;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&R,&S);
        for(int i=0;i<R;i++)scanf("%s",map[i]);
        flag=true;
        for(int i=0;i<R;i++){
            if(map[i][0]=='#'){
               flag=false;
            }
            if(flag)dp[i][0]=1;
            else dp[i][0]=0;
        }
        flag=true;
        for(int j=0;j<S;j++){
            if(map[0][j]=='#'){
               flag=false;
            }
            if(flag)dp[0][j]=1;
            else dp[0][j]=0;
        }
        for(int i=1;i<R;i++){
            for(int j=1;j<S;j++){
               if(map[i][j]=='#')dp[i][j]=0;
               else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        printf("Existuje %I64d ruznych cest.\n",dp[R-1][S-1]);
    }
  //  system("pause");
    return 0;
}
