#include"iostream"
#define MAXN 16
#define FULL 15
using namespace std;
int K,P;
int check[5]={0,3,6,12,15};//0000,0011,0110,1100,1111
struct matrix{
    int N;
    int mat[MAXN][MAXN];
    void init();
}A,B;
void matrix::init(){
    N=16;
    memset(mat,0,sizeof(mat));
    for(int i=0;i<=FULL;i++){
        for(int j=0;j<=FULL;j++){
          //  printf("i=%d,(~i)&FULL=%d\n",i,(~i)&FULL);
          //  printf("j=%d,(~i)&j=%d\n",j,(~i)&j);
            if(((~i)&FULL)==((~i)&j)){
                  for(int k=0;k<5;k++){
                      if((i&j)==check[k]){
                         mat[i][j]=1;
                         break;
                      }
                  }
            }
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
int main(){
    A.init();
   // print(A);
    while(~scanf("%d%d",&K,&P) && K){
        B=A^K;
        printf("%d\n",B.mat[15][15]);
    }
    system("pause");
    return 0;
}
