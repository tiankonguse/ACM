#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 10 + 2
using namespace std;

struct matrix{
    int N;
    double mat[maxn][maxn];
    void init(int n){
        N = n;
    }
    matrix operator+(matrix B){
        matrix C;
        C.N=N;
        for(int i=0;i<N;i++){
            for(int j=0;j<B.N;j++){
                C.mat[i][j]=(mat[i][j]+B.mat[i][j]);
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
                       C.mat[i][k]=(C.mat[i][k]+mat[i][j]*B.mat[j][k]);
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
}A,B,T,C;

double mat[maxn][maxn];
int main(){
    int n = 0;
    string s;
    getline(cin, s);
    istringstream is(s);
    while(is >> mat[0][n]) n++;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    A.init(n);
    double t ;
    for(int i=0;i<n;i++){
        t = 0;
        for(int j=0;j<n;j++) t += mat[i][j];
        for(int j=0;j<n;j++){
            A.mat[i][j] = mat[i][j] / t;
        }
    }
    B.init(n);
    B.mat[0][0] = 1.0;
    for(int i=0;i<10;i++){
        T = A;
        C = B * (T ^ i);
        for(int j=0;j<n;j++){
            if(j == n - 1) printf("%.5lf\n", C.mat[0][j]);
            else printf("%.5lf ", C.mat[0][j]);
        }
    }
    return 0;
}
