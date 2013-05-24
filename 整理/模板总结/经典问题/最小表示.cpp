/*
ID: zhangzz4
PROG: hidden
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=100010;
int n,l;
char s[N*2];
int main()
{
    freopen("hidden.in","r",stdin);
    freopen("hidden.out","w",stdout);
    scanf("%d",&n);
    s[0]=0;
    char str[80];
    while(scanf("%s",str)==1)
    {
         strcat(s,str);
         int len=strlen(str);
         s[l+=len]=0;
    }
    for(int i=0;i<n;i++) s[n+i]=s[i];
    s[n+n]=0;
    int i=0,j=1,k=0;
    while(j<n)
    {
        if(i==j) j++;
        k=0;
        while(k<=n&&s[i+k]==s[j+k]) k++;
        if(k>n) break;
        if(s[i+k]>s[j+k]) i=i+k+1;
        else j=j+k+1;   
    }
    printf("%d\n",i);
}
