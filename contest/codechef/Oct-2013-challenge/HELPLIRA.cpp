#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 50005
int n;
void work()
{
    int i , x , y , x1 , y1 , x2 , y2 , s;
    pair<int , int> mx(-1 << 30 , 0) , mn(1 << 30 , 0);
    for (i = 1 ; i <= n ; ++ i)
    {
        scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
        x1 -= x , x2 -= x , y1 -= y , y2 -= y;
        s = abs(x1 * y2 - x2 * y1);
        mn = min(mn , make_pair(s , -i));
        mx = max(mx , make_pair(s , i));
    }
    printf("%d %d\n" , -mn.se , mx.se);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    while (~scanf("%d",&n))
        work();
    return 0;
}
