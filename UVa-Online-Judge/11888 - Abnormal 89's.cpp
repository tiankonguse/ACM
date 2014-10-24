#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 200005
ULL MAGIC = 31;
ULL power[N] , L[N] , R[N];
int n;
char s[N];

void work()
{
    int i ; ULL x , y;
    scanf("%s" , s + 1) , n = strlen(s + 1);
    L[0] = 0;
    for (i = 1 ; i <= n ; ++ i)
        L[i] = L[i - 1] * MAGIC + s[i] - 'a' + 1;
    R[n + 1] = 0;
    for (i = n ; i >= 1 ; -- i)
        R[i] = R[i + 1] * MAGIC + s[i] - 'a' + 1;
    for (i = 1 ; i < n ; ++ i) // 1 ~ i , i + 1 ~ n
    {
        x = L[n] - L[i] * power[n - i];
        y = R[1] - R[i + 1] * power[i];
        if (x == R[i + 1] && y == L[i])
            break;
    }
    if (i < n)
        puts("alindrome");
    else if (L[n] == R[1])
        puts("palindrome");
    else
        puts("simple");
}

int main()
{
    freopen("~input.txt" , "r" , stdin);

    power[0] = 1;
    for (int i = 1 ; i <= 200000 ; ++ i)
        power[i] = power[i - 1] * MAGIC;
    int _; scanf("%d" , &_); while (_ --)
        work();
    return 0;
}
