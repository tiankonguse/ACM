#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;
#define N 10005

char s[N];
int n , ca;
void work()
{
    int i , j , cnt[3] = {} , sum = 0;
    scanf("%s" , s) , n = strlen(s);
    printf("Case %d: " , ++ ca);
    for (i = 0 ; i < n ; ++ i)
        sum += s[i] - '0' , ++ cnt[(s[i] - '0') % 3];
    sum %= 3;
    if (sum != 0 && !cnt[sum])
        puts("T");
    else
    {
        if (!sum)
            ++ cnt[0];
        puts(cnt[0] & 1 ? "T" : "S");
    }
}

void init()
{

}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //init();

    int _; scanf("%d",&_); while (_ --)
    //hile (scanf("%d",&n) , n)
        work();
    return 0;
}
