#include<stdio.h>
//#include<iostream>
//using namespace std;
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
    int x,y,z,i,j,n,m,l;
    int max=10000;
    for(i=2972;i<max;i++)
    {
        l=n=m=i;
        z=y=x=0;   
        for(j=0;j<4;j++)
        {
            x+=n%12;
            n=n/12;
            
            y+=m%16;
            m=m/16;
            
            z+=l%10;
            l=l/10; 
         }    
            if(z==x&&z==y)printf("%d\n",i); 
       
       
    }

getchar();getchar();
return 0;
}
