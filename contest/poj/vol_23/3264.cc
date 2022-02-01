#include"iostream"
#include"cmath"
#define MAXN 50001
using namespace std;
int dpm[MAXN][20],dpn[MAXN][20];
int a[MAXN],N;
int max(int a,int b){
   return a>b?a:b;
}
int min(int a,int b){
   return a<b?a:b;
}
void init(){
     int i,j;
     int k=(int)(log((double)(N+1))/log(2.0));
     for(i = 1 ; i <= N ; i++ ){
          dpm[i][0] = a[i];
          dpn[i][0] = a[i];
     }
     for( j = 1 ; j <=k  ; j++ ){
          for( i = 1 ; i+(1<<j)-1 <= N ; i++ ){
               dpm[i][j] = max( dpm[i][j-1] , dpm[i+(1<<(j-1))][j-1] );  
               dpn[i][j] = min( dpn[i][j-1] , dpn[i+(1<<(j-1))][j-1] );  
          }
     }     
}
int getm( int a , int b ){
    int k = (int)(log((double)(b-a+1))/log(2.0));
    return max( dpm[a][k] , dpm[b-(1<<k)+1][k] );    
}
int getn( int a , int b ){
    int k = (int)(log((double)(b-a+1))/log(2.0));
    return min( dpn[a][k] , dpn[b-(1<<k)+1][k] );    
}
int main(){
    int Q,x,y;
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++)scanf("%d",a+i);
    init();
    while(Q--){
       scanf("%d%d",&x,&y);
       printf("%d\n",getm(x,y)-getn(x,y));
    }
   // system("pause");
    return 0;
}
