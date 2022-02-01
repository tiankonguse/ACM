#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[12][12],str2[12][12];
int fun(int i,int j)
{char p='0';
if(str1[i-1][j-1]=='*')p++;    
if(str1[i-1][j]=='*')p++;    
if(str1[i-1][j+1]=='*')p++;    
if(str1[i][j-1]=='*')p++;    
if(str1[i][j+1]=='*')p++;    
if(str1[i+1][j-1]=='*')p++;    
if(str1[i+1][j]=='*')p++;    
if(str1[i+1][j+1]=='*')p++;    
    
return p;    
}

int main()
{
//OJOJ//RA代表空格问题   WA代表答案错误 AC代表正确
int m,i,j;

bool h=true;
while(scanf("%d",&m)!=EOF)
{
    memset(str1,'.',sizeof(str1));
    if(h==false)printf("\n");
    h=false;


    for(i=1;i<=m;i++)
    {
    getchar();
    for(j=1;j<=m;j++)
    scanf("%c",&str1[i][j]);
    }
   
    
    for(i=1;i<=m;i++)
    {
    getchar();
    for(j=1;j<=m;j++)
    scanf("%c",&str2[i][j]);
    }

    bool ch=true;
    for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
    if(str2[i][j]=='x')
    {
        if(str1[i][j]=='*')ch=false;    
         else str2[i][j]=fun(i,j);   
    }   

if(ch==false)    
    for(i=1;i<=m;i++)
    for(j=1;j<=m;j++)
    if(str1[i][j]=='*')str2[i][j]='*';    
 


    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        printf("%c",str2[i][j]);
    
    printf("\n");   
    }    





}
 return 0;
}