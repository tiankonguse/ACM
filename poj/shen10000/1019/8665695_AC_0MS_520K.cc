
#include<stdio.h>

int str3[40000];
   
int main()
{
//OJOJ//RA代表空格问题   WA代表答案错误 AC代表正确
int i,p=1,q=1;
for(i=1;i<=32005;i++)
{
    str3[i]=p; 
if(i==9||i==99||i==999||i==9999)    
q++;    
  p+=q;
}

int n;
scanf("%d",&n);

while(n--)
{
    int m;
    scanf("%d",&m);
    
    i=1;
    while(m-str3[i]>0)
    {
    m-=str3[i]; 
    i++; 
    }  

    p=i;q=1;
    
    for(i=1;i<=p;i++)
    {
    if(m-q<=0)break;
    m-=q;
    if(i==9||i==99||i==999||i==9999)
    q++;      
    }     
    char str0[1000];

    sprintf(str0,"%d",i);    
    printf("%c\n",str0[m-1]);    
        
}

 return 0;
}

