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
bool can[1 << 7];
int state[N];
char str[N];

void init() {
    for (int i = 0 , j ; i < 1 << m ; ++ i) {
        for (j = 1 ; j < m ; ++ j)
            if ((~i >> (j - 1) & 1) && (~i >> j & 1))
                break;
        if (j >= m) can[i] = 1;
    }
}
int f[2][1 << 7][1 << 7];
int cur , nxt;
void dfs(int fir,int sec,int sec1,int thi,int cur,int num)
{
    if(cur == m)
    {
        f[nxt][sec1][thi] = min(f[nxt][sec1][thi], f[::cur][fir][sec] + num);
        return ;
    }
    int a = fir >> cur & 1;
    int b = sec1 >> cur & 1;
    int c = thi >> cur & 1;
    if(b) dfs(fir,sec,sec1,thi,cur + 1,num);
    if(!b && a && (cur == 0 || (sec1 >> cur - 1 & 1)))
        dfs(fir,sec,sec1,thi,cur + 1,num);
    if(!b && cur + 1 < m && (sec1 >> cur + 1 & 1) == 0)
        dfs(fir,sec,sec1 + (3 << cur),thi,cur + 2,num + 1);
    if(!b && !c )
        dfs(fir,sec,sec1 + (1 << cur),thi + (1 << cur),cur + 1,num + 1);
}

void work()
{
    int i , j , k;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        for (j = 0 ; j < m ; ++ j)
            state[i] |= (str[j] == '*') << j;
    }
    cur = 0 , nxt = 1;
    memset(f[cur] , 63 , sizeof(f[cur]));
    f[cur][(1 << m) - 1][state[0]] = 0;
    for (i = 0 ; i < n ; ++ i) {

        memset(f[nxt] , 63 , sizeof(f[nxt]));
        for (j = 0 ; j < 1 << m ; ++ j) if (can[j]){
            for (k = 0 ; k < 1 << m ; ++ k) {
                if ((k & state[i]) == state[i] && f[cur][j][k] < 0x3f3f3f3f) {
                    //printf("%d %d %d %d\n" , i , j , k , f[cur][j][k]);
                    dfs(j , k , k , state[i + 1] , 0 , 0);
                }
            }
        }
        swap(cur , nxt);
    }
    int ans = 1 << 30;
    for (i = 0 ; i < 1 << m ; ++ i)
        if (can[i])
            ans = min(ans , f[cur][i][0]);
    printf("%d\n" , ans);
}


int main()
{
    freopen("1.txt" , "r" , stdin);
    scanf("%d%d",&n,&m);
    init();
    work();
    return 0;
}


