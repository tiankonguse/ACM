#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n , m;
vector<int> sel[20];
bool f[1 << 20] ;int g[20];
void work()
{
    int i , j , k , x;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < m ; ++ i)
    {
        scanf("%d",&j) , sel[i].resize(j);
        for (j = 0 ; j < sel[i].size() ; ++ j)
            scanf("%d",&sel[i][j]);
    }
    for (i = 0 ; i < m ; ++ i)
    {
        for (j = 0 ; j < sel[i].size() ; ++ j)
            f[sel[i][j]] = 1;
        for (j = i + 1 ; j < m ; ++ j)
        {
            for (k = 0 ; k < sel[j].size() ; ++ k)
                if (f[sel[j][k]])
                    break;
            if (k < sel[j].size())
                g[i] ^= 1 << j , g[j] ^= 1 << i;
        }
        for (j = 0 ; j < sel[i].size() ; ++ j)
            f[sel[i][j]] = 0;
    }
    int ans = 0; f[0] = 1;
    for (i = 0 ; i < (1 << m) ; ++ i) if (f[i])
    {
        ans = max(ans , __builtin_popcount(i));
        for (j = 0 ; j < m ; ++ j) if (~i >> j & 1) if (!(g[j] & i))
            f[i ^ (1 << j)] = 1;
    }
    printf("%d\n" , ans);
}

int main()
{
    //int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}
