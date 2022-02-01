#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
char str[4][4];
int fun(char a)
{int p=0;
 if(str[0][0]==a&&str[0][1]==a&&str[0][2]==a)p++;  
 if(str[1][0]==a&&str[1][1]==a&&str[1][2]==a)p++;  
 if(str[2][0]==a&&str[2][1]==a&&str[2][2]==a)p++;  
 if(str[0][0]==a&&str[1][0]==a&&str[2][0]==a)p++;  
 if(str[0][1]==a&&str[1][1]==a&&str[2][1]==a)p++;  
 if(str[0][2]==a&&str[1][2]==a&&str[2][2]==a)p++;  
 if(str[1][1]==a&&str[0][0]==a&&str[2][2]==a)p++;  
 if(str[0][2]==a&&str[1][1]==a&&str[2][0]==a)p++;   
return p;    
}

int main()
{
//OJOJ//RA代表空格问题   WA代表答案错误 AC代表正确
int num,i,j;
scanf("%d",&num);
while(num--)
{
    for(i=0;i<3;i++)
    scanf("%s",str[i]) ;
    int n=0,m=0,p=0,q=0;
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {
    if(str[i][j]=='O')n++;
    if(str[i][j]=='X')m++;   
    } 
  //  printf("%d %d\n",n,m);  
    if(m<n||m>n+1){printf("no\n");continue;}
    
    p=fun('O');
    q=fun('X');
    //printf("%d %d\n",p,q);
    if(((!q)==0&&p==0&&m==n+1)||(q==0&&p==1&&m==n)||(q==0&&p==0)){printf("yes\n");continue;}
    printf("no\n");
}


 return 0;
}