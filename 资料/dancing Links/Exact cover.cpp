//71712 1017 Accepted 1928 kb 268 ms C++ 2157 B 2011-11-14 21:26:16
//矩阵为1000 × 1000
//每一列1的个数最多100
#include<stdio.h>
#include<string.h>
#include<time.h>
#define N 1005
#define V 102005//V可为N*C（或M*N）
int U[V],D[V];
int L[V],R[V];
int C[V];
int H[N],S[N],mark[V];
/*
S[N]为//每列中1的个数
*/
int size,n,m,OK[N],flag;
void Link(int r,int c) {
    S[c]++;
    C[size]=c;
    U[size]=U[c];
    D[U[c]]=size;
    D[size]=c;
    U[c]=size;
    if(H[r]==-1) H[r]=L[size]=R[size]=size;
    else {
        L[size]=L[H[r]];
        R[L[H[r]]]=size;
        R[size]=H[r];
        L[H[r]]=size;
    }
    mark[size]=r;
    size++;
}
void remove(int c) { //删除列
    int i,j;
    L[R[c]]=L[c];
    R[L[c]]=R[c];
    for(i=D[c]; i!=c; i=D[i]) {
        for(j=R[i]; j!=i; j=R[j]) {
            U[D[j]]=U[j],D[U[j]]=D[j];
            S[C[j]]--;
        }
    }
}
void resume(int c) {
    int i,j;
    for(i=U[c]; i!=c; i=U[i]) {
        for(j=L[i]; j!=i; j=L[j]) {
            U[D[j]]=j;
            D[U[j]]=j;
            S[C[j]]++;
        }
    }
    L[R[c]]=c;
    R[L[c]]=c;
}
void Dance(int k) {
    int i,j,Min,c;
    if(!R[0]) {
        flag=1;//标记有解
        printf("%d",k);//输出有k行
        for(i=0; i<k; i++)
            printf(" %d",mark[OK[i]]);
        printf("\n");
        return;
    }
    for(Min=N,i=R[0]; i; i=R[i])
        if(S[i]<Min) Min=S[i],c=i;
    remove(c);//删除该列
    for(i=D[c]; i!=c; i=D[i]) {
        OK[k]=i;
        for(j=R[i]; j!=i; j=R[j])
            remove(C[j]);
        Dance(k+1);
        if(flag) return;//只要一组解
        for(j=L[i]; j!=i; j=L[j])
            resume(C[j]);
    }
    resume(c);
}
int main() {
    int i,j,num;
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(i=0; i<=m; i++) {
            S[i]=0;
            D[i]=U[i]=i;
            L[i+1]=i;
            R[i]=i+1;
        }
        R[m]=0;
        size=m+1;
        memset(H,-1,sizeof(H));
        memset(mark,0,sizeof(mark));
        for(i=1; i<=n; i++) {
            scanf("%d",&num);
            while(num--) {
                scanf("%d",&j);
                Link(i,j);//向第i行第j列插入1
            }
        }
        flag=0;
        Dance(0);
        if(!flag) printf("NO\n");
    }
    return 0;
}
