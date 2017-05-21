#include"iostream"
#define MAXN 61
using namespace std;
int K,P;
struct matrix{
    int N;
    int mat[MAXN][MAXN];
    void init();
}A,B;
void matrix::init(){
    scanf("%d%d%d",&N,&K,&P);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&mat[i][j]);
        }
    }
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
            for(int k=0;k<A.N;k++){
                C.mat[i][j]=(C.mat[i][j]+A.mat[i][k]*B.mat[k][j])%P;
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
    A.init();
   // print(A);
    B=convert(A);
  //  print(B);
    B=B^(K+1);
  //  print(B);
    for(int i=0;i<A.N;i++){
        for(int j=A.N;j<B.N;j++){
            if(j==B.N-1){
                if(j-A.N==i)printf("%d\n",(B.mat[i][j]+P-1)%P);
                else printf("%d\n",B.mat[i][j]);
            }
            else{
                if(j-A.N==i)printf("%d ",(B.mat[i][j]+P-1)%P);
                else printf("%d ",B.mat[i][j]);
            }
        }
    }
    //system("pause");
    return 0;
}
