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
int num[19] = {} , n;
int power[10];
char s[20];
void work()
{
    int i , j , x , y;
    for (i = 1 ; i < 19 ; ++ i)
        if (n > num[i])
            n -= num[i];
        else
            break;
    x = i , -- n;
    if (x == 1)
        printf("%d\n" , n + 1);
    else if (x & 1)
    {
        j = n / 10  , y = n % 10;
        sprintf(s , "%d" , power[(x - 2) >> 1] + j);
        printf("%s" , s);
        printf("%d" , y);
        reverse(s , s + strlen(s));
        printf("%s\n" , s);
    }
    else
    {
        sprintf(s , "%d" , power[(x - 1) >> 1] + n);
        printf("%s" , s);
        reverse(s , s + strlen(s));
        printf("%s\n" , s);
    }


}

void init()
{
    int i ;
    num[1] = num[2] = 9;
    for (i = 3 ; i < 19 ; ++ i)
        if (i & 1)
            num[i] = num[i - 1] * 10;
        else
            num[i] = num[i - 1];
    power[0] = 1;
    for (i = 1 ; i < 10 ; ++ i)
        power[i] = power[i - 1] * 10;

}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    init();

    //int _; scanf("%d",&_); while (_ --)
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
