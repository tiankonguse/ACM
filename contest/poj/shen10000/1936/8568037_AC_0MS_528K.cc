#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str1[105050],str2[105050];
    int m,i,j,n;
while(scanf("%s%s",str1,str2)!=EOF)
{   

m=strlen(str1);

n=strlen(str2);

for(i=0,j=0;i<n;i++)
    {
    if(str1[j]==str2[i])j++;
    if(j==m)break;   
    } 
    
    if(j==m)printf("Yes\n");
    else printf("No\n");       

  
}
    

return 0;
}
