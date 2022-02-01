#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
char str[10000];
char c;
while((c=getchar())!=EOF)
{
if(c==10){printf("\n");continue;}
    gets(str);
    int n=strlen(str);
  //  printf("%d ",n);
      if(n!=0)
      {
         int m=n;
         str[m+1]='\0';
         
         for(;m>0;m--)      
           str[m]=str[m-1] ;
           
        str[0]=c;
        n++;    
      }
    else
    {
    if(c=='1')printf("1111\n");
    else printf("1%c1\n",c);
    continue; 
    }

 // printf("%d %d ",n,strlen(str));
//  printf("%s\n",str);
    for(int i=0;i<n;)
    {
          char a=str[i++];
          int k=1;  
          
          while(i<n&&str[i]==a)  
        {
        i++;
        k++;
        if(k==9)break;       
        }
        
        if(k!=1)printf("%d%c",k,a);
        else if(k==1&&i>=n)
        {
            if(a=='1')
            printf("1111");
            else
            printf("1%c1",a);
        }
        else
        {
            printf("1%c",a);
            if(a=='1')
            printf("1");
            
            while(i+1<n&&str[i]!=str[i+1])    
                {
                
                printf("%c",str[i]);
                
                if(str[i]=='1')
                    printf("1");
                i++;         
                }
                
            if(i+1>=n)
                { 
                    printf("%c",str[i]);
                    if(str[i]=='1')
                    printf("1");
                     i++;
                }
                
            printf("1");
        }
        
   
    }   
     printf("\n");
}


return 0;
}
