#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

int dx[] = {1 , 0 , -1 , 0};
int dy[] = {0 , -1 , 0 , 1};
bool f[12][12];
int n , m;
int main() {

    int n , m , x , y , i;
    cin >> n >> m >> x >> y;
    while (1) {
        for (i = 0 ; i < 4 ; ++ i) {
            int X = x + dx[i] , Y = y + dy[i];
            if (X > 0 && X <= n && Y > 0 && Y <= m && !f[X][Y]) {
                f[x][y] = 1;
                putchar("DLUR"[i]);
                x = X , y = Y;
                break;
            }
        }
        if (i >= 4) break;
    }
    puts("");
    return 0;
}
