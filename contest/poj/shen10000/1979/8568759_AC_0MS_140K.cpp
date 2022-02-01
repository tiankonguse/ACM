#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

    int i,j,x,y,m,n,k,p;
    char  str[25][25];
    int str1[1000],str2[1000],num;

while(scanf("%d%d",&m,&n)!=EOF)
{
    if(m==0)break;
    memset(str,'#',sizeof(str));

    num=1;
    k=1;
    for(i=1;i<=n;i++)
    {
        getchar(); 
        
        for(j=1;j<=m;j++)
        {
            str[i][j]=getchar();   
            if(str[i][j]=='@')
            {
                str1[num]=i;
                str2[num]=j;
                str[i][j]='#';
            }     
        }          
    }

    
    while(num>0)
    {
          x=str1[num];
          y=str2[num]; 
          num--;
 
          if(str[x+1][y]!='#')
          {
                k++;
                
                num++;

                str1[num]=x+1;
                str2[num]=y;
                str[x+1][y]='#' ;           
          }
           
          if(str[x-1][y]!='#')
          {
                k++;
                num++;

                str1[num]=x-1;
                str2[num]=y;
                str[x-1][y]='#';            
          } 
          
         if(str[x][y+1]!='#')
          {
                k++;
                num++;
                str1[num]=x;
                str2[num]=y+1;
                str[x][y+1]='#';            
          } 
          
         if(str[x][y-1]!='#')
          {
                k++;
                num++;
                str1[num]=x;
                str2[num]=y-1;
                str[x][y-1]='#';            
          }

    }
    
    printf("%d\n",k); 
        
}

return 0;
}
