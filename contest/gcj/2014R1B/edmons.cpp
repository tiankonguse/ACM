//多源最小树形图,edmonds算法,邻接阵形式,复杂度 O(n^3)                            
//返回最小生成树的长度,构造失败返回负值
//传入图的大小 n和邻接阵 mat,不相邻点边权 inf
//可更改边权的类型,pre[]返回树的构造,用父结点表示
//传入时 pre[]数组清零,用-1标出可能的源点
#include <string.h>
#define MAXN 120
#define inf 1000000000
typedef int elem_t;
elem_t edmonds(int n,elem_t mat[][MAXN*2],int* pre){
    elem_t ret=0;
    int c[MAXN*2][MAXN*2],l[MAXN*2],p[MAXN*2],m=n,t,i,j,k;
    for (i=0;i<n;l[i]=i,i++);
    do{
        memset(c,0,sizeof(c)),memset(p,0xff,sizeof(p));
        for (t=m,i=0;i<m;c[i][i]=1,i++);
        for (i=0;i<t;i++)
            if (l[i]==i&&pre[i]!=-1){
                for (j=0;j<m;j++)
                    if
(l[j]==j&&i!=j&&mat[j][i]<inf&&(p[i]==-1||mat[j][i]<mat[p[i]][i]))
                        p[i]=j;
                if ((pre[i]=p[i])==-1)
                    return -1;
                if (c[i][p[i]]){
                    for (j=0;j<=m;mat[j][m]=mat[m][j]=inf,j++);
                    for (k=i;l[k]!=m;l[k]=m,k=p[k])
                        for (j=0;j<m;j++)
                            if (l[j]==j){
                                if (mat[j][k]-mat[p[k]][k]<mat[j][m])
                                    mat[j][m]=mat[j][k]-mat[p[k]][k];
                                if (mat[k][j]<mat[m][j])
                                    mat[m][j]=mat[k][j];
                            }
                    c[m][m]=1,l[m]=m,m++;
                }
                for (j=0;j<m;j++)
                    if (c[i][j])
                        for (k=p[i];k!=-1&&l[k]==k;c[k][j]=1,k=p[k]);
            }
    }
    while (t<m);
    for (;m-->n;pre[k]=pre[m])
        for (i=0;i<m;i++)
            if (l[i]==m){
                for (j=0;j<m;j++)
                    if (pre[j]==m&&mat[i][j]==mat[m][j])
                        pre[j]=i;
                if (mat[pre[m]][m]==mat[pre[m]][i]-mat[pre[i]][i])
                    k=i;
            }
    for (i=0;i<n;i++)
        if (pre[i]!=-1)
            ret+=mat[pre[i]][i];
    return ret;
}
  