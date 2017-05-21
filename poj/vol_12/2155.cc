#include"iostream"
#define MAXN 1005
using namespace std;
int N,num[MAXN][MAXN];
int lowbit(int x){
     return x&(-x);
}
void update(int x,int y,int a){
     int t;
     while(x>0){
          t=y;
          while(t>0){
               num[x][t]+=a;
               t-=lowbit(t);
          }
          x-=lowbit(x);
     }
}
int sum(int x,int y){
    int s=0,t;
    while(x<=N){
          t=y;
          while(t<=N){
               s+=num[x][t];
               t+=lowbit(t);
          }
          x+=lowbit(x);
    }
    return s;
}
int main(){
    int T,M,x,y,x1,y1,x2,y2;
    char c;
    scanf("%d",&T);
    while(T--){
         scanf("%d%d",&N,&M);
         memset(num,0,sizeof(num));
         while(M--){
              scanf(" %c",&c);
              if(c=='C'){
                   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                   update(x2,y2,1);
                   update(x2,y1-1,-1);
                   update(x1-1,y2,-1);
                   update(x1-1,y1-1,1);
              }
              else{
                   scanf("%d%d",&x,&y);
                   printf("%d\n",sum(x,y)%2);
              }
         }
         if(T)printf("\n");
    }
   // system("pause");
    return 0;
}
