/*************************************************************************
    > File Name: j 1481.矩阵乘法.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 13:25:03
 ************************************************************************/

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
const int MOD = 9997;
const int N = 1111;

int A[N][N];
int B[N][N];
int C[N][N];
bool haveA[N];
bool haveB[N];


void read(int n,int str[][N]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&str[i][j]);
            str[i][j] %= MOD;
        }
    }
}

bool eq(int i,int j,int sz){
    int tmp=0,k;
    for(k=0;k<sz;k++){
        tmp += A[i][k]*B[k][j];
    }
    return tmp == C[i][j];
}

const int L = 10000;
bool randTest(int sz){
    int i,j,k;
    for(k=0;k<L;k++){
        i = rand()%sz;
        j = rand()%sz;
        if(!eq(i,j,sz))return false;
    }

    return true;
}


int main() {
    int n,i,j,k;
    srand (time(NULL));
    while(~scanf("%d",&n)){
        read(n,A);
        read(n,B);
        read(n,C);
        printf("%s\n",eq(n)?"Yes":"No");

    }
    return 0;
}
