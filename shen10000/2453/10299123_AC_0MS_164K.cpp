#include <stdio.h>
int main()
{
    int n,x;
    while(scanf("%d",&n),n)
    {
        x=n&-n;
        printf("%d\n",n+x+(n^n+x)/x/4);
    }
}