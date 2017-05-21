#include"iostream"
#define inf 1000000
using namespace std;
struct edge{
   int s,e,w;
}edges[5300];
int d[501];
int N,M,W;
int bellman_ford(int count){
     int flag;
     for(int i=1;i<N;i++)d[i]=inf;
     d[0]=0;
     for(int i=0;i<N;i++){
         flag=1;
         for(int j=0;j<count;j++){
             if(d[edges[j].s]>d[edges[j].e]+edges[j].w){
                d[edges[j].s]=d[edges[j].e]+edges[j].w;
                flag=0;
             }
         }
         if(flag)break;
     }
     for(int j=0;j<count;j++)
       if(d[edges[j].s]>d[edges[j].e]+edges[j].w)
       return 0;
     return 1;
}
int main(){
   int F,i,j,a,b,c;
   scanf("%d",&F);
   while(F--){
       scanf("%d%d%d",&N,&M,&W);
       j=0;
       for(i=0;i<M;i++){
             scanf("%d%d%d",&a,&b,&c);
             edges[j].s=a;
             edges[j].e=b;
             edges[j++].w=c;
             edges[j].s=b;
             edges[j].e=a;
             edges[j++].w=c;
       }
       for(i=0;i<W;i++){
             scanf("%d%d%d",&a,&b,&c);
             edges[j].s=a;
             edges[j].e=b;
             edges[j++].w=-c;
       }
       if(bellman_ford(j))printf("NO\n");
       else printf("YES\n");
   }
   return 0;
}
