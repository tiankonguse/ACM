#include<stdio.h>
#include<string.h>
char str2[25][130];
void fa0(int s,int m)
{
   int i,j;
   for(i=0;i<s;i++) 
    {
        str2[0][m*(s+3)+1+i]='-';    
        str2[2*s+2][m*(s+3)+1+i]='-';    
    }
    for(i=0;i<2*s+1;i++)
    if(i!=s)
    {
    str2[i+1][m*(s+3)]='|';
    str2[i+1][(s+3)*m+s+1]='|';
    }     
}




void fa1(int s,int m)
{
   int i,j;
   
    for(i=0;i<2*s+1;i++)
    if(i!=s)
   str2[i+1][(s+3)*m+s+1]='|';
     
}



void fa2(int s,int m)
{
   int i,j;
   for(i=0;i<s;i++) 
    {
        str2[0][m*(s+3)+1+i]='-'; 
        str2[s+1][m*(s+3)+1+i]='-';    
        str2[2*s+2][m*(s+3)+1+i]='-'; 
           
    }
    for(i=0;i<s;i++)
     str2[i+2+s][m*(s+3)]='|';

    for(i=0;i<s;i++)
    str2[i+1][(s+3)*m+s+1]='|';
    
    
}


void fa3(int s,int m)
{
   int i,j;
   for(i=0;i<s;i++) 
    {
        str2[0][m*(s+3)+1+i]='-';
         str2[s+1][m*(s+3)+1+i]='-';       
        str2[2*s+2][m*(s+3)+1+i]='-';    
    }
   for(i=0;i<2*s+1;i++)
    if(i!=s)
   str2[i+1][(s+3)*m+s+1]='|';
}



void fa4(int s,int m)
{
   int i,j;
   for(i=0;i<s;i++) 

        str2[s+1][m*(s+3)+1+i]='-';    
  
  for(i=0;i<2*s+1;i++)
    if(i!=s)
   str2[i+1][(s+3)*m+s+1]='|';
  for(i=0;i<s;i++) 
    str2[i+1][m*(s+3)]='|';   
       
}


void fa5(int s,int m)
{
   int i,j;
   for(i=0;i<s;i++) 
    {
        str2[0][m*(s+3)+1+i]='-'; 
        str2[s+1][m*(s+3)+1+i]='-';    
        str2[2*s+2][m*(s+3)+1+i]='-'; 
           
    }
    for(i=0;i<s;i++)
     str2[i+1][m*(s+3)]='|';

    for(i=0;i<s;i++)
    str2[i+2+s][(s+3)*m+s+1]='|';
    
    
}


void fa6(int s,int m)
{
   int i,j;
   for(i=0;i<s;i++) 
    {
        str2[0][m*(s+3)+1+i]='-'; 
        str2[s+1][m*(s+3)+1+i]='-';    
        str2[2*s+2][m*(s+3)+1+i]='-'; 
           
    }
    for(i=0;i<s;i++)
    str2[i+2+s][(s+3)*m+s+1]='|';
    
    for(i=0;i<2*s+1;i++)
    if(i!=s)
   str2[i+1][(s+3)*m]='|';
}


void fa7(int s,int m)
{
   int i,j;
   for(i=0;i<s;i++) 
    {
        str2[0][m*(s+3)+1+i]='-';

    }
   for(i=0;i<2*s+1;i++)
    if(i!=s)
   str2[i+1][(s+3)*m+s+1]='|';
}


void fa8(int s,int m)
{
   int i,j;
   for(i=0;i<s;i++) 
    {
        str2[0][m*(s+3)+1+i]='-'; 
        str2[s+1][m*(s+3)+1+i]='-';    
        str2[2*s+2][m*(s+3)+1+i]='-'; 
           
    }
    for(i=0;i<2*s+1;i++)
    if(i!=s)
    {
    str2[i+1][m*(s+3)]='|';
    str2[i+1][(s+3)*m+s+1]='|';
    }     
}

void fa9(int s,int m)
{
   int i,j;
  for(i=0;i<s;i++) 
    {
        str2[0][m*(s+3)+1+i]='-'; 
        str2[s+1][m*(s+3)+1+i]='-';    
        str2[2*s+2][m*(s+3)+1+i]='-'; 
           
    }
  for(i=0;i<2*s+1;i++)
    if(i!=s)
   str2[i+1][(s+3)*m+s+1]='|';
  for(i=0;i<s;i++) 
    str2[i+1][m*(s+3)]='|';   
       
}


int main()
{
  int s,m,i,j,b=0;
  char str1[10];  
    while(1)
    {   
      
        memset(str2,32,sizeof(str2));
       
        scanf("%d %s",&s,str1); 
          if(s==0)break; 
         if(b==1)
       printf("\n");
        m=strlen(str1);
   
        for(i=0;i<m;i++)   
        switch(str1[i])
        {
        case '0':fa0(s,i); break;  
        case '1':fa1(s,i); break; 
        case '2':fa2(s,i); break;
        case '3':fa3(s,i); break; 
        case '4':fa4(s,i);break;
        case '5':fa5(s,i);break;
        case '6':fa6(s,i);break;
        case '7':fa7(s,i);break;
        case '8':fa8(s,i);break;
        case '9':fa9(s,i); break;
        }
        for(j=0;j<2*s+3;j++)
      {  
        for(i=0;i<(s+3)*m-1;i++) 
        printf("%c",str2[j][i]);
        printf("\n");
        }
    b=1;
    
    }
    
    
getchar();
return 0;    
}
