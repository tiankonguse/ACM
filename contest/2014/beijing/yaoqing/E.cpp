/*************************************************************************
    > File Name: L - 柯南堆积木问题.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/21 17:17:38
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
typedef unsigned long long TT;
const int N=11;
int sz=11;
const int mod = 20140518;

int str[N][N];


void bornState() {
    memset(str,0,sizeof(str));
    str[0][1] = sz;
    for(int i=1;i<sz;i++){
		for(int j=0;j<=i;j++){
			if(j){
				str[i][j] = 1;
			}else{
				if(j + 1 != sz){
					str[i][i+1] = sz - i;
				}
			}
		}
    }
}


struct Matrix {
    TT a[N][N];
    Matrix() {
        memset(a,0,sizeof(a));
    }
    void _union() {
        int l=sz;
        while(l--)a[l][l]=1;
    }
    void init(int _a[][N]) {
        for(int i=0; i<sz; i++) {
            for(int j=0; j<sz; j++) {
                a[i][j] = _a[i][j];
            }
        }
    }
    Matrix operator*(Matrix& B);
    Matrix pow(TT k);
    void output(){
		for(int i=0;i<sz;i++){
			for(int j=0;j<sz;j++){
				printf("%llu ",a[i][j]);
			}
			puts("");
		}
    }
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
    TT n, tmp;
    int k,t=1;
    scanf("%d",&k);
    while(~scanf("%llu%d",&n,&k)) {
    	k++;
    	sz = k;
    	bornState();
    	matrix.init(str);
        ans = matrix.pow(n);
        //ans.output();
        tmp = 0;
        for(int i=0;i<sz;i++){
			tmp += ans.a[0][i];
			tmp = tmp % mod;
        }

        printf("Case #%d: %llu\n",t++,tmp);
    }




    return 0;
}
