#include"iostream"
#include"cstdlib"
#define MAXN 130
using namespace std;
int N,M;
bool mat[MAXN][MAXN],fy[MAXN];
int matx[MAXN],maty[MAXN];
int path(int u){
    int v;
    for(v=1;v<=N;v++){
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
    for(int i=1;i<=N;i++){
       if(matx[i]<0){
          memset(fy,false,sizeof(fy));
          res+=path(i);
       }
    }
    return res;
}

int main(){
    int T,a,b;
    scanf("%d",&T);
    while(T--){
       memset(mat,false,sizeof(mat));
       scanf("%d%d",&N,&M);
       while(M--){
          scanf("%d%d",&a,&b);
          mat[a][b]=true;
       }
       printf("%d\n",N-hungary());
    }
    return 0;
}
