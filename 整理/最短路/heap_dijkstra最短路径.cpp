#include<stdio.h>
#include<string.h>
struct P
{
   int num;
   int d;      
};
struct HEAP
{
  P p[100];
  int n;       
}heap;
int g[100][100];
void min_heapify(int n)
{
  int temp=n*2;
  if(heap.p[temp].d>heap.p[temp+1].d)
    temp++;
  if(heap.p[n].d>heap.p[temp].d)
  {
    P p_temp;
    p_temp=heap.p[n];
    heap.p[n]=heap.p[temp];
    heap.p[temp]=p_temp;                              
  }     
  min_heapify(temp);
  return ;
}

void build_min_heap()
{
  for(int i=heap.n/2;i>=1;i--)
  {
    min_heapify(i);        
  }     
  return ;
}

void dijkstra()
{
  
  
  build_min_heap();
  int size=heap.n;
  while(size)
  {

    heap.p[1]=heap.p[size];
    for(int i=1;i<=size;i++)
    {
      if(heap.p[i].d>heap.p[size].d+g[heap.p[size].num][heap.p[1].num])
        heap.p[i].d=heap.p[size].d+g[heap.p[size].num][heap.p[1].num];
      if(i<size/2)
        min_heapify(i);           
    }
    size--;
  }  
    
  return ;    
}
 
int main()
{
  int n;
  int s,e,d;
  while(scanf("%d",&n)!=EOF)
  {
    memset(g,9999999,sizeof(g));
    for(int i=1;i<=n;i++)
    {
      scanf("%d %d %d",&s,&e,&d);
      g[s][e]=g[e][s]=d;        
    }    
    for(int i=1;i<=n;i++)
    {
       heap.p[i].d=9999999;
       heap.p[i].num=i;        
    }
    heap.p[1].d=0;
    heap.n=n;
    dijkstra();
    for(int i=1;i<=n;i++)
      printf("~~~~%d->%d\n",heap.p[i].num,heap.p[i].d);
  }
  return 0;    
}
