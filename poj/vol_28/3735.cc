#include"iostream"
#define MAXN 101
using namespace std;
int NN,M,K;
struct matrix{
    int N;
    __int64 mat[MAXN][MAXN];
    void init();
}A,B;
void matrix::init(){
    char c;
    int x,y,t;
    A.N=NN+1;
    memset(mat,0,sizeof(mat));
    for(int i=0;i<N;i++)mat[i][i]=1;
    while(K--){
        scanf(" %c",&c);
        if(c=='g'){
            scanf("%d",&x);
            x--;
            mat[x][N-1]++;
        }
        else if(c=='e'){
            scanf("%d",&x);
            x--;
            for(int i=0;i<N;i++){
                mat[x][i]=0;
            }
        //    mat[x][x]=1;
        }
        else{
            scanf("%d%d",&x,&y);
            x--;y--;
            if(x==y)continue;
            for(int i=0;i<N;i++){
                t=mat[x][i];
                mat[x][i]=mat[y][i];
                mat[y][i]=t;
            }
        }
    }
}
matrix operator +(matrix A,matrix B){
    matrix C;
    C.N=A.N;
    for(int i=0;i<A.N;i++){
        for(int j=0;j<A.N;j++){
            C.mat[i][j]=A.mat[i][j]+B.mat[i][j];
        }
    }
    return C;
}
matrix operator *(matrix A,matrix B){
    matrix C;
    C.N=A.N;
    memset(C.mat,0,sizeof(C.mat));
    for(int i=0;i<A.N;i++){
        for(int j=0;j<A.N;j++){
            if(A.mat[i][j]){
                for(int k=0;k<A.N;k++){
                    C.mat[i][k]+=A.mat[i][j]*B.mat[j][k];
                }
            }
        }
    }
    return C;
}
matrix operator ^(matrix A,int n){
    matrix C;
    C.N=A.N;
    memset(C.mat,0,sizeof(C.mat));
    for(int i=0;i<C.N;i++)C.mat[i][i]=1;
    while(n){
        if(n&1)C=C*A;
        A=A*A;
        n>>=1;
    }
    return C;
}
void print(matrix a){
    for(int i=0;i<a.N;i++){
        for(int j=0;j<a.N;j++){
            if(j==a.N-1)printf("%d\n",a.mat[i][j]);
            else printf("%d ",a.mat[i][j]);
        }
    }
}
int main(){
    while(~scanf("%d%d%d",&NN,&M,&K)&&NN){
        A.init();
        B=A^M;
        for(int i=0;i<B.N-1;i++){
            if(i==B.N-2)printf("%I64d\n",B.mat[B.N-2][B.N-1]);
            else printf("%I64d ",B.mat[i][B.N-1]);
        }
    }
   // system("pause");
    return 0;
}
