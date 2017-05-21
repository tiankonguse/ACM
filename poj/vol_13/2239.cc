#include"iostream"
#include"cstdlib"
#define MAXN 305
using namespace std;
int N,M;
bool mat[MAXN][MAXN],fy[MAXN];
int matx[MAXN],maty[MAXN];
int path(int u){
   int v;
   for(v=0;v<M;v++){
       if(mat[u][v] && !fy[v]){
          fy[v]=1;
          if(maty[v]<0 || path(maty[v])){
             matx[u]=v;
             maty[v]=u;
             return 1;
          }
       }
   }
   return 0;
}
int hungary(){
    int res=0;
    memset(matx,0xff,sizeof(matx));
    memset(maty,0xff,sizeof(maty));
    for(int i=0;i<N;i++){
       if(matx[i]<0){
          memset(fy,false,sizeof(fy));
          res+=path(i);
       }
    }
    return res;
}
int main(){
    M=100;
    int k,p,q;
    while(~scanf("%d",&N)){
        memset(mat,false,sizeof(mat));
        for(int i=0;i<N;i++){
          scanf("%d",&k);
          while(k--){
             scanf("%d%d",&p,&q);
             mat[i][p*12+q]=true;
          }
        }
        printf("%d\n",hungary());
    }
    return 0;
}
