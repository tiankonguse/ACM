#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;

#define N 200
int n , m , a[N][N];
queue<int> Q;
vector< pair<int , int> > res;
void work()
{
    int i , j , x , y ;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < m ; ++ j) {
            scanf("%d",&a[i][j]);
            if (a[i][j] == 1) {
                Q.push(i * m + j);
            }
        }
    while (!Q.empty()) {
        i = Q.front() , Q.pop() ;
        x = i / m , y = i % m;
        a[x][y] = 1 << 30;
        res.push_back(make_pair(x + 1 , y + 1));
        if (x > 0) {
            if (!-- a[x - 1][y])
                break;
            if (a[x - 1][y] == 1)
                Q.push(i - m);
        }
        if (x + 1 < n) {
            if (!-- a[x + 1][y])
                break;
            if (a[x + 1][y] == 1)
                Q.push(i + m);
        }
        if (y > 0) {
            if (!-- a[x][y - 1])
                break;
            if (a[x][y - 1] == 1)
                Q.push(i - 1);
        }
        if (y + 1 < m) {
            if (!-- a[x][y + 1])
                break;
            if (a[x][y + 1] == 1)
                Q.push(i + 1);
        }
    }
    if (res.size() < n * m) {
        puts("No solution");
    } else
        for (i = n * m - 1 ; i >= 0 ; -- i)
            printf("%d %d\n" , res[i].first , res[i].second);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}
