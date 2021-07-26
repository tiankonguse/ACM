/**************************************************************************
 **      File Name: 3.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/30 18:19:12
/**************************************************************************/
#include<cstdio>
#include<cstring>
#include<cstdlib>
/*==================================================*\
| 二分图匹配（匈牙利算法DFS 实现）
| INIT: g[][]邻接矩阵;
| CALL: res = MaxMatch();
| 优点：实现简洁容易理解，适用于稠密图，DFS找增广路快。
| 找一条增广路的复杂度为O（E），最多找V条增广路，故时间复杂度为O（VE）
\*==================================================*/
const int MAXN = 1111;
int uN, vN; // u, v数目，要初始化！！！
bool g[MAXN][MAXN]; // g[i][j] 表示xi与yj相连
int xM[MAXN], yM[MAXN]; // 输出量
bool chk[MAXN]; // 辅助量检查某轮y[v]是否被check
int str[MAXN][MAXN];

int mapx[9]={-2, -1, -1,  0, 0,  1, 1, 2};
int mapy[9]={ 0, -1,  1, -2, 2, -1, 1, 0};

bool SearchPath(int u) {
    int v;
    for(v = 0; v < vN; v++)
        if(g[u][v] && !chk[v]) {
            chk[v] = true;
            if(yM[v] == -1 || SearchPath(yM[v])) {
                yM[v] = u;
                xM[u] = v;
                return true ;
            }
        }
    return false ;
}
int MaxMatch() {
    int u, ret = 0 ;
    memset(xM, -1, sizeof (xM));
    memset(yM, -1, sizeof (yM));
    for(u = 0; u < uN; u++)
        if(xM[u] == -1) {
            memset(chk, false, sizeof (chk));
            if(SearchPath(u)) ret++;
        }
    return ret;
}
int main() {
    int i,j,k,x,y,n,m,num;
    while(scanf("%d%d",&n,&m) != EOF){
        memset(g,0,sizeof(g));

        num = 0;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&str[i][j]);
                if(str[i][j]){
                    num++;
                    str[i][j]= num;
                }
            }
        }

        uN=vN=num;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(str[i][j]){
                    for(k=0;k<8;k++){
                        if(i+mapx[k]>=0 && i+mapx[k]<n && j+mapy[k]>=0 && j+mapy[k]<m && str[i+mapx[k]][j+mapy[k]]){
                            g[str[i][j]-1][str[i+mapx[k]][j+mapy[k]]-1] = 1;
                        }
                    }
                }
            }
        }

        int ans = MaxMatch();

        printf("%d\n",num - ans / 2);
    }
    return 0;
}
