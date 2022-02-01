#include"iostream"
#define MAXN 4
using namespace std;
const int P=10007;
struct matrix{
    int N;
    int mat[MAXN][MAXN];
    void init();
}A,B;
void matrix::init(){
    N=4;
    mat[0][0]=2;mat[0][1]=1;mat[0][2]=1;mat[0][3]=0;
    mat[1][0]=1;mat[1][1]=2;mat[1][2]=0;mat[1][3]=1;
    mat[2][0]=1;mat[2][1]=0;mat[2][2]=2;mat[2][3]=1;
    mat[3][0]=0;mat[3][1]=1;mat[3][2]=1;mat[3][3]=2;
}
matrix operator +(matrix A,matrix B){
    matrix C;
    C.N=A.N;
    for(int i=0;i<A.N;i++){
        for(int j=0;j<A.N;j++){
            C.mat[i][j]=(A.mat[i][j]+B.mat[i][j])%P;
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
                   C.mat[i][k]=(C.mat[i][k]+A.mat[i][j]*B.mat[j][k])%P;
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
matrix convert(matrix A){
    matrix C;
    C.N=A.N*2;
    memset(C.mat,0,sizeof(C.mat));
    for(int i=0;i<A.N;i++){
        for(int j=0;j<A.N;j++){
            C.mat[i][j]=A.mat[i][j];
        }
    }
    for(int i=0;i<A.N;i++){
        C.mat[i][A.N+i]=1;
        C.mat[A.N+i][A.N+i]=1;
    }
    return C;
}
int main(){
    int T,K;
    A.init();
  //  print(A);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&K);
        printf("%d\n",(A^K).mat[0][0]);
    }
    system("pause");
    return 0;
}
