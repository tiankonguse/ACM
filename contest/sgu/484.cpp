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
#define N 105
int n , m;
char s[N][N];

void work()
{
    int i , j , x , y;
    cin >> n >> m;
    for (i = 1 ; i <= n ; ++ i)
        cin >> (s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j) {
            if (s[i][j] == 'P') {
                x = i , y = j;
                s[i][j] = '.';
            }
        }
    while (x <= n) {
        if (s[x][y] == '.')
            ++ x;
        else if (s[x][y] == '\\'){
            if (y == m || s[x][y + 1] == '/') break;
            ++ x , ++ y;
        } else {
            if (y == 1 || s[x][y - 1] == '\\') break;
            ++ x , -- y;
        }
    }
    if (x <= n)
        puts("-1");
    else
        printf("%d\n" , y);
}


int main()
{
    work();
    return 0;
}

