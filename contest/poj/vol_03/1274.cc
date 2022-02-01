#include"iostream"
#include"cstdlib"
#define MAXN 205
using namespace std;
int matx[MAXN],maty[MAXN];
bool fy[MAXN],mat[MAXN][MAXN];
int N,M;

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
    int t,a;
    while(~scanf("%d%d",&N,&M)){
        memset(mat,false,sizeof(mat));
        for(int i=0;i<N;i++){ 
           scanf("%d",&t);
           while(t--){
              scanf("%d",&a);
              mat[i][a-1]=true;
           }
        }
        printf("%d\n",hungary());
    }
    return 0;
}
