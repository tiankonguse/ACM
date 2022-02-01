#include<stdio.h>
#include<string.h>
char str[100];

int find(int i,int l)
{
while(l)
    if(str[i]<str[l])
        return l;
    else 
        l--;
    
}
void chang(int i,int j)
{
    str[i]^=str[j];
    str[j]^=str[i];
    str[i]^=str[j];
}

void rever(int i,int j)
{
    while(i<j)
        chang(i++,j--);
}

int main()
{
int l,i,j;
while(scanf("%s",str),str[0]!='#')
{
    l=strlen(str)-1;
    int i=l;
    while(i && str[i]<=str[i-1])i--;
    if(i==0)printf("No Successor\n");
    else
    {
        i--;
        j=find(i,l);
        chang(i,j);
        rever(i+1,l);
        printf("%s\n",str);
    }
       
}
return 0;
}