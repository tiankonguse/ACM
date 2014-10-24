#include <iostream>
#include <cstdio>
using namespace std;
int n;

void work()
{
    int i , x , s1 = 0 , s2 = 0;
    long long ans = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
    {
        scanf("%d",&x);
        if (x == 2)
            ans += s2;
        else if (x > 2)
            ans += s1;
        if (x > 2) ++ s2;
        if (x > 1) ++ s1;
    }
    cout << ans << endl;
}

int main()
{
    int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}
