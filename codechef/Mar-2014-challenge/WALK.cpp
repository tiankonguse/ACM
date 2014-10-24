#include <iostream>
#include <cstdio>
using namespace std;


void work()
{
    int ans = 0 , n;
    scanf("%d",&n);
    for (int i = 0 , x; i < n ; ++ i)
        scanf("%d",&x) , ans = max(ans , x + i);
    printf("%d\n" , ans);
}

int main()
{
    int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}
