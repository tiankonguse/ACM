#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 505
int n , K;
pair<int , int> a[N];
pair<int , int> cur , nxt;
int dx[] = {1 , 0 , -1 , 0};
int dy[] = {0 , 1 , 0 , -1};
bool w[N][N][4];
int ans;
bool f[N][N];

void work() {
    int i , j , k , x , y;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d%d",&a[i].first , &a[i].second);
    memset(w , 0 , sizeof(w));
    memset(f , 0 , sizeof(f)) , ans = 0;
    for (i = 0 ; i < n ; ++ i) {
        int l = (i + 1) % n;
        if (a[i].first == a[l].first) {
            x = min(a[i].second , a[l].second);
            y = max(a[i].second , a[l].second);
            for (j = x + 1 ; j <= y ; ++ j)
                w[a[i].first][j][0] = w[a[i].first + 1][j][2] = 1;
        } else {
            x = min(a[i].first , a[l].first);
            y = max(a[i].first , a[l].first);
            for (j = x + 1 ; j <= y ; ++ j)
                w[j][a[i].second][1] = w[j][a[i].second + 1][3] = 1;
        }
    }
    scanf("%d%d",&cur.first , &cur.second);
    for (i = 1 ; i < K ; ++ i) {
        scanf("%d%d",&nxt.first , &nxt.second);
        if (cur.first == nxt.first) {
            if (cur.second < nxt.second) {
                for (j = cur.second + 1 ; j <= nxt.second ; ++ j) {
                    x = cur.first , y = j;
                    while (!w[x][y][0]) {
                        ++ x;
                        if (!f[x][y])
                            f[x][y] = 1 , ++ ans;
                    }
                    x = cur.first + 1 , y = j;
                    while (!w[x][y][2]) {
                        -- x;
                        if (!f[x][y])
                            f[x][y] = 1 , ++ ans;
                    }
                }
            } else {
                for (j = nxt.second + 1 ; j <= cur.second ; ++ j) {
                    x = cur.first , y = j;
                    while (!w[x][y][0]) {
                        ++ x;
                        if (!f[x][y])
                            f[x][y] = 1 , ++ ans;
                    }
                    x = cur.first + 1 , y = j;
                    while (!w[x][y][2]) {
                        -- x;
                        if (!f[x][y])
                            f[x][y] = 1 , ++ ans;
                    }
                }
            }

        } else {
            if (cur.first < nxt.first) {
                for (j = cur.first + 1 ; j <= nxt.first ; ++ j) {
                    x = j , y = cur.second;
                    while (!w[x][y][1]) {
                        ++ y;
                        if (!f[x][y])
                            f[x][y] = 1 , ++ ans;
                    }
                    x = j , y = cur.second + 1;
                    while (!w[x][y][3]) {
                        -- y;
                        if (!f[x][y])
                            f[x][y] = 1 , ++ ans;
                    }
                }
            } else {
                for (j = nxt.first + 1 ; j <= cur.first ; ++ j) {
                    x = j , y = cur.second;
                    while (!w[x][y][1]) {
                        ++ y;
                        if (!f[x][y])
                            f[x][y] = 1 , ++ ans;
                    }
                    x = j , y = cur.second + 1;
                    while (!w[x][y][3]) {
                        -- y;
                        if (!f[x][y])
                            f[x][y] = 1 , ++ ans;
                    }
                }
            }
        }
        cur = nxt;
    }
    printf("%d\n" , ans);
}

int main(){
    while (scanf("%d%d",&n,&K) , n || K)
        work();
    return 0;
}
