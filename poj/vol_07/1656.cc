#include"iostream"
using namespace std;
int map[101][101];
int main(){
    int t,x,y,l;
    char str[10];
    scanf("%d",&t);
    while(t--){
          scanf(" %s%d%d%d",str,&x,&y,&l);
          if(str[0]=='B'){
              for(int i=x;i<x+l;i++){
                 for(int j=y;j<y+l;j++){
                    map[i][j]=1;
                 }
              }
          }
          else if(str[0]=='W'){
             for(int i=x;i<x+l;i++){
                 for(int j=y;j<y+l;j++){
                    map[i][j]=0;
                 }
              }
          }
          else{
              int cnt=0;
              for(int i=x;i<x+l;i++){
                 for(int j=y;j<y+l;j++){
                    cnt+=map[i][j];
                 }
              }
              printf("%d\n",cnt);
          }
    }
    return 0;
}
