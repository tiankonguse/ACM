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
struct matrix{
    int N;
    double mat[maxn][maxn];
    void init(int n){
        N = n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = 0;
            }
        }
    }
    matrix operator *(matrix B){
        matrix C;
        C.init(N);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mat[i][j] > 0){
                    for(int k=0;k<N;k++){
                        C.mat[i][k] += mat[i][j] * B.mat[j][k];
                    }
                }
            }
        }
        return C;
    }
    matrix operator ^(int n){
        matrix C;
        C.init(N);
        for(int i=0;i<N;i++) C.mat[i][i] = 1.0;
        while(n){
            if(n & 1) C = C * (*this);
            *this = (*this) * (*this);
            n >>= 1;
        }
        return C;
    }
    void print(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j == N - 1) printf("%.3lf\n", mat[i][j]);
                else printf("%.3lf ", mat[i][j]);
            }
        }
    }
}A, B, C;
int main(){
    int c, n, m;
    while(scanf("%d", &c) && c){
        scanf("%d%d", &n, &m);
        if(n < m || m > c){ puts("0.000"); continue;}
        A.init(c + 1);
        A.mat[0][1] = 1.0; A.mat[c][c-1] = 1.0;
        for(int i=1;i<c;i++){
            A.mat[i][i-1] = 1.0 * i / c;
            A.mat[i][i+1] = 1.0 - A.mat[i][i-1];
        }
        B.init(c + 1);
        B.mat[0][0] = 1.0;
        C = B * (A ^ n);
        printf("%.3f\n", C.mat[0][m]);
    }
    return 0;
}
