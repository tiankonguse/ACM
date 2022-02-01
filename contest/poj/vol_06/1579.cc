#include"iostream"
using namespace std;
int w[21][21][21];
int fun(int a,int b,int c){
  if(a<=0 || b<=0 || c<=0)return 1;
  else if(a>20 || b>20 || c>20)return w[20][20][20];
  else if(a<b && b<c) return w[a][b][c-1]+w[a][b-1][c-1]-w[a][b-1][c];
  else return w[a-1][b][c]+w[a-1][b-1][c]+w[a-1][b][c-1]-w[a-1][b-1][c-1];
}
int main(){
    int a,b,c;
    w[0][0][0]=1;
    for(int i=0;i<=20;i++){
       for(int j=0;j<=20;j++){
          for(int k=0;k<=20;k++){
             w[i][j][k]=fun(i,j,k);
          }
       }
    }
    while(scanf("%d%d%d",&a,&b,&c)){
       if(a==-1 && b==-1 && c==-1)break;
       else printf("w(%d, %d, %d) = %d\n",a,b,c,fun(a,b,c));
    }
    return 0;
}
