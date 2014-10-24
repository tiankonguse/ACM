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
#define N 100005
int n , m , K;
pair<int , int> a[N];
pair<double , int> p[N];

bool check(int x , int y , int i , int j) {
    // (x , y) in (a[0] , a[i] , a[j]);
    LL area = (LL)(a[i].first - a[0].first) * (LL)(a[j].second - a[0].second) -
              (LL)(a[i].second - a[0].second) * (LL)(a[j].first - a[0].first);
    area = abs(area);
    LL sum = 0 , A;
    A = (LL)(a[i].first - x) * (LL)(a[j].second - y) -
        (LL)(a[i].second - y) * (LL)(a[j].first - x);
    sum += abs(A);
    A = (LL)(a[0].first - x) * (LL)(a[j].second - y) -
        (LL)(a[0].second - y) * (LL)(a[j].first - x);
    sum += abs(A);
    A = (LL)(a[i].first - x) * (LL)(a[0].second - y) -
        (LL)(a[i].second - y) * (LL)(a[0].first - x);
    sum += abs(A);
    return sum == area;
}

bool cmp(pair<int , int> A , pair<int , int> B) {
    if (A.second != B.second)
        return A.second < B.second;
    return A.first < B.first;
}

void work()
{
    int i , j , x , y;
    scanf("%d%d%d",&n,&m,&K);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d%d",&a[i].first , &a[i].second);
    sort(a , a + n , cmp);
    for (i = 1 ; i < n ; ++ i) {
        p[i] = make_pair(atan2(a[i].second - a[0].second , a[i].first - a[0].first) , i);
    }
    sort(p + 1 , p + n);
    //for (i = 1 ; i < n ; ++ i)
    //    printf("%d %d\n" , a[p[i].second].first , a[p[i].second].second);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d",&x,&y);
        if (*lower_bound(a , a + n , make_pair(x , y) , cmp) == make_pair(x , y)) {
            -- K;
            continue;
        }
         double arc = atan2(y - a[0].second , x - a[0].first);
        j = lower_bound(p + 1 , p + n , make_pair(arc , 1 << 30)) - p;
        if (j >= n) {
            if (check(x , y , p[n - 1].second , p[n - 1].second)) {
                LL A = (LL)(x - p[0].first) * (x - p[0].first) + (LL)(y - p[0].second) * (y - p[0].second);
                LL B = (LL)(x - p[n - 1].first) * (x - p[n - 1].first) + (LL)(y - p[n - 1].second) * (y - p[n - 1].second);
                if (A >= 0 && B <= 0 || A <= 0 && B >= 0)
                    -- K;
            }
            continue;
        }
        if (check(x , y , p[j].second , p[j - 1].second))
            -- K;
    }
    if (K <= 0)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    work();
    return 0;
}

