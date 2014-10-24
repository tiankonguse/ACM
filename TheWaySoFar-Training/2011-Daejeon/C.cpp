#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define N 5005
#define M 26
int n , m;
char s[N] , t[N];
int f[N][N] , cnt1[M][N] , cnt2[M][N];

void work()
{
    int i , j , k , x;
    scanf("%s%s" , s + 1 , t + 1);
    n = strlen(s + 1) , m = strlen(t + 1);
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 0 ; j < 26 ; ++ j)
            cnt1[j][i] = cnt1[j][i - 1];
        ++ cnt1[s[i] - 'A'][i];
    }
    for (i = 1 ; i <= m ; ++ i) {
        for (j = 0 ; j < 26 ; ++ j)
            cnt2[j][i] = cnt2[j][i - 1];
        ++ cnt2[t[i] - 'A'][i];
    }
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j <= m ; ++ j)
            f[i][j] = 0x3F3F3F3F;
    f[0][0] = 0;
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j <= m ; ++ j)
            if (f[i][j] < 0x3F3F3F3F) {
                if (i + 1 <= n) {
                    x = f[i][j] , k = s[i + 1] - 'A';
                    if (cnt1[k][i + 1] + cnt2[k][j] == cnt1[k][n] + cnt2[k][m]) {
                        x += i + j + 1;
                    }
                    if (cnt1[k][i + 1] + cnt2[k][j] == 1) {
                        x -= i + j + 1;
                    }
                    if (x < f[i + 1][j]) f[i + 1][j] = x;
                }
                if (j + 1 <= m) {
                    x = f[i][j] , k = t[j + 1] - 'A';
                    if (cnt1[k][i] + cnt2[k][j + 1] == cnt1[k][n] + cnt2[k][m]) {
                        x += i + j + 1;
                    }
                    if (cnt1[k][i] + cnt2[k][j + 1] == 1) {
                        x -= i + j + 1;
                    }
                    if (x < f[i][j + 1]) f[i][j + 1] = x;
                }
            }
    printf("%d\n" , f[n][m]);
}

int main(){
    //freopen("1.txt","r",stdin);
    int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}
