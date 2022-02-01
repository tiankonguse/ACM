#include<stdio.h>
#include<string.h>
int str[101][101],str2[101][101];
int max1,max2;
int n;

void seach(const int a,const int b)
{
int i,j;
for(i=a;i<n;i++)   
for(j=b;j<n;j++)
{
    if(i==a&&j==b)
    {
    str2[i][j]=str[i][j];
    max2=str2[i][j];
    continue;    
    }    
    else if(i==a)
    {
    str2[i][j]=str[i][j]+str2[i][j-1];  
    max2=max2>str2[i][j]?max2:str2[i][j]; 
    continue;   
    }
    else if(i==b)
    {
    str2[i][j]=str[i][j]+str2[i-1][j];  
    max2=max2>str2[i][j]?max2:str2[i][j]; 
    continue;   
    }
    else
    {
    str2[i][j]=str[i][j]+str2[i][j-1]+str2[i-1][j]-str2[i-1][j-1];  
    max2=max2>str2[i][j]?max2:str2[i][j]; 
     continue;   
    }
    
}  
  
}

int main()
{
int i,j;
while(1){
scanf("%d",&n);

for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
    scanf("%d",&str[i][j]);

}

max1=str[0][0];
    
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
memset(str2,0,sizeof(str2));

seach(i,j);

max1=max1>max2?max1:max2;
}
printf("%d\n",max1);
}
return 0;
}
