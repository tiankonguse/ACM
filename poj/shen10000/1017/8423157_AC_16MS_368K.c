#include<stdio.h>
int main()
{
    int a,b,c,d,e,f;
    int num,str;
    while(1)
    {
             scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);   
            if((a+b+c+d+e+f)==0)break;
            num=f+e;
            //五箱 
            if(a>11*e)a-=11*e;
            else a=0;
            
            
            //四箱 
            num+=d;
            if(b>5*d)b-=5*d;
            else
            {   str=4*(5*d-b);
                b=0;
                if(a>str)a=a-str;
                else a=0;    
            }   
                
           //三箱
           num+=(3+c)/4;
                
           switch(c%4)
           {
                
                
               case 1:
                    
                    if(b>5)
                        {
                              b-=5;
                              if(a>7)a-=7;
                              else a=0;      
                        }
                      else 
                        {
                             str=27-4*b;
                             b=0;
                             if(a>str) a-=str;
                             else a=0;       
                        }
                        
                      
                    break;  
                        
               case 2:
                    
                     if(b>3)
                       {
                            b-=3;    
                            if(a>6)a-=6;
                            else a=0;    
                        }
                     else
                        {
                            str=18-4*b;
                            b=0;
                            if(a>str)a-=str;
                            else a=0;  
                        }
                        
                    break;    
                           
               case 3:  
                    
                    if(b>=1)
                        {
                            b--;
                            if(a>5)a-=5;
                            else a=0;    
                        }
                        else
                        { 
                            
                            if(a>9)a-=9;
                            else a=0;    
                        }
                 break;       
  
               default:break;                 
            }     
           
           
           //二箱
           
           num+=(8+b)/9;
           if(b%9>0)
           {
           str=36-(b%9)*4;
           if(a>str)a-=str;
           else a=0;
            } 
            
            
           //一箱
           num+=(35+a)/36;
           printf("%d\n",num);    
}
 
return 0;    
}
