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
#include <cassert>
using namespace std;
typedef long long LL;
#define N 1005
#define M 100005

int n , m , res;
char s[N][N];
int cnt[N][N];
void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%s" , s[i] + 1);
    }
    for (i = 1 ; i <= n ; ++ i)
        s[i][0] = s[i][m + 1] = 'X';
    for (i = 1 ; i <= m ; ++ i)
        s[0][i] = s[n + 1][i] = 'X';
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= m ; ++ j) {
            if (s[i][j] == 'X') {
                ++ cnt[i - 1][j];
                ++ cnt[i + 1][j];
                ++ cnt[i][j - 1];
                ++ cnt[i][j + 1];
                ++ res;
            }
        }
    }
    queue< pair<int , int> > Q;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (s[i][j] != 'X' && cnt[i][j] > 1) {
                Q.push(make_pair(i , j));
                s[i][j] = 'X';
                ++ res;
            }
    while (!Q.empty()) {
        x = Q.front().first , y = Q.front().second , Q.pop();
        ++ cnt[x - 1][y];
        ++ cnt[x + 1][y];
        ++ cnt[x][y - 1];
        ++ cnt[x][y + 1];
        if (s[x - 1][y] != 'X' && cnt[x - 1][y] > 1) {
            Q.push(make_pair(x - 1 , y));
            s[x - 1][y] = 'X' , ++ res;
        }
        if (s[x + 1][y] != 'X' && cnt[x + 1][y] > 1) {
            Q.push(make_pair(x + 1 , y));
            s[x + 1][y] = 'X' , ++ res;
        }
        if (s[x][y - 1] != 'X' && cnt[x][y - 1] > 1) {
            Q.push(make_pair(x , y - 1));
            s[x][y - 1] = 'X' , ++ res;
        }
        if (s[x][y + 1] != 'X' && cnt[x][y + 1] > 1) {
            Q.push(make_pair(x , y + 1));
            s[x][y + 1] = 'X' , ++ res;
        }
    }
    cout << res << endl;
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

