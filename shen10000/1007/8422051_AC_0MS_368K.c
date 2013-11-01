#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{

char str1[105][55] , str2[105][55] , c ;
int str3[105] , str4[105] ;
int m , n , i , j , k ,h;

scanf("%d%d",&m,&n);
for ( i = 0 ; i < n ; i++ )
{
    scanf ( "%s" , str1[i] ) ;
    
    strcpy ( str2[i] , str1[i] ) ;
    
    k=0;
    
    for ( j = 0 ; j < m - 1 ; j++ )
    for ( h = 0 ; h < m - 1 - j ; h++ )
         if ( str2[i][h] > str2[i][h+1] )   
         {
               // printf("%c %c\n",str2[i][h],str2[h][h+1]);
             c = str2[i][h] ;
             str2[i][h] = str2[i][h+1] ;       
             str2[i][h+1] = c ;
             k++;  
             // printf("%c %c\n",str2[i][h],str2[h][h+1]);     
         }
//printf("%s\n\n",str2[i]);
    str3[i] = k ; 
}

for (  i = 0 ; i < n ; i++ )
  str4[i] = i ;


for ( i = 0 ; i < n-1 ; i++ )
    for ( j = 0 ; j < n - 1 - i ; j++ )
        if( str3[str4[j]] > str3[str4[j+1]] ) 
        {
             m = str4[j] ;
             str4[j] = str4[j+1] ;
             str4[j+1] = m ;      
        }   
        else if( str3[str4[j]] == str3[str4[j+1]] )
            if ( strcmp ( str1[str4[j]] , str1[str4[j+1]] ) > 0 )
            {
                 m = str4[j] ;
                 str4[j] = str4[j+1] ;
                 str4[j+1] = m ;           
            }        
        
 for ( i = 0 ; i < n ; i++ )
     printf ( "%s\n" , str1[str4[i]] ) ;   
    

return 0;
}
