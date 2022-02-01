#include"iostream"
#define inf 1000000
#define MAXN 101
using namespace std;
int map[MAXN][MAXN];
bool used[MAXN];
int N,M;
int main(){
    int a,b;
    while(scanf("%d",&N)&& N){
       memset(used,false,sizeof(used));
       for(int i=0;i<N;i++){
         for(int j=0;j<N;j++){
            map[i][j]=inf;
         }
       }
       for(int i=0;i<N;i++){
            scanf("%d",&M);
            for(int j=0;j<M;j++){
                scanf("%d%d",&a,&b);
                map[i][a-1]=b;
            }     
       }
       for(int k=0;k<N;k++){
           for(int i=0;i<N;i++){
               for(int j=0;j<N;j++){
                   if(map[i][k]+map[k][j]<map[i][j])
                     map[i][j]=map[i][k]+map[k][j];
               }
           }
       }
       for(int i=0;i<N;i++)map[i][i]=-1;
       int max,min=inf,t;
       for(int i=0;i<N;i++){
          max=0;
          for(int j=0;j<N;j++){
             if(map[i][j]>max)
               max=map[i][j];
          }
          if(max<min){min=max;t=i;}
       }
       if(min==inf)printf("disjoint\n");
       else printf("%d %d\n",t+1,min);
    }
    return 0;
}
