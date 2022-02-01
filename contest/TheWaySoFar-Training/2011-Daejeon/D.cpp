#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define N 10005
int n , K;
int a[5][N] , b[32][N];
int LOG[100];
int f[32][5];
int main(){
    int T;
    //freopen("1.txt","r",stdin);
    scanf("%d",&T);
    LOG[1] = 0 , LOG[2] = 1 , LOG[4] = 2 , LOG[8] = 3 , LOG[16] = 4;
    for (;T ; --T){

        int i , j , k , l , x , y;
        scanf("%d%d",&n,&K);
        for (i = 0 ; i < n ; ++ i)
            for (j = 0 ; j < 5 ; ++ j)
                scanf("%d",&a[j][i]);
        if (K >= 5)
        {
            x = 0 ;
            for (j = 0 ; j < 5 ; ++ j)
            {
                y = 0;
                for (i = 0 ; i < n ; ++ i)
                    y = max(y , a[j][i]);
                x += y;
            }
            printf("%d\n" , x);
            continue;
        }

        memset(b , 0 , sizeof(b));
        for (j = 1 ; j < 32 ; ++ j)
        {
            x = j & (j - 1) , y = LOG[j & -j];
            for (i = 0  ; i < n ; ++ i)
                b[j][i] = b[x][i] + a[y][i];
        }
        for (j = 1 ; j < 32 ; ++ j)
        {
            sort(b[j] , b[j] + n , greater<int>());
            //for (i = 1 ; i < n ; ++ i)
            //    b[j][i] += b[j][i - 1];
        }
        memset(f , 0x80 , sizeof(f));
        f[0][0] = 0;
        for (i = 1 ; i < 32 ; ++ i)
            for (j = 0 ; j <= K ; ++ j)
            {
                //if (i == 15 && j == 2)
                //    ++ j , -- j;
                for (k = i ; k ; k = (k - 1) & i)
                    for (l = 1 ; l <= j ; ++ l)
                        f[i][j] = max(f[i][j] , f[i ^ k][j - l] + b[k][0]);
                //printf("%d %d : %d\n" , i , j , f[i][j]);
            }

        printf("%d\n" , f[31][K]);
    }
}
