#include<stdio.h>
#include<string.h>

int str1[30]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2,0};

int main()
{

char str0[30];
while(scanf("%s",str0)!=EOF)
{ 
    int q;
    int i=0;
    int n=strlen(str0);
    int p=str1[str0[i]-'A'];
    if(p!=0)
        printf("%d",p);
    i++;
    while(i<n)
    {
    q=str1[str0[i]-'A'];
    if(q!=p&&q!=0)
        printf("%d",q);
    p=q;
    i++;
    }  
printf("\n");
}

return 0;
}
