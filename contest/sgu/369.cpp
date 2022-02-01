#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 200005
struct Point {
    int x , y , id;
}a[N];
bool cmpx(Point A , Point B) {
    return make_pair(A.x , A.y) < make_pair(B.x , B.y);
}
bool cmpy(Point A , Point B) {
    return make_pair(A.y , A.x) < make_pair(B.y , B.x);
}
int n , f[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}
set<int> fx[N] , fy[N];
void work()
{
    int i , x , y;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        a[i] = (Point) {x , y , i};
        f[i] = i;
    }
    sort(a , a + n , cmpx);
    for (i = 1 ; i < n ; ++ i)
        if (a[i].x == a[i - 1].x)
            f[getf(a[i].id)] = getf(a[i - 1].id);
    sort(a , a + n , cmpy);
    for (i = 1 ; i < n ; ++ i)
        if (a[i].y == a[i - 1].y)
            f[getf(a[i].id)] = getf(a[i - 1].id);
    for (i = 0 ; i < n ; ++ i) {
        x = getf(a[i].id);
        fx[x].insert(a[i].x);
        fy[x].insert(a[i].y);
    }
    LL ans = 0;
    for (i = 0 ; i < n ; ++ i)
        ans += (LL)fx[i].size() * fy[i].size();
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}
