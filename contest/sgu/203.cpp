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
using namespace std;
typedef long long LL;

#define N 500005
int n , a[N];
priority_queue<LL> Q;
LL ans;
void work()
{
    int i , j ; LL x , y;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&j) , Q.push(-j);
    while (Q.size() > 1) {
        x = Q.top() , Q.pop();
        y = Q.top() , Q.pop();
        ans -= x + y;
        Q.push(x + y);
    }
    cout << ans << endl;
}


int main()
{
    freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}
