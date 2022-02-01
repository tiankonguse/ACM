#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;
#define N 100005
#define M 105
int n , m , sum , s[N] , block = 1000;
vector<int> a[N];
int d[N] , D , ans;
int id[N] , cnt;
int res[M][N] , rank[N];

void work()
{
    int i , j , k , x , y;
    sum = D = 0;
    for (i = 1 ; i <= n ; ++ i)
    {
        scanf("%d",&s[i]) , a[i].resize(s[i]) , sum += s[i];
        for (j = 0 ; j < s[i] ; ++ j)
            scanf("%d",&a[i][j]) , d[D ++] = a[i][j];
        sort(a[i].begin() , a[i].end());
    }
    sort(d , d + D) , D = unique(d , d + D) - d;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 0 ; j < s[i] ; ++ j)
            a[i][j] = lower_bound(d , d + D , a[i][j]) - d + 1;
    cnt = 0;

    for (i = 1 ; i <= n ; ++ i)
        if (s[i] >= block)
        {
            id[i] = ++ cnt;
            memset(rank , 0 , sizeof(rank));
            for (j = 1 , k = 0 ; j <= D ; ++ j)
            {
                while (k < s[i] && j >= a[i][k])
                    ++ k;
                rank[j] = k;
            }
            memset(res[cnt] , 0 , sizeof(res[cnt]));
            for (j = 1 ; j <= n ; ++ j)
                if (i != j && s[i] >= s[j])
                {
                    for (k = 0 ; k < s[j] ; ++ k)
                        d[k] = rank[a[j][k]];
                    x = unique(d , d + s[j]) - d;
                    for (k = 0 ; k < x ; ++ k)
                        if (d[k] == 0 || d[k] == s[i])
                            ++ res[cnt][j];
                        else
                            res[cnt][j] += 2;
                }
        }
    scanf("%d",&m);
    while (m --)
    {
        scanf("%d%d",&x,&y);
        if (s[x] > s[y])
            swap(x , y);
        if (s[y] < block)
        {
            i = j = ans = 0;
            bool pre;
            if (a[x][i] < a[y][j])
                ++ i , pre = 0;
            else
                ++ j , pre = 1;
            while (i < s[x] || j < s[y])
            {
                if (j >= s[y] || (i < s[x] && a[x][i] < a[y][j]))
                {
                    ++ i;
                    if (pre != 0)
                        ++ ans;
                    pre = 0;
                }
                else
                {
                    ++ j;
                    if (pre != 1)
                        ++ ans;
                    pre = 1;
                }
            }
            printf("%d\n" , ans);
        }
        else
            printf("%d\n" , res[id[y]][x]);
    }
}

int main()
{
    while (~scanf("%d",&n))
        work();
    return 0;
}
