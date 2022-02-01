#include"iostream"
#include"cstdlib"
using namespace std;
int map[101];
int ava[60],acnt;
int countbit[1024];
int N,M;
char str[12];
int dp[101][60][60];
int max(int a,int b){
    return a>b?a:b;
}
void init(){
    int t;
    bool flag;
    acnt=0;
    countbit[0]=0;
    for(int i=1;i<1024;i++){
        countbit[i]=1+countbit[i-((i^(i-1))&i)];
    }
    for(int i=0;i<1024;i++){
       flag=true;
       t=i;
       while(t){
         if((t&3)==3||(t&5)==5){
            flag=false;
            break;
         }
         t>>=1;
       }
       if(flag)ava[acnt++]=i;
    }
}
int main(){
    init();
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf(" %s",str);
        for(int j=0;j<M;j++){
           map[i]<<=1;
           if(str[j]=='H')map[i]+=1;
        }
    }
    int mn=1<<M;
    int cnt=acnt;
    for(int i=0;i<acnt;i++){
       if(ava[i]>=mn){
          cnt=i;
          break;
       }
    }
    for(int i=1;i<=N;i++){
       for(int j=0;j<cnt;j++){
          if(ava[j]&map[i])continue;
          for(int k=0;k<cnt;k++){
             if((ava[k]&map[i-1])||(ava[k]&ava[j]))continue;
             for(int l=0;l<cnt;l++){
                if((ava[l]&map[i-2])||(ava[l]&ava[j])||(ava[l]&ava[j]))continue;
                dp[i][k][j]=max(dp[i][k][j],dp[i-1][l][k]+countbit[ava[j]]);
             }
          }
       }
    }
    int res=0;
    for(int i=0;i<cnt;i++){
       for(int j=0;j<cnt;j++){
         if(dp[N][i][j]>res)res=dp[N][i][j];
       }
    }
    printf("%d\n",res);
   // system("pause");
    return 0;
}
