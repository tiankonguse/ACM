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
#define maxn 105
using namespace std;
typedef __int64 ll;

int const P = 10000LL;
struct matrix{
    int N;
    ll mat[maxn][maxn];
    void init(int n){
        N = n;
        memset(mat, 0, sizeof mat);
        for (int i = 0; i < n - 1; ++i) {
            mat[i][i + 1] = 1;
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
    matrix operator ^(int n){ // (*this) will be changed!
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
}A,B,C,D;

ll a[maxn], b[maxn];
int main() {
    int n, m;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%I64d", &b[i]);
        scanf("%d", &m);
        if (m < n) { printf("%I64d\n", a[m]); continue; }
        A.init(n);
        for (int i = 0; i < n; ++i) A.mat[n - 1][i] = b[n - i - 1];
//        A.print();
        B = A ^ m;
//        B.print();
        C.N = n; memset(C.mat, 0, sizeof C);
        for (int i = 0; i < n; ++i) C.mat[i][0] = a[i];
        D = B * C;
//        D.print();
        printf("%I64d\n", D.mat[0][0]);
    }
    return 0;
}
