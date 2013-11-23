#include<stdio.h>
#include<string.h>
int str1[21][21][21];
int fun(int a,int b,int c)
{
if(str1[a][b][c]!=-1)return str1[a][b][c];

 if(a<=0||b<=0||c<=0)    
 return str1[a][b][c]=1;   
 
 if(a<b&&b<c) return str1[a][b][c]=fun(a,b,c-1)+fun(a,b-1,c-1)-fun(a,b-1,c);   
 return str1[a][b][c]=fun(a-1,b,c )+fun(a-1,b-1,c )+fun(a-1,b,c-1 )-fun(a-1,b-1,c-1 );  
}


int main()
{
 int x,y,z;
 memset(str1,-1,sizeof(str1));
 while(1)
 {
  scanf("%d%d%d",&x,&y,&z); 
   
if(x==-1&&y==-1&&z==-1)break;
printf("w(%d, %d, %d) = ",x,y,z);    
 if(x<=0||y<=0||z<=0)
{
printf("1\n");
continue;        
}
if(x>20||y>20||z>20)
{
x=y=z=20;        
}    
 printf("%d\n",fun(x,y,z));       
      
} 



getchar();getchar();
return 0;
}
