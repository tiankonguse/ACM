#include<stdio.h>
int o[2500], father[2500];

int find(int x)
{
    if(father[x]!=x)
    {
    father[x]=find(father[x]);    
    }    
        
    return father[x];    
}


int main( )
{
int n;
scanf("%d", &n);
for(int k = 0; k < n ; k++)
{
printf("Scenario #%d:\n", k+1);    

int b, t;
scanf("%d%d", &b, &t);

int i;

for(i = 1; i <= b; i++)
{
father[i] = i;
o[i] = 0;    
}
   
int x,y,f,ff,p;
bool mark=false;

for(i = 1; i <= t; i++)
{
    
    scanf("%d%d",&x, &y);

    if(mark)continue;

     f=find(x);
     ff=find(y);    
        
    if(f==ff){mark=true;continue;}    
 
    if(o[x]!=0)
    {
    p=find(o[x]);
    if(ff!=p)father[p]=ff;    
    }  

    if(o[y]!=0)
    {
    p=find(o[y]); 
    if(f!=p)father[p]=f;   
    }   
    
    o[x]=y;
    o[y]=x;  
}    
          if(mark)printf("Suspicious bugs found!\n");
          else printf("No suspicious bugs found!\n");
          printf("\n");    
}



//getchar();getchar();
return 0;
}
