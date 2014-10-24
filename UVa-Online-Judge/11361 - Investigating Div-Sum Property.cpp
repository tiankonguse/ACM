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
#define N 40005

int a , b , k;
int dp[20][100][100];
int digit[20] , power[20];

int dfs(int pos , int mod0 , int mod1 , bool doing)
{
    if (pos == -1)
        return mod0 == 0 && mod1 == 0;
    if (!doing && ~dp[pos][mod0][mod1])
        return dp[pos][mod0][mod1];
    int ans = 0;
    int end = doing ? digit[pos] : 9;
    for(int i = 0 ; i <= end ; i ++)
        ans += dfs(pos - 1 , (mod0 + i) % k , (mod1 + i * power[pos]) % k  , doing && i == end);
    if(!doing)
        dp[pos][mod0][mod1] = ans;
    return ans;
}

int cal(int x)
{
    memset(dp , -1 , sizeof(dp));
    int pos = 0;
    while(x)
    {
        digit[pos ++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1 , 0 , 0 , 1);
}

void work()
{
    scanf("%d%d%d",&a,&b,&k);
    if (k > 100)
        puts("0");
    else
        printf("%d\n" , cal(b) - cal(a - 1));
}


int main()
{
    freopen("~input.txt" , "r" , stdin);
    power[0] = 1;
    for (int i = 1 ; i < 10 ; ++ i)
        power[i] = power[i - 1] * 10;
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
