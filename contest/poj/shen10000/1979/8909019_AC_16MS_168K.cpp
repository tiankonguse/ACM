#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

    int i,j,x,y,m,n,k,p;
    char  str[25][25];
    int str1[1000],str2[1000],num;
    int str3[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
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
          
          for(int i=0;i<4;i++)
          {
				int p1=x+str3[i][0];
				int p2=y+str3[i][1];
		   	if(str[p1][p2]!='#')	
			{
                k++;
                num++;
                str1[num]=p1;
                str2[num]=p2;
                str[p1][p2]='#' ;           
            }	
				
		  }
    }
    
    printf("%d\n",k); 
        
}

return 0;
}

