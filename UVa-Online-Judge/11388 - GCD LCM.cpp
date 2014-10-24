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

void work()
{
    int a , b;
    scanf("%d%d",&a,&b);
    if (b % a != 0)
        puts("-1");
    else
        printf("%d %d\n" , a , b);

}

int main()
{
    //freopen("~input.txt" , "r" , stdin);

    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
