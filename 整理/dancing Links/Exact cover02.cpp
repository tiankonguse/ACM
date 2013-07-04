/*************************************************************************
    > File Name: Exact cover02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/22 22:09:43
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
const int N = 1005;
const int M = 1005;
const int maxn = N*M;
int R[maxn], L[maxn], U[maxn], D[maxn];
int col[maxn], row[maxn];
int rowHead[M], selectRow[N],colNum[N];
int size,n,m;
bool flag;

void init() {
    memset(rowHead,-1,sizeof(rowHead));
    for(int i=0; i<=m; i++) {
        colNum[i]=0;

        D[i]=U[i]=i;
        L[i+1]=i;
        R[i]=i+1;

        row[i] = 0;
        col[i] = i;
    }
    R[m]=0;
    size=m+1;
}

void insert(int r,int c) {
    colNum[c]++;
    U[size]=U[c];
    D[size]=c;
    D[U[size]]=size;
    U[D[size]]=size;

    if(rowHead[r]==-1) {
        rowHead[r]=L[size]=R[size]=size;
    } else {
        L[size]=L[rowHead[r]];
        R[size]=rowHead[r];
        R[L[size]]=size;
        L[R[size]]=size;
    }
    row[size] = r;
    col[size] = c;
    size++;
}

void remove(int const& c) { //删除列
    int i,j;
    L[R[c]]=L[c];
    R[L[c]]=R[c];
    for(i=D[c]; i!=c; i=D[i]) {
        for(j=R[i]; j!=i; j=R[j]) {
            U[D[j]]=U[j],D[U[j]]=D[j];
            colNum[col[j]]--;
        }
    }
}

void resume(int c) {
    int i,j;
    for(i=U[c]; i!=c; i=U[i]) {
        for(j=L[i]; j!=i; j=L[j]) {
            U[D[j]]=j;
            D[U[j]]=j;
            colNum[col[j]]++;
        }
    }
    L[R[c]]=c;
    R[L[c]]=c;
}

void dfs(int k){
    int i,j,Min,c;
    if(R[0] == 0) {
        flag = true;//标记有解
        printf("%d",k);//输出有k行
        for(i=0; i<k; i++){
            printf(" %d",selectRow[i]);
        }
        printf("\n");
        return;
    }

    //select a col that has min 1
    for(Min=N,i=R[0]; i; i=R[i]){
        if(colNum[i]<Min){
            Min=colNum[i],c=i;
        }
    }
    remove(c);//删除该列

    //select a row in the delete col
    for(i=D[c]; i!=c; i=D[i]) {
        selectRow[k] = row[i];
        for(j=R[i]; j!=i; j=R[j]){
            remove(col[j]);
        }
        dfs(k+1);
        if(flag) return;//只要一组解
        for(j=L[i]; j!=i; j=L[j]){
            resume(col[j]);
        }
    }
    resume(c);

}
int main() {
    int i,j,num;
    while(scanf("%d%d",&n,&m)!=EOF) {
        init();
        for(i=1; i<=n; i++) {
            scanf("%d",&num);
            while(num--) {
                scanf("%d",&j);
                insert(i,j);//向第i行第j列插入1
            }
        }
        flag = false;
        dfs(0);
        if(!flag){
            printf("NO\n");
        }
    }
    return 0;
}
