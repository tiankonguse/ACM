/*************************************************************************
    > File Name: 矩阵.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/21 16:22:37
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
#define TT int
const int N=12;
const int sz = 7;
int mod;

int str[7][7]=
{
 {1,1, 1, 1, 1, 0}
,{1,0, 0, 1, 0, 0}
,{1,0, 0, 0, 0, 1}
,{1,1, 0, 0, 0, 0}
,{1,0, 0, 0, 0, 0}
,{0,0, 1, 0, 0, 0}
};

struct Matrix {
    TT a[N][N];
    Matrix() {
        memset(a,0,sizeof(a));
    }
    void _union() {
        int l=sz;
        while(l--)a[l][l]=1;
    }
    void init(int _a[][7]){
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                a[i][j] = _a[i][j];
            }
        }
    }
    Matrix operator*(Matrix& B);
    Matrix pow(TT k);
};
Matrix Matrix::operator*(Matrix& B) {
    Matrix ret;
    for(int i=0; i<sz; i++)
        for(int j=0; j<sz; j++)
            for(int k=0; k<sz; k++)
                ret.a[i][j]=(ret.a[i][j]+a[i][k]*B.a[k][j]) %mod;
    return ret;
}

Matrix Matrix::pow(TT k) {
    Matrix ret;
    Matrix A=*this;
    ret._union();

    while(k) {
        if(k&1)ret=ret*A;
        A=A*A;
        k>>=1;
    }
    return ret;
}
int main() {
    Matrix matrix,ans;
    int n,m;
    matrix.init(str);
    while(~scanf("%d%d",&n,&m),n){
        mod = m;
//        puts("--");
        ans = matrix.pow(n);
        printf("%d\n",ans.a[0][0]);
    }

    return 0;
}
/*


*/
