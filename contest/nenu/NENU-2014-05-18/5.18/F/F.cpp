#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 105

struct Mat{
    int mat[M][M];
};
int n , m, t;
Mat operator * (Mat a, Mat b){
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for(k = 0; k<n; k++){
        for(i = 0; i < n; i++){
            if(a.mat[i][k]){
                for(j = 0; j < n; j++){
                    if(b.mat[k][j]){
                        c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(c.mat[i][j])
                c.mat[i][j] = 1;
    return c;
}

Mat operator ^ (Mat a, int k){
    Mat c;
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            c.mat[i][j] = (j == i);
        }
    }
    for(;k; k>>=1){
        if(k&1) c = c * a;
        a = a* a;
    }
    return c;
}
int main(){
    Mat dir, tar;
    Mat start;
    int a[M];
    int th = 1;
    int u, v;
//    freopen("K.in", "r", stdin);
//    freopen("K.txt", "w", stdout);

    while(~scanf("%d%d%d", &n, &m, &t)){

        memset(dir.mat, 0, sizeof(dir.mat));
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            dir.mat[u-1][v-1] = dir.mat[v-1][u-1] = 1;
        }
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
            a[i] --;
        }
        for(int i = 0; i<n; i++){
            int flag = 0;
            for(int j=0; j<n;j++){
                if(dir.mat[i][j] == 1){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) dir.mat[i][i] = 1;
        }
        tar = dir ^ t;
        if(th > 1) printf("\n");
        printf("Case %d:\n", th);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(tar.mat[a[i]][j])
                printf("1");
                else printf("0");
                //if(j < n-1) printf(" ");
            }
            printf("\n");
        }

        th++;
    }
    return 0;
}
/*
2 2 2
1 2
2 1
2 1

3 0 1
2 1 3

4 5 2
1 2
3 1
2 3
2 4
3 4
2 4 1 3
*/
