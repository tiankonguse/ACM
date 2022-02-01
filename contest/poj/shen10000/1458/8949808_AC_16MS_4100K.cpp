#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
char str1[1000],str2[1000];
int str0[1001][1001]; 

int max(int a,int b)
{
return a>b?a:b;    
}


int fun(int m,int n)
{
if(str0[m][n]!=-1)
{
    return str0[m][n];
}

if(m==0||n==0)
{
	return str0[m][n]=0;
}
  
if(str1[m-1]==str2[n-1])
    return str0[m][n]=fun(m-1,n-1)+1;
    
return str0[m][n]=max(fun(m-1,n),fun(m,n-1));
   
}





int main()
{
while(scanf("%s%s",str1,str2)!=EOF)
{
memset(str0,-1,sizeof(str0));    
int m=strlen(str1);
int n=strlen(str2);   
printf("%d\n",fun(m,n)); 

}

return 0;
}

