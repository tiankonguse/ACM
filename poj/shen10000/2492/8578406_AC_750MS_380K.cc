#include<stdio.h>
//#include<stdlib.h> 
int o[2005],rank[2005],father[2005];//o[]表对象 
int find(int x)
{
    if(x!=father[x])
     father[x]=find(father[x]);
     return father[x];
}
void Union(int x,int y)
{
     if(x==y)
       return ;
  //   if(rank[x]>rank[y])father[y]=x;
    // else{  if(rank[x]==rank[y])
   //           rank[y]++;
            father[x]=y;
    //     }
}
int main()//女性一支，男性一支 
{int n,b,t,i,mark,f,ff,x,y,f1, ff1, count=0;
scanf("%d",&n);
while(n--)
{
          count++;
          mark=0;
          scanf("%d%d",&b,&t);
          for(i=1;i<=b;i++)
          {rank[i]=0;
          father[i]=i;
          o[i]=0;}
          for(i=1;i<=t;i++)
          {
            scanf("%d%d",&x,&y);
            if(mark)continue;
            f=find(x);
            ff=find(y);
            if(f==ff)mark=1;
            else{ if(o[x]!=0)
                  {f1=find(o[x]); 
                   //错了几次在这里，本来想省一个变量，却变成悲剧！
                   Union(f1,ff);}
                   
                   if(o[y]!=0)
                   {ff1=find(o[y]);
                   Union(f,ff1);}
                }
            o[x]=y;
            o[y]=x;
          }
          printf("Scenario #%d:\n",count);
          if(mark)printf("Suspicious bugs found!\n");
          else printf("No suspicious bugs found!\n");
          printf("\n");
}
//system("pause"); 
return 0;
}
