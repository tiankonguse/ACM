#include"iostream"
#include"algorithm"
using namespace std;
struct player{
   int id,t;
}p[10001];
int cmp(player a,player b){
     if(a.t==b.t)return a.id<b.id;
     else return a.t>b.t;
}
int main(){
    int N,M,a,d;
    while(scanf("%d%d",&N,&M)){
       if(N==0 && M==0)break;
       for(int i=0;i<=10000;i++){
           p[i].id=i;
           p[i].t=0;
       }
       for(int i=0;i<N;i++){
          for(int j=0;j<M;j++){
             scanf("%d",&a);
             p[a].t++;
          }
       }
       sort(p,p+10001,cmp);
       d=p[1].t;
       for(int i=1;;i++){
          if(p[i].t!=d)break;
          else{
              if(i==1)printf("%d",p[i].id);
              else printf(" %d",p[i].id);
          }
       }
       printf("\n");
    }
    return 0;
}
