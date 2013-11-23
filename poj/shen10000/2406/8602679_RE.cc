#include<stdio.h>
#include<string.h>
char str1[10009],str2[10009];

int find(char a[],char b[],int n)
{
 int i;
 for(i=0;i<n;i++)
     if(a[i]!=b[i])
         return 0;
 
 return 1;   
    
}

int main()
{
char *p;
int len,i,k;
while(scanf("%s",str1),strcmp(str1,".")!=0)
{
    len=strlen(str1);
    
    for(i=0;i<len;i++)
    {
        str2[i]=str1[i];
        k=i+1;
        str2[k]='\0';    
    
        if(len%k==0)   
        {
        p=str1+k;
        while(find(p,str2,k))
        p+=k;
        if(p==str1+len)    
          break;  
        }
    }
       printf("%d\n",len/k);
} 
return 0;
}
