#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
using namespace std;

#define N 105
int n , s , m;
int sx , sy , ex , ey;
struct board {
    int l , r , h;
    bool operator < (const board& R) const {
        return h > R.h;
    }
}b[N];
pair<int,int> f[N][2];

int main(){
    //freopen("1.txt","r",stdin);
    int i , j , k , x , y , z;

    scanf("%d%d",&m,&s);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d%d",&b[i].l , &b[i].r , &b[i].h);
    }
    sort(b + 1 , b + 1 + n);
    for (i = 1 ; i <= n ; ++ i)
        f[i][0] = f[i][1] = make_pair(1 << 29 , 1 << 29);
    for (i = 1 ; i <= n ; ++ i)
        if (ey == b[i].h && b[i].l <= ex && ex <= b[i].r)
            z = i;

    x = -1;
    for (i = 1 ; i <= n ; ++ i) {
        if (b[i].l <= sx && sx <= b[i].r && sy >= b[i].h) {
            if (!~x || b[i].h > b[x].h)
                x = i;
        }
    }
    if (x == -1) {
        puts("0 0");
        return 0;
    }
    pair<int , int> ans(1 << 29 , 1 << 29);
    if (x == z) {
        if (ex >= sx)
            ans = min(ans , make_pair(0 , ex - sx + sy - b[x].h));
        else
            ans = min(ans , make_pair(1 , sx - ex + sy - b[x].h));
    }
    f[x][0] = make_pair(0 , b[x].r - sx + sy - b[x].h);
    f[x][1] = make_pair(1 , -b[x].l + sx + sy - b[x].h);
    for (i = 1 ; i <= n ; ++ i) {
        int X , Y;
        X = b[i].l , Y = b[i].h;
        x = -1;
        for (j = i + 1 ; j <= n ; ++ j) {
            if (b[j].l <= X && X <= b[j].r && Y >= b[j].h) {
                if (!~x || b[j].h > b[x].h)
                    x = j;
            }
        }
        if (~x) {
            f[x][1] = min(f[x][1] , make_pair(f[i][1].first , f[i][1].second + Y - b[x].h + X - b[x].l));
            f[x][0] = min(f[x][0] , make_pair(f[i][1].first + 1 , f[i][1].second + Y - b[x].h - X + b[x].r));
        }
        if (x == z) {
            if (ex <= X)
                ans = min(ans , make_pair(f[i][1].first , f[i][1].second + Y - b[x].h + X - ex));
            else
                ans = min(ans , make_pair(f[i][1].first + 1 , f[i][1].second + Y - b[x].h + ex - X));
        }
        X = b[i].r , Y = b[i].h;
        x = -1;
        for (j = i + 1 ; j <= n ; ++ j) {
            if (b[j].l <= X && X <= b[j].r && Y >= b[j].h) {
                if (!~x || b[j].h > b[x].h)
                    x = j;
            }
        }
        if (~x) {
            f[x][1] = min(f[x][1] , make_pair(f[i][0].first + 1 , f[i][0].second + Y - b[x].h + X - b[x].l));
            f[x][0] = min(f[x][0] , make_pair(f[i][0].first , f[i][0].second + Y - b[x].h - X + b[x].r));
        }
        if (x == z) {
            if (ex <= X)
                ans = min(ans , make_pair(f[i][0].first + 1, f[i][0].second + Y - b[x].h + X - ex));
            else
                ans = min(ans , make_pair(f[i][0].first , f[i][0].second + Y - b[x].h + ex - X));
        }
    }
    //printf("%d %d\n" , ans.first , ans.second);
    if (ans.first >= m) {
        puts("0 0");
    } else {
        s = s * (m - 1) + ans.second;
        printf("%d %d\n" , m - ans.first , s);
    }

    return 0;
}
