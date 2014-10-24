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
#define N 4005

int n , sum[N];
pair<int , int> a[N] , p;

void work()
{
    int i , j , ans = 1 << 30;
    scanf("%d",&n);
    scanf("%d%d",&a[0].first,&a[0].second);
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&a[i].first , &a[i].second);
        sum[i] = sum[i - 1] + abs(a[i].first - a[i - 1].first) + abs(a[i].second - a[i - 1].second);
        for (j = 1 ; j + 1 < i ; ++ j) {
            if (((a[i].first == a[i - 1].first) ^ (a[j].first == a[j - 1].first)) == 0) {
                continue;
            } else if (a[i].first == a[i - 1].first) {
                if (max(a[j].first , a[j - 1].first) >= a[i].first && a[i].first >= min(a[j].first , a[j - 1].first)) {
                    if (max(a[i].second , a[i - 1].second) >= a[j].second && a[j].second >= min(a[i].second , a[i - 1].second)) {
                        p = make_pair(a[i].first , a[j].second);
                        break;
                    }
                }
            } else {
                if (max(a[j].second , a[j - 1].second) >= a[i].second && a[i].second >= min(a[j].second , a[j - 1].second)) {
                    if (max(a[i].first , a[i - 1].first) >= a[j].first && a[j].first >= min(a[i].first , a[i - 1].first)) {
                        p = make_pair(a[j].first , a[i].second);
                        break;
                    }
                }
            }
        }
        if (j + 1 < i) {
            int x = sum[i - 1] - sum[j];
            x += abs(a[i - 1].first - p.first) + abs(a[i - 1].second - p.second);
            x += abs(a[j].first - p.first) + abs(a[j].second - p.second);
            ans = min(ans , x);
        }
    }
    ans = min(ans , sum[n - 1]);
    printf("%d\n" , ans);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

