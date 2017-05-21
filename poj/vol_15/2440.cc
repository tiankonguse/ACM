#include"iostream"
#define MAXN 4
using namespace std;
int K;
const int P=2005;
struct matrix{
    int N;
    int mat[MAXN][MAXN];
    void init();
}A,B;
void print(matrix a){
    for(int i=0;i<a.N;i++){
        for(int j=0;j<a.N;j++){
            if(j==a.N-1)printf("%d\n",a.mat[i][j]);
            else printf("%d ",a.mat[i][j]);
        }
    }
}
void matrix::init(){
    A.N=4;
    memset(mat,0,sizeof(mat));
    for(int i=0;i<3;i++){
            mat[i][i+1]=1;
    }
    mat[0][0]=mat[2][0]=mat[3][0]=1;
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
        if(n&1){
            C=C*A;
        }
        A=A*A;
        n>>=1;
    }
    return C;
}
int f[5]={-1,2,4,6,9};
int main(){
    A.init();
    while(~scanf("%d",&K)){
        if(K<=4)printf("%d\n",f[K]%P);
        else{
            B=A^(K-4);
            printf("%d\n",(B.mat[0][0]*9+B.mat[1][0]*6+
                          B.mat[2][0]*4+B.mat[3][0]*2)%P);
        }
    }
   // system("pause");
    return 0;
}
