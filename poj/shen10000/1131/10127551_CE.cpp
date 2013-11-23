#include<stdio.h>
#include<string.h>
char str0[100];
int str1[1000];
int main()
{
int l,len,i,yu;
while(scanf("%s",str0)!=EOF)
{
    memset(str1,0,sizeof(str1));
    len=0;
    for(l=strlen(str0)-1;str0[l]!='.';l--)
    {
        yu=str0[l]-'0';
        for(i=0;i<len || yu;i++)
        {
            yu=yu*10+str1[i];
            str1[i]=yu/8;
            yu=yu%8;
        }
        len=i;
    }
    printf("%s [8] = 0.",str0);
    for(i=0;i<len;i++)
        printf("%d",str1[i]);
    printf(" [10]\n");
}

return 0;
}
//0.75 [8] = 0.953125 [10]