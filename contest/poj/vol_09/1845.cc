#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 2
using namespace std;
int P=9901;
struct matrix{
    int N;
    long long mat[MAXN][MAXN];
}A;
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
matrix operator ^(matrix A,long long n){
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
long long fun(long long a,long long b){
    A.N=2;
    A.mat[0][0]=a;A.mat[0][1]=1;
    A.mat[1][0]=0;A.mat[1][1]=1;
    A=A^(b+1);
    return A.mat[0][1];
}
long long solve(long long a,long long b){
    long long cnt,res=1;
    for(int i=2;i<=8000;i++){
        if(a%i==0){
            cnt=0;
            while(a%i==0){
                a/=i;
                cnt++;
            }
            res=res*fun(i,cnt*b)%P;
        }
        if(a==1)break;
    }
    if(a!=1)res=res*fun(a,b)%P;
    return res;
}
int main(){
    long long a,b;
    while(~scanf("%lld%lld",&a,&b)){
        if(a==0)printf("0\n");
        else if(a==1)printf("1\n");
        else{
            printf("%lld\n",solve(a,b));
        }
    }
    return 0;
}
