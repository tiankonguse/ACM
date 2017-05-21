#include <iostream>
using namespace std;

const int px[6]={0,0,0,0,1,-1};
const int py[6]={0,0,-1,1,0,0};
const int pz[6]={1,-1,0,0,0,0};
struct Point
{
   int x,y,z,length;       
}d[100000];
int l,r,c;
char map[40][40][40];
bool visit[40][40][40];

int bfs(int xx,int yy,int zz)
{
   int i,s,t,ans,x,y,z;
   memset(visit,false,sizeof(visit));
   memset(d,0,sizeof(d));
   visit[xx][yy][zz]=1;
   d[0].x=xx,d[0].y=yy,d[0].z=zz; 
   s=t=0;    
   while(s<=t)
   {
      for(i=0;i<6;i++)
      {
         x=d[s].x+px[i];
         y=d[s].y+py[i];
         z=d[s].z+pz[i];
         if(!visit[x][y][z]&&(map[x][y][z]=='.'||map[x][y][z]=='E'))
         {
            visit[x][y][z]=true;
            d[++t].x=x;
            d[t].y=y;
            d[t].z=z;
            d[t].length=d[s].length+1;
            if(map[x][y][z]=='E')
              return d[t].length;                                      
         }                 
      } 
      s++;          
   }
   return -1;
}

int main()
{
   int i,j,k,sx,sy,sz,ans;
   while(scanf("%d%d%d",&l,&r,&c)!=EOF)
   {
      if(l==0||r==0||c==0) break;
      memset(map,0,sizeof(map));

        for(i=1;i<=l;i++)
          for(j=1;j<=r;j++)
           for(k=1;k<=c;k++)
          {
             cin>>map[i][j][k];
             if(map[i][j][k]=='S')
             {
               sx=i;
               sy=j;
               sz=k;               
             }
          }                 
      ans=bfs(sx,sy,sz);  
      if(ans==-1)
        printf("Trapped!\n");
      else
    printf("Escaped in %d minute(s).\n",ans);                                
   }
   return 0;
}
