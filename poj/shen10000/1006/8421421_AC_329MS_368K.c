#include<stdio.h>

int main()
{
 
    int  i , a , b , c , d , k=1;
    
    while ( 1 )
    {
        scanf ( "%d%d%d%d" , &a , &b , &c , &d ) ; 
        
        if( a == -1 ) break ;   
        
        for( i = 1 ; ; i++ )
            if(( i + d - a ) % 23 == 0 && ( i + d - b ) % 28 == 0 && ( i + d - c ) % 33 == 0 ) break;  
          
        printf( "Case %d: the next triple peak occurs in %d days.\n" , k , i);
        
        k++ ;       
    }

return 0 ;

}
