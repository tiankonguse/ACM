#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cassert>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define N 55

int n , m , K;
vector< pair<int , int> > A[101];
int f[102][2005][21];
int SA , SB;
vector<int> res;

void print(int i , int j , int k) {
    if (i == 0 && j == 1000 && k == 0)
        return;
    int x = 0 , y = 0;
    if (f[i][j][k] == f[i - 1][j][k]) {
        print(i - 1 , j , k);
        return;
    }
    for (int l = 0 ; l < A[i - 1].size() ; ++ l) {
        x += A[i - 1][l].first , y += i - 1 - 50;
        if (j - y >= 0 && j - y <= 2000 && k - l - 1 >= 0) {
            int val = f[i - 1][j - y][k - l - 1] + x;
            if (val == f[i][j][k]) {
                print(i - 1 , j - y , k - l - 1);
                for (int e = 0 ; e <= l ; ++ e) {
                    res.push_back(A[i - 1][e].second);
                }
                return;
            }
        }
    }
}

int main(){
    //freopen("1.txt","r",stdin);
    int i , j , k , l , x , y;
    scanf("%d%d",&n,&K);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d" , &x , &y);
        A[x - y + 50].push_back(make_pair(x + y , i));
    }
    for (i = 0 ; i <= 100 ; ++ i) {
        sort(A[i].begin() , A[i].end() , greater< pair<int , int> >());
        if (A[i].size() > 20)
            A[i].resize(20);
    }
    memset(f , 0x80 , sizeof(f));
    f[0][1000][0] = 0;
    for (i = 0 ; i <= 100 ; ++ i) {
        for (j = 0 ; j <= 2000 ; ++ j) {
            for (k = 0 ; k <= K ; ++ k) {
                if (f[i][j][k] < 0) continue;
                //printf("%d %d %d %d\n" , i , j , k  , f[i][j][k]);
                x = y = 0;
                f[i + 1][j][k] = max(f[i + 1][j][k] , f[i][j][k]);
                for (l = 0 ; l < A[i].size() && k + l + 1 <= K ; ++ l) {
                    x += A[i][l].first , y += i - 50;
                    if (j + y >= 0 && j + y <= 2000)
                        f[i + 1][j + y][k + l + 1] = max(f[i + 1][j + y][k + l + 1] , f[i][j][k] + x);
                }
            }
        }
    }
    for (i = 0 ; i <= 1000 ; ++ i) {
        if (f[101][1000 - i][K] >= 0 || f[101][1000 + i][K] >= 0) {
            if (f[101][1000 - i][K] > f[101][1000 + i][K])
                j = 1000 - i , x = f[101][1000 - i][K];
            else
                j = 1000 + i , x = f[101][1000 + i][K];
            break;
        }
    }
    printf("%d %d\n" , (x + j - 1000) / 2 , (x - j + 1000) / 2);
    print(101 , j , K);
    sort(res.begin() , res.end());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
    return 0;
}
