#include<stdio.h>
#include<string.h>
int str0[620][620];
int str1[620][620];
int m,n;
 
int fun1(int i,int j)
{
    int max=0;

    if(str1[i][j]>0)return str1[i][j];

    if(j>0&&str0[i][j]>str0[i][j-1])max=max>fun1(i,j-1)?max:fun1(i,j-1);
    
    if(j<m-1&&str0[i][j]>str0[i][j+1])max=max>fun1(i,j+1)?max:fun1(i,j+1);
    
    if(i>0&&str0[i][j]>str0[i-1][j])max=max>fun1(i-1,j)?max:fun1(i-1,j);
    
    if(i<n-1&&str0[i][j]>str0[i+1][j])max=max>fun1(i+1,j)?max:fun1(i+1,j);
    
 
   return str1[i][j]=max+1; 

}

int main()
{
   
    int   i, j;

    
    scanf ( "%d%d", &n, &m);

     memset(str1,0,sizeof(str1)); 
  
    for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
        scanf ("%d", &str0[i][j]);

   int max=0;
   
    for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) 
    {
    fun1(i,j);   
    }
    
    for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) 
    {
    max=max>str1[i][j]?max:str1[i][j];   
    }
    
    
    printf ( "%d\n", max);

return 0;    
}
