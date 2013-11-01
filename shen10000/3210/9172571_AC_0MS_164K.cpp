#include<stdio.h>
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int m;
    while(scanf("%d",&m),m)
    {
    if(m%2)printf("%d\n",m-1);
    else printf("No Solution!\n");
    }

return 0;
}
