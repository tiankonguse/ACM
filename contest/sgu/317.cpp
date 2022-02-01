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
#define N 5005
#define M 100005
int n , m , B;
struct stable {
    int x;
    vector< pair<int , int> > H;
    bool operator < (const stable& R) const {
        return x < R.x;
    }
}s[N];
pair<int , int> h[M];
double f[N];

void work()
{
    int i , j , k , x , y;
    scanf("%d%d",&B,&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d", &s[i].x , &m);
        for (j = 0 ; j < m ; ++ j) {
            scanf("%d%d",&x,&y);
            h[j] = make_pair(x , y);
        }
        if (s[i].x >= B) {
            -- n , -- i;
            continue;
        }
        sort(h , h + m);
        vector< pair<int , int> >& V = s[i].H;
        for (j = 0 ; j < m ; ++ j) {
            while (!V.empty() && h[j].first >= V.back().first && h[j].second >= V.back().second)
                V.pop_back();
            V.push_back(h[j]);
        }
    }
    s[n].x = B;
    sort(s , s + n + 1);
    if (s[0].x != 0) {
        puts("-1");
        return;
    }
    for (i = 0 ; i <= n ; ++ i)
        f[i] = 1e60;
    f[0] = 0;
    for (i = 0 ; i < n ; ++ i) {
        y = s[i].H.size() , k = y - 1;
        for (j = i + 1 ; j <= n ; ++ j) {
            while (k >= 0 && s[i].x + s[i].H[k].second < s[j].x)
                -- k;
            if (k >= 0)
                f[j] = min(f[j] , f[i] + 1.0 * (s[j].x - s[i].x) / s[i].H[k].first);
            else
                break;
        }
    }
    if (f[n] > 1e50)
        puts("-1");
    else
        printf("%f\n" , f[n]);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

