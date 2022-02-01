#include"iostream"
#include"cstdlib"
#define MAXN 501
using namespace std;
int N;
int matx[MAXN],maty[MAXN];
bool mat[MAXN][MAXN],fy[MAXN];
int path(int u){
    for(int i=1;i<=N;i++){
        if(mat[u][i] && !fy[i]){
            fy[i]=true;
            if(maty[i]==-1 || path(maty[i])){
                maty[i]=u;
                matx[u]=i;
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
    int K,a,b;
    scanf("%d%d",&N,&K);
    while(K--){
        scanf("%d%d",&a,&b);
        mat[a][b]=true;
    }
    printf("%d\n",hungary());
    //system("pause");
    return 0;
}
