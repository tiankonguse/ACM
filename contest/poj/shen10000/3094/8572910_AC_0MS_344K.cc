#include<stdio.h>
#include<string.h>

int main()
{
    while(1)
    {
        char str0[300];
        gets(str0);
        if(str0[0]=='#')break;
        int m=strlen(str0);    
        int sum=0;
        
        for(int i=0;i<m;i++)
        {
            int n;
            if(str0[i]==' ')n=0;
            else n=str0[i]-64;
            
            sum+=(i+1)*n;        
        }   
        printf("%d\n",sum);    
    } 
return 0;
}
