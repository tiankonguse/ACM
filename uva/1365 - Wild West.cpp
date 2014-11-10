//set
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
#define N 200005
int n , m;
struct build
{
    int x , y , z;
    bool operator < (const build& r) const{
        return z > r.z;
    }
}a[N];
LL ans , area;
set< pair<int , int> > h;
set< pair<int , int> >::iterator it1 , it;
vector< set< pair<int , int> >::iterator > tmp;
void work()
{
    int i , x , y;
    pair<int , int> cur;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d%d%d",&a[i].x , &a[i].y , &a[i].z);
    a[n].z = 0;
    sort(a , a + n);
    h.clear() , ans = area = 0;
    h.insert(make_pair(0 , 1 << 30));
    h.insert(make_pair(1 << 30 , 0));
    for (i = 0 ; i < n ; ++ i)
    {
        x = a[i].x , y = a[i].y;
        cur = make_pair(x , y);

        it = h.lower_bound(make_pair(x , y));
        if (it -> second >= y)
        {
            if (a[i].z != a[i + 1].z)
                ans += area * (a[i].z - a[i + 1].z);
            continue;
        }
        it1 = it , -- it1;
        area -= (LL)it -> second * (it -> first - it1 -> first);
        if (it1 != h.begin())
        {
            -- it , -- it1;
            tmp.clear();
            while (x >= it -> first && y >= it -> second)
            {
                tmp.push_back(it);
                area -= (LL)it -> second * (it -> first - it1 -> first);
                -- it;
                if (it == h.begin()) break;
                -- it1;
            }
            while (!tmp.empty())
                h.erase(tmp.back()) , tmp.pop_back();
        }
        h.insert(cur) , it = it1 = h.find(cur) , -- it1;
        area += (LL)it -> second * (it -> first - it1 -> first);
        ++ it , ++ it1;
        area += (LL)it -> second * (it -> first - it1 -> first);
        if (a[i].z != a[i + 1].z)
            ans += area * (a[i].z - a[i + 1].z);
    }
    printf("%lld\n" , (LL) m * m * m - ans);
}

int main()
{
    while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}
