#include<stdio.h>

int main()
{
int m;
scanf("%d",&m);
while(m--) 
{
    int n;
    scanf("%d",&n);
    int p;
    scanf("%d",&p);
    n--;
    int max=p,min=p;
    while(n--)    
    {
    scanf("%d",&p);
    max=max>p?max:p;
    min=min<p?min:p;       
    }   
    printf("%d\n",(max-min)*2);    
}

return 0;
}
