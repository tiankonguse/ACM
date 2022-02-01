#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100005
int n , m , f[N] , s[N];
int getf(int x)
{
    if (f[x] == x)
        return x;
    int fx = getf(f[x]);
    s[x] += s[f[x]];
    return f[x] = fx;
}

void work()
{
    int i , j , x , y , fx , fy;
    char str[10];
    for (i = 1 ; i <= n ; ++ i)
        f[i] = i , s[i] = 0;
    //cout << n << m << endl;
    while (m --)
    {
        scanf("%s" , str);
        if (*str == '!')
        {
            scanf("%d%d%d",&x,&y,&j);
            fx = getf(x) , fy = getf(y);
            if (fx == fy) continue;
            f[fy] = fx , s[fy] = s[x] + j - s[y];
        }
        else
        {
            scanf("%d%d",&x,&y);
            fx = getf(x) , fy = getf(y);
            if (fx != fy)
                puts("UNKNOWN");
            else
            {
                printf("%d\n" , -s[x] + s[y]);
            }
        }
    }
}

int main()
{
   //freopen("1.txt" , "r" , stdin);

    while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}
