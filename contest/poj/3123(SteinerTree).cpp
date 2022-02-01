#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define N 35
int n , m , pre[N] , mcnt , pcnt;
map<string , int> hash;
int id[N] , box[N];
pair<int , int> link[4];
struct edge
{
    int x , w , next;
}e[2005];
int dp[N][1 << 8] , d[1 << 8];
bool f[N][1 << 8];
queue< pair<int , int> > Q;
string str;

void SPFA()
{
    int x , w , i;
    while (!Q.empty())
    {
        x = Q.front().first , w = Q.front().second , Q.pop() , f[x][w] = 0;
        for (i = pre[x] ; ~i ; i = e[i].next)
        {
            int y = e[i].x;
            if (dp[x][w] + e[i].w < dp[y][w | id[y]])
            {
                dp[y][w | id[y]] = dp[x][w] + e[i].w;
                if (!f[y][w | id[y]])
                    f[y][w | id[y]] = 1 , Q.push(make_pair(y , w | id[y]));
            }
        }
    }
}

bool check(int x)
{
    for (int i = 0 ; i < 8 ; ++ i)
        if (x & (1 << i))
        {
            for (int j = 0 ; j < 4 ; ++ j)
                if (link[j].first == (1 << i))
                {
                    if ((x & link[j].second) == 0)
                        return 0;
                }
                else if (link[j].second == (1 << i))
                {
                    if ((x & link[j].first) == 0)
                        return 0;
                }
        }
    return 1;
}

void work()
{
    int i , j , x , y , w;
    memset(pre , -1 , sizeof(pre));
    mcnt = pcnt = 0 , hash.clear();
    for (i = 1 ; i <= n ; ++ i)
        cin >> str , hash[str] = i;
    for (i = 1 ; i <= m ; ++ i)
    {
        cin >> str;
        x = hash[str];
        cin >> str;
        y = hash[str];
        scanf("%d",&w);
        e[mcnt] = (edge){y , w , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge){x , w , pre[y]} , pre[y] = mcnt ++;
    }
    memset(id , 0 , sizeof(id));
    for (i = 0 ; i < 4 ; ++ i)
    {
        cin >> str;
        x = hash[str];
        cin >> str;
        y = hash[str];
        if (!id[x]) box[pcnt] = x , id[x] = 1 << pcnt ++;
        if (!id[y]) box[pcnt] = y , id[y] = 1 << pcnt ++;
        link[i] = make_pair(id[x] , id[y]);
    }
    memset(f , 0 , sizeof(f));
    for (i = 1 ; i <= n ; ++ i)
        for (j = 0 ; j < 1 << pcnt ; ++ j)
            dp[i][j] = 1 << 29;
    for (i = 0 ; i < pcnt ; ++ i)
        dp[box[i]][1 << i] = 0;

    for (i = 0 ; i < 1 << pcnt ; ++ i)
    {
        for (x = 1 ; x <= n ; ++ x)
        {
            for (j = (i - 1) & i ; j ; j = (j - 1) & i)
                dp[x][i] = min(dp[x][i] , dp[x][j | id[x]] + dp[x][(i ^ j) | id[x]]);
            if (dp[x][i] < 1 << 29) Q.push(make_pair(x , i));
        }
        SPFA();
    }
    for (i = 0 ; i < 1 << pcnt ; ++ i)
    {
        d[i] = 1 << 29;
        for (j = 1 ; j <= n ; ++ j)
            d[i] = min(d[i] , dp[j][i]);
        for (j = (i - 1) & i ; j ; j = (j - 1) & i)
            if (check(j))
                d[i] = min(d[i] , d[j] + d[i ^ j]);
        //printf("%d : %d \n" , i , d[i]);
    }
    printf("%d\n" , d[(1 << pcnt) - 1]);
}

int main()
{
    freopen("input.txt" , "r" , stdin);
    //int _; scanf("%d",&_) ; while (_ --)
    while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}
