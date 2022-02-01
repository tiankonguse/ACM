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
#define N 1005
int n , ca ;
char str[N];
int cnt[26];

void work()
{
    int i , j , x , res = 0;
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    for (i = 1 ; i <= n ; ++ i) {
        memset(cnt , 0 , sizeof(cnt));
        x = 0;
        for (j = i ; j <= n ; ++ j) {
            if (cnt[str[j] - 'a'])
                -- x;
            else
                ++ x;
            cnt[str[j] - 'a'] ^= 1;
            if (x <= 1)
                ++ res;
        }
    }
    printf("Case %d: %d\n" , ++ ca , res);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
