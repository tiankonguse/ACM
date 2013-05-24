//pku-1775-Sum of Factorials
#include <iostream>
using namespace std;

int main()
{
    long fac[11] = {1,1,2,6,24,120,720,5040,40320,362880};
    long n, i;
    while (scanf("%d", &n)==1 && n >= 0) {
        if (n == 0) {
            printf("NO\n");
            continue;
        }
        
        for (i = 10; i >= 0;--i) {
            if (fac[i] <= n)
                n -= fac[i];
        }
        if (n == 0)
            printf("YES\n");
        else
            printf("NO\n");
        
    }    
    return 0;
}
