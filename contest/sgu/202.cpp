#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 105
int n , m;
int f[N][N] , g[N][N];
deque<int> P[N];

void move(int x , int y) {
    assert(!P[x].empty());
    if (P[y].empty()) {
        printf("move %d from %d to %d\n" , P[x].front() , x , y);
    } else {
        printf("move %d from %d to %d atop %d\n" , P[x].front() , x , y , P[y].front());
    }
    P[y].push_front(P[x].front()) , P[x].pop_front();
}

void print(int s , int t , int x , int y) {
    if (x == 1) {
        move(s , t);
        return;
    }
    int R = -1;
    for (int i = 1 ; i <= m ; ++ i) {//transit
        if (i == s || i == t) continue;
        if (P[i].empty() || P[s][g[x][y] - 1] < P[i].front()) {
            R = i;
            break;
        }
    }
    assert(R != -1);
    print(s , R , g[x][y] , y);
    print(s , t , x - g[x][y] , y - 1);
    print(R , t , g[x][y] , y);
}

void work() {
    int i , j , k;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j <= m ; ++ j)
            f[i][j] = 1 << 29;
    for (i = 1 ; i <= m ; ++ i)
        f[1][i] = 1;
    for (i = 2 ; i <= n ; ++ i) {
        for (j = 3 ; j <= m ; ++ j) {
            for (k = 1 ; k < i ; ++ k) {
                if (f[k][j] + f[i - k][j - 1] + f[k][j] < f[i][j]) {
                    f[i][j] = f[k][j] + f[i - k][j - 1] + f[k][j];
                    g[i][j] = k;
                }
            }
        }
    }
    cout << f[n][m] << endl;
    for (i = n ; i >= 1 ; -- i)
        P[1].push_front(i);
    print(1 , m , n , m);
}

int main(){
    //freopen("1.txt" , "r" , stdin);
        work();
    return 0;
}
