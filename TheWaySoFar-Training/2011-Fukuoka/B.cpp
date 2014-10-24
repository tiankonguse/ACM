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

int n , m;
char s[15][25] , str[205];
int num ;
int dx[] = {0 , 0 , 1 , 1 , 1 , -1 , -1 , -1};
int dy[] = {1 , -1 , 1 , 0 , -1 , 1 , 0 , -1};
int f[10];

struct STR{
    int len;
    char s[205];
    char operator [] (int x) {
        return s[x];
    }
    bool operator < (const STR& E) const {
        return strcmp(s , E.s) < 0;
    }
}t[10*20*8];

void work()
{
    int i , j , k , x , y;
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , s[i]);
    num = 0;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j) {
            for (k = 0 ; k < 8 ; ++ k) {
                memset(f , 0 , sizeof(f));
                x = i , y = j , t[num].len = 0;
                t[num].s[t[num].len ++] = s[i][j] , f[i] |= 1 << j;
                while (1) {
                    x += dx[k] , y += dy[k];
                    if (x < 0) x += n;
                    if (y < 0) y += m;
                    if (x >= n) x -= n;
                    if (y >= m) y -= m;
                    if (f[x] >> y & 1) break;
                    t[num].s[t[num].len ++] = s[x][y] , f[x] |= 1 << y;
                }
                //puts(t[num]);
                t[num].s[t[num].len] = 0;
                ++ num;
            }
        }
    }
    sort(t , t + num);
    //for (i = 0 ; i < num ; ++ i) {
    //    puts(t[i].s);
    //}
    int ans = 0;
    for (i = 1 ; i < num ; ++ i)
        {
            j = 0;
            while (t[i - 1][j] && t[i - 1][j] == t[i][j])
                ++ j;
            t[i - 1].len = j;
            t[i - 1].s[j] = 0;
            if (t[i - 1].len > ans)
                ans = t[i - 1].len , strcpy(str , t[i - 1].s);
            else if (t[i - 1].len == ans && strcmp(t[i - 1].s , str) < 0)
                strcpy(str , t[i - 1].s);
        }
    if (ans < 2)
        puts("0");
    else
        puts(str);
}


int main()
{
    //freopen("1.txt" , "r" , stdin);
    while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}
