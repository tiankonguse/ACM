#include"iostream"
#include"cstdlib"
#include"algorithm"
#define MAXN 1001
#define MAXM 20001
using namespace std;
struct edge{
   int u,v,c;
}edges[MAXM];
int parents[MAXN];
int cmp(edge a,edge b){
    return a.c>b.c;
}
int find(int a){
    int x=a,tmp;
    while(parents[a]>=0)a=parents[a];
    while(parents[x]>=0 && parents[x]!=a){
       tmp=parents[x];
       parents[x]=a;
       x=tmp;
    }
    return a;
}
int Union(int a,int b){
   if(parents[a]<parents[b]){
      parents[a]+=parents[b];
      parents[b]=a;
      return parents[a];
   }
   else{
      parents[b]+=parents[a];
      parents[a]=b;
      return parents[b];
   }
}
int main(){
    int N,M,r1,r2,s,sum=0;
    memset(parents,0xff,sizeof(parents));
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
       scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].c);
    }
    sort(edges,edges+M,cmp);
    for(int i=0;i<M;i++){
       r1=find(edges[i].u);
       r2=find(edges[i].v);
       if(r1!=r2){
                  s=Union(r1,r2);
                  sum+=edges[i].c;
       }
    }
    if(s!=-N)printf("-1\n");
    else printf("%d\n",sum);
    //system("pause");
    return 0;
}
