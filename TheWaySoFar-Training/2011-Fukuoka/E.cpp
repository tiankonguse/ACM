#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

int t[20][3] = {
 {5 , 4 , 1} ,
 {0 , 2 , 6} ,
 {1 , 3 , 7} ,
 {2 , 4 , 8} ,
 {3 , 0 , 9} ,
 {0 , 11 , 10} ,
 {1 , 12 , 11} ,
 {2 , 13 , 12} ,
 {3 , 14 , 13} ,
 {4 , 10 , 14} ,
 {9 , 5 , 15} ,
 {5 , 6 , 16} ,
 {6 , 7 , 17} ,
 {7 , 8 , 18} ,
 {8 , 9 , 19} ,
 {10 , 16 , 19} ,
 {11 , 17 , 15} ,
 {12 , 18 , 16} ,
 {13 , 19 , 17} ,
 {14 , 15 , 18}
};
int f[210][110][20][3];
struct opt {
    int x , y , d , c;
    opt (int _x , int _y , int _d , int _c) {
        x = _x , y = _y , d = _d , c = _c;
    }
};
queue< opt > Q;
int dx0[] = {0 , -1 , 1};
int dy0[] = {1 , 0 , 0};
int dx1[] = {0 , 1 , -1};
int dy1[] = {-1 , 0 , 0};

void update(int x , int y , int d , int c , int w) {
    if (!~f[x][y][d][c])
        f[x][y][d][c] = w , Q.push(opt(x , y , d , c));
}

void work()
{
    int i , j , x , y , d , c , w , k;
    memset(f , -1 , sizeof(f));
    f[102][52][0][0] = 0;
    Q.push(opt(102 , 52 , 0 , 0));
    while (!Q.empty()) {
        x = Q.front().x , y = Q.front().y , d = Q.front().d;
        c = Q.front().c , Q.pop() , w = f[x][y][d][c];
        if (w > 100) break;
        if ((x + y) % 2 == 0) {
            for (i = 0 ; i < 3 ; ++ i) {
                k = t[d][(c + i) % 3];
                for (j = 0 ; j < 3 ; ++ j)
                    if (t[k][j] == d) {
                        (j += 3 - i) %= 3;
                        break;
                    }
                update(x + dx0[i] , y + dy0[i] , k , j , w + 1);
            }
        } else {
            for (i = 0 ; i < 3 ; ++ i) {
                k = t[d][(c + i) % 3];
                for (j = 0 ; j < 3 ; ++ j)
                    if (t[k][j] == d) {
                        (j += 3 - i) %= 3;
                        break;
                    }
                update(x + dx1[i] , y + dy1[i] , k , j , w + 1);
            }
        }
    }
    while (scanf("%d%d%d",&x,&y,&d) , x || y || d) {
        x += 102 , y += 52;
        int res = 1 << 30;
        for (int i = 0 ; i < 3 ; ++ i)
            if (~f[x][y][d][i])
                res = min(res , f[x][y][d][i]);
        printf("%d\n" , res);
    }
}


int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}


