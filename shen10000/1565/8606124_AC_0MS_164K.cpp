#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{

    char c_ar[33];
    int n,i;
    long long sum1,sum2,str[33];

    while(1)
    {
    scanf("%s",c_ar);
    
    n=strlen(c_ar);  
     
    if(n==1&&c_ar[0]==48)break;
    
    sum1=0;
    sum2=0;
    for(i=0;i<n;i++)
    {
    sum1=sum1*2+c_ar[i]-48;
    sum2+=c_ar[i]-48;      
    }  
    
    sum1*=2;  
        
    printf("%lld\n",sum1-sum2);    
    
    
    
    
    
}

//getchar();getchar();
return 0;
}
