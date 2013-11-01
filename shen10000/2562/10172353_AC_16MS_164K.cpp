#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 //按F9编译
class ADD
{
  public:
    char str1[500];
    char answer[500];
    int num;
   
  public:
      ADD(){str1[0]='\0';answer[0]='\0';num=0;}      
    int operator = (char*); 
    char* operator + (ADD);  
};
int ADD::operator = (char* p)
{
strcpy(str1,p); 
return 0;       
} 


char* ADD::operator + (ADD q)
{
int n=strlen(str1);
int m=strlen(q.str1);
char str4[500];
strcpy(str4,q.str1);
if(m>n)
{
int t=m;
m=n;
n=t;
strcpy(str4,str1);
strcpy(str1,q.str1);  
}

char str2[500];
int i,j,k,p=0;
       
for(k=0,i=n-1,j=m-1;i>=0&&j>=0;i--,j--,k++) 
{
p+=str1[i]-'0'+str4[j]-'0';    
str2[k]=p%10+'0';
p=p/10;
if(p)num++;   
}  
 
for(;i>=0;i--,k++)
{
p+=str1[i]-'0';    
str2[k]=p%10+'0'; 
p=p/10;
if(p)num++;       
}   
 
if(p)
str2[k++]=p+'0'; 

str2[k]='\0'; 
k--;
while(k>0&&str2[k]=='0')k--;
k++;
for(i=0,j=k-1;i<k;i++,j--)
answer[i]=str2[j];
answer[k]='\0'; 
strcpy(str1,answer);
return answer; 
}



int main()
{
//OJOJ//RA代表空格问题   WA代表答案错误 AC代表正确

char str1[50],str2[50];

while(scanf("%s%s",str1,str2))
{ADD a,b;
int n=strlen(str1);
int m=strlen(str2);    
if(m==1&&n==1&&str1[0]=='0'&&str2[0]=='0')break;    
a=str1;
b=str2;
a+b;
int p=a.num;
switch(p)
{
case 0:printf("No carry operation.\n",p);break;    
case 1:printf("1 carry operation.\n",p);break;    
default:printf("%d carry operations.\n",p);    
    
}
  
}

 //getchar();getchar();getchar();getchar();getchar();getchar();

 return 0;
}