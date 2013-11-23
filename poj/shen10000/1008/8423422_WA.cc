#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<iostream>
//using namespace std;
int fun1 ( int m , char c)
{
 switch(m)
{
case 0:return (11);
case 3:return (8);
case 4:return (13);
case 6:return (12);
case 9:return (15);
case 14:return (18);
case 16:return (17);
case 18:
  if(c=='y')return(9);
   return(16);   
case 19:return (10);
case 20:return (7);
case 21:return (1);
case 23:return (0);
case 26:return (14);       
case 27:return (2);        
case 32:return (6);
case 33:return (3);
case 37:return (5);
case 38:return (4);        
}   
    
    
}


int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int n , i , j , m , t , r , y;
char c , str1[10] , str2[10] ;
char str3[21][10]={ "ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac" };
scanf ( "%d" , &n ) ;
printf ( "%d\n" , n ) ;
for ( i = 0 ; i < n ; i++ )
{
scanf ( "%d" , &r) ;  
getchar();  
scanf ( "%s%d" , str1 , &y ) ;

t = str1[0] + str1[1] - 200 ;

t = fun1( t , str1[0] ) ;

t = y * 365 + t *  20 + r + 1 ;

 y = t / 260 ;
t = t % 260 ;
m = t % 13 ;
r = t % 20 ;
printf("%d %s %d\n",m,str3[r],y);

}

return 0;
}
