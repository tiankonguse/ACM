#include"iostream"
#define MAXN 30001
using namespace std;
int parents[MAXN];
int Find(int x){
    while(parents[x]>0)x=parents[x];
    return x;
}
int Union(int a,int b){
    while(parents[a]>0)a=parents[a];
    while(parents[b]>0)b=parents[b];
    if(parents[a]<parents[b]){
         parents[a]+=parents[b];
         parents[b]=a;
         return a;
    }
    else{
         parents[b]+=parents[a];
         parents[a]=b;
         return b;
    }
    
}
int main(){
    int N,M,P,tmp1,tmp2;
    while(scanf("%d%d",&N,&M)&&(N||M)){
      memset(parents,-1,N*sizeof(parents[0]));
      for(int i=0;i<M;i++){
          scanf("%d",&P);
          scanf("%d",&tmp1);
          for(int j=1;j<P;j++){
              scanf("%d",&tmp2);
              if(Find(tmp1)!=Find(tmp2))tmp1=Union(tmp1,tmp2);
          }
      }
      printf("%d\n",-parents[Find(0)]);
    }
    return 0;
};
