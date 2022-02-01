#include"iostream"
using namespace std;
char str[5026];
int dp[5026];
int main(){
    int len;
    while(scanf("%s",str)){
       if(str[0]=='0')break;
       memset(dp,0,sizeof(dp));
       dp[0]=1;
       dp[1]=1;
       len=strlen(str);
    //   if(len==1)printf("1\n");
       for(int i=1;i<len;i++){
           if(str[i-1]!='0' && (str[i-1]-'0')*10+str[i]-'0'<=26){
                dp[i+1]+=dp[i-1];
           }
           if(str[i]!='0'){
                dp[i+1]+=dp[i];
           }
       }
       printf("%d\n",dp[len]);
    }
    return 0;
}
