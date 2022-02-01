#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 11
using namespace std;
int P = 2007; 
struct matrix{
    int N;
    int mat[maxn][maxn];
    void init(int n){
        N = n;
        memset(mat, 0, sizeof mat);
        for (int i = 0; i < n; ++i) {
            mat[i][i] = i + 1;
            if (i > 0) mat[i][i - 1] = 1;
        } 
    }
    matrix operator+(matrix B){
        matrix C;
        C.N=N;
        for(int i=0;i<N;i++){
            for(int j=0;j<B.N;j++){
                C.mat[i][j]=(mat[i][j]+B.mat[i][j])%P;
            }
        }
        return C;
    }
    matrix operator *(matrix B){
        matrix C;
        C.N=N;
        memset(C.mat,0,sizeof(C.mat));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mat[i][j]){
                   for(int k=0;k<N;k++){
                       C.mat[i][k]=(C.mat[i][k]+mat[i][j]*B.mat[j][k])%P;
                   }
                }
            }
        }
        return C;
    }
    matrix operator ^(int n){
        matrix C;
        C.N=N;
        memset(C.mat,0,sizeof(C.mat));
        for(int i=0;i<N;i++)C.mat[i][i]=1;
        while(n){
            if(n&1)C=C*(*this);
            *this=(*this)*(*this);
            n>>=1;
        }
        return C;
    }
    void print(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j == N - 1) cout<<mat[i][j]<<endl;
                else cout<<mat[i][j]<<" ";
            }
        }
    }
}A,B,C;
int main() {
    int n, k;
    while (~scanf("%d%d", &n, &k)) {
        A.init(k);
        C =  (A ^ (n - 1));
        printf("%d\n", C.mat[k - 1][0]);
    }
    return 0;
}

