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
#include <cassert>
using namespace std;
typedef long long LL;

#define N 200000

int n , d;
pair<int , int> a[N];

void work() {
    int i , j ;
    pair<int , pair<int , int> > ans;
    ans.first = -1 << 30;
    pair<int , int> x(-1 << 30 , -1);
    scanf("%d%d",&n,&d);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d%d",&a[i].first , &a[i].second);
    sort(a , a + n);
    for (i = 0 , j = 0 ; i < n ; ++ i) {
        while (a[i].first - a[j].first >= d) {
            x = max(x , make_pair(a[j].second , j)) , ++ j;
        }
        ans = max(ans , make_pair(a[i].second + x.first , make_pair(i , x.second)));
    }
    if (ans.first <= -1 << 29)
        puts("-1 -1");
    else
        printf("%d %d\n" , ans.second.first + 1 , ans.second.second + 1);
}

int main()
{
    work();
    return 0;
}

