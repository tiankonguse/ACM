#include"iostream"
#include"cstdio"
#include"cstdlib"
#define MAXN 505
using namespace std;
bool mat[MAXN][MAXN],fy[MAXN];
int matx[MAXN],maty[MAXN];
int N;
int path(int u){
    int v;
    for(v=0;v<N;v++){
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
int ab(int x){
   return x>0?x:-x;
}
int ti[MAXN][2];
int pos[MAXN][4];
int main(){
    int T,h,m;
    scanf("%d",&T);
    while(T--){
       memset(mat,false,sizeof(mat));
       scanf("%d",&N);
       for(int i=0;i<N;i++){
          scanf("%d:%d %d%d%d%d",&h,&m,&pos[i][0],&pos[i][1],&pos[i][2],&pos[i][3]);
          ti[i][0]=h*60+m;
          ti[i][1]=ti[i][0]+ab(pos[i][0]-pos[i][2])+ab(pos[i][1]-pos[i][3]);          
       }
       for(int i=0;i<N;i++){
          for(int j=i+1;j<N;j++){
             if(ti[i][1]+ab(pos[j][0]-pos[i][2])+ab(pos[j][1]-pos[i][3])<ti[j][0]){
               mat[i][j]=true;
             }
          }
       }
       printf("%d\n",N-hungary());
    }
    //system("pause");
    return 0;
}
