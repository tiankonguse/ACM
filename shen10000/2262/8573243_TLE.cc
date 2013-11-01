#include<stdio.h>
int j;

int str[79000]={2,3};

void fun()
{
    //printf("123");
int k;
for(int i=5,j=2;i<1000005;i+=2)    
{
    for(k=1;k<j;k++)
        if(i%str[k]==0)
            break;            
    
    if(k>=j)
        str[j++]=i;      
}        
 
}

int main()
{

fun();
for(int i=0;i<8;i++)printf("%d ",str[i]);
int m=j;
int n;
while(scanf("%d",&n)&&n!=0)
{
    int k=1;
    for(int i=0;str[i]<n;i++)
    {
    for(int j=i;str[j]<n;j++)
        if(str[i]+str[j]==n)
            {
                k=0;
            printf("%d = %d + %d\n",n,str[i],str[j]);
            break;
            } 
    if(k==0)break;
    } 

}   
    

return 0;
}
