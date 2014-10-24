#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define N 52
int n , m , INF = 0x3f3f3f3f;
char s[N][N];
int dt[2][N][N];
int d[N][N][4];
bool f[N][N][4];
int dx4[] = {-1 , 1 , 0 , 0} , dy4[] = {0 , 0 , -1 , 1};
int dx[] = {-1 , -1 , 2 , 2 , 0 , 1 , 0 , 1};
int dy[] = {0 , 1 , 0 , 1 , -1 , -1 , 2 , 2};

struct opt
{
    int x , y , d , w;
    opt (int _x , int _y , int _d , int _w){
        x = _x , y = _y , d = _d , w = _w;
    }
    bool operator < (const opt& R)const{
        return w > R.w;}
};

void BFS(int sx , int sy , int D[][N])
{
    queue< pair<int , int> > Q;
    memset(D , 63 , sizeof(dt[0]));
    Q.push(make_pair(sx , sy)) , D[sx][sy] = 0;
    while (!Q.empty())
    {
        int x = Q.front().first , y = Q.front().second; Q.pop();
        for (int i = 0 ; i < 4 ; ++ i)
        {
            int xx = x + dx4[i] , yy = y + dy4[i];
            if (xx > 0 && xx <= n && yy > 0 && yy <= m && D[xx][yy] == INF)
                if (s[xx][yy] == 'o' || s[xx][yy] == '.')
                    D[xx][yy] = D[x][y] + 1 , Q.push(make_pair(xx , yy));
        }
    }
}
priority_queue< opt > Q;
void update(int x , int y , int dd , int w) {
    if (w >= INF) return;
    if (!f[x][y][dd] && d[x][y][dd] > w)
    {
        d[x][y][dd] = w;
        Q.push(opt(x , y , dd , w));
    }
}

void work()
{
    int i , j , x , y , D , w;
    int ncnt = 0 , sx , sy;
    memset(s , 0 , sizeof(s));
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (s[i][j] == 'X' && s[i + 1][j] == 'X' && s[i][j + 1] == 'X' && s[i + 1][j + 1] == 'X')
                sx = i , sy = j;
    if (sx == 1 && sy == 1)
    {
        puts("0");
        return;
    }
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (s[i][j] == '.')
                BFS(i , j , dt[ncnt ++]) , s[i][j] = 'o';
    s[sx][sy] = s[sx + 1][sy] = s[sx][sy + 1] = s[sx + 1][sy + 1] = 'o';
    memset(d , 63 , sizeof(d));
    memset(f , 0 , sizeof(f));
    for (i = 0 ; i < 4 ; ++ i)
    {
        int x1 , x2 , y1 , y2;
        x1 = sx + dx[i << 1] , y1 = sy + dy[i << 1];
        x2 = sx + dx[i << 1 | 1] , y2 = sy + dy[i << 1 | 1];
        if (s[x1][y1] == 'o' && s[x2][y2] == 'o')
            update(sx , sy , i , min(dt[0][x1][y1] + dt[1][x2][y2] , dt[1][x1][y1] + dt[0][x2][y2]));
    }
    //printf("%d\n%d\n%d\n%d\n\n" , d[sx][sy][0] , d[sx][sy][1] , d[sx][sy][2] ,  d[sx][sy][3]);
    while (!Q.empty())
    {
        x = Q.top().x , y = Q.top().y , D = Q.top().d , w = Q.top().w , Q.pop();
        if (f[x][y][D]) continue; f[x][y][D] = 1;
        s[x][y] = s[x + 1][y] = s[x][y + 1] = s[x + 1][y + 1] = 'X';
        BFS(x + dx[D << 1] , y + dy[D << 1] , dt[0]);
        BFS(x + dx[D << 1 | 1] , y + dy[D << 1 | 1] , dt[1]);
        s[x][y] = s[x + 1][y] = s[x][y + 1] = s[x + 1][y + 1] = 'o';
        int x1 , x2 , y1 , y2;
        for (i = 0 ; i < 4 ; ++ i)
        {
            x1 = x + dx[i << 1] , y1 = y + dy[i << 1];
            x2 = x + dx[i << 1 | 1] , y2 = y + dy[i << 1 | 1];
            if (s[x1][y1] == 'o' && s[x2][y2] == 'o')
                update(x + dx4[i] , y + dy4[i] , i ^ 1 , w + 1 + min(dt[0][x1][y1] + dt[1][x2][y2] , dt[1][x1][y1] + dt[0][x2][y2]));
        }
    }
    int ans = 1 << 30;
    for (i = 0 ; i < 4 ; ++ i)
        ans = min(ans , d[1][1][i]);
    if (ans >= INF)
        puts("-1");
    else
        printf("%d\n" , ans);
}

int main()
{
    while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}
