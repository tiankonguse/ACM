#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1050
using namespace std;
bool mat[MAXN][MAXN];
int matx[MAXN],maty[MAXN];
bool fy[MAXN];
int N,M;
void floyd(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            if(k==i)continue;
            for(int j=0;j<N;j++){
                mat[i][j] |= (mat[i][k] & mat[k][j]);
            }
        }
    }
}
int path(int u){
    for(int v=0;v<N;v++){
        if(mat[u][v] && !fy[v]){
            fy[v]=true;
            if(maty[v]==-1 || path(maty[v])){
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
        if(matx[i]==-1){
            memset(fy,false,sizeof(fy));
            res+=path(i);
        }
    }
    return res;
}
int main(){
    int a,b;
    while(scanf("%d%d",&N,&M),N+M){
        memset(mat,false,sizeof(mat));
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            a--,b--;
            mat[a][b]=true;
        }
        floyd();
        printf("%d\n",N-hungary());
    }
    return 0;
}
