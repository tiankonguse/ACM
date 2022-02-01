#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
int str1[205][2],str2[205];

void fun1(int m)
{
for(int i=0;i<m-1;i++)
for(int j=0;j<m-1-i;j++)
    if(str1[j][0]>str1[j+1][0])
    {
     
        int h;
        h=str1[j][0];
        str1[j][0]=str1[j+1][0];
        str1[j+1][0]=h;
        
        h=str1[j][1];
        str1[j][1]=str1[j+1][1];
        str1[j+1][1]=h;                   
    }     
    return;     
}

int fun2(int m)
{
int k=0;
int p=0;
int last=0;
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<m;i++)
        {
            if(p==0&&str2[i]==-1)
            {
                p=1;
                k++;
                last=str1[i][1] ;                  
            }       
            else if(str2[i]==-1)
            {
                if(str1[i][0]>last)
                {
                    last=str1[i][1] ;   
                    str2[i]=1;   
                }   
            }   
        }    
    p=0;  
    }
return k;  
}

int main()
{
int t;
scanf("%d",&t);
while(t--)
{
memset(str2,-1,sizeof(str2));
int m;
scanf("%d",&m);
for(int i=0;i<m;i++)
{
    int a,b;
    scanf("%d%d",&a,&b);
    
    if(a>b)
    {
    a=a+b;
    b=a-b;
    a=a-b;              
    } 
    
    str1[i][0]=a;
    str1[i][1]=b;       
}         

fun1(m);          

printf("%d\n",10*fun2(m)); 
          
}
        
return 0;                
}
