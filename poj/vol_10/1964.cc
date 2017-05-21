#include"iostream"
#include"cstdio"
#include"cstdlib"
#include"string"
#define MAXN 1002
using namespace std;
int h[MAXN][MAXN];
int l[MAXN],r[MAXN];
int main(){
    char c;
    int T,N,M,area,res;
    scanf("%d",&T);
    while(T--){
       scanf("%d %d",&N,&M);
       for(int i=1;i<=N;i++){
           for(int j=1;j<=M;j++){
               scanf(" %c",&c);
               if(c=='R')h[i][j]=0;
               else h[i][j]=h[i][j-1]+1;
           }
       }
       res=0;
       for(int j=1;j<=M;j++){
           for(int i=1;i<=N;i++){
               l[i]=r[i]=i;
           }
           h[0][j]=h[N+1][j]=-1;
           for(int i=1;i<=N;i++){
               while(h[l[i]-1][j]>=h[i][j]){
                   l[i]=l[l[i]-1];
               }
           }
           for(int i=N;i>=1;i--){
               while(h[r[i]+1][j]>=h[i][j]){
                   r[i]=r[r[i]+1];
               }
           }
           for(int i=1;i<=N;i++){
               area=(r[i]-l[i]+1)*h[i][j];
               if(area>res)res=area;
           }
       }
       printf("%d\n",res*3);
    }
  //  system("pause");
    return 0;
}
