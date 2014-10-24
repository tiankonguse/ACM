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

#define N 120005
set<ULL> hash;
string str[N];
ULL p[N] , h[N] , MAGIC = 29;

void work()
{
    int i , j , n = 0;
    p[0] = 1;
    for (i = 1 ; i < N ; ++ i)
        p[i] = p[i - 1] * MAGIC;
    while (cin >> str[n])
    {
        h[n] = 0;
        for (i = 0 ; i < str[n].size() ; ++ i)
            h[n] = h[n] * MAGIC + (str[n][i] - 'a' + 1);
        hash.insert(h[n]);
        ++ n;
    }
    for (i = 0 ; i < n ; ++ i)
    {
         ULL x = 0;
         for (j = 0 ; j < str[i].size() ; ++ j)
         {
             x = x * MAGIC + (str[i][j] - 'a' + 1);
             h[i] -= p[str[i].size() - j - 1] * (str[i][j] - 'a' + 1);
             if (hash.count(h[i]) && hash.count(x)) break;
         }
         if (j < str[i].size() - 1) cout << str[i] << endl;
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
