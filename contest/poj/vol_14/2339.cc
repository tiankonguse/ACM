#include"iostream"
using namespace std;
char map1[101][101],map2[101][101];
char pk(char a,char b){
   if(a==b)return a;
   if(a=='R' && b=='S')return 'R';
   if(a=='S' && b=='R')return 'R';
   if(a=='R' && b=='P')return 'P';
   if(a=='P' && b=='R')return 'P';
   if(a=='S' && b=='P')return 'S';
   if(a=='P' && b=='S')return 'S';
}
int main(){
    int T,N,M,D;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d%d",&N,&M,&D);
       for(int i=0;i<N;i++){
           scanf(" %s",map1[i]);
       }
       memcpy(map2,map1,sizeof(map1));
       for(int i=0;i<D;i++){
              for(int j=0;j<N;j++){
                 for(int k=0;k<M;k++){
                     if(j>0 && pk(map1[j][k],map1[j-1][k])!=map1[j][k])map2[j][k]=map1[j-1][k];
                     if(j<N-1 && pk(map1[j][k],map1[j+1][k])!=map1[j][k])map2[j][k]=map1[j+1][k];
                     if(k>0 && pk(map1[j][k],map1[j][k-1])!=map1[j][k])map2[j][k]=map1[j][k-1];
                     if(k<M-1 && pk(map1[j][k],map1[j][k+1])!=map1[j][k])map2[j][k]=map1[j][k+1];
                 }
              }   
           memcpy(map1,map2,sizeof(map2));
       }

          for(int i=0;i<N;i++){
               for(int j=0;j<M;j++){
                   printf("%c",map1[i][j]);
               }
               printf("\n");
           }
       
       if(T)printf("\n");
    }
    //system("pause");
    return 0;
}
