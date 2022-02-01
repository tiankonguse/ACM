#include"iostream"
#include"algorithm"
#define MAXN 1005
using namespace std;
struct road{
     int x,y;
     friend bool operator<(road a,road b){
          if(a.x==b.x)return a.y<b.y;
          else return a.x<b.x;
     }
}r[MAXN*MAXN];
__int64 num[MAXN];
__int64 lowbit(__int64 x){
     return x&(-x);
}
__int64 sum(int n){
    __int64 s=0;
    while(n>0){
       s+=num[n];
       n-=lowbit(n);
    }
    return s;
}
void update(int p,__int64 a){
    while(p<=MAXN){
       num[p]+=a;
       p+=lowbit(p);
    }
} 
int main(){
    int T,N,M,K;
    __int64 s;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
        memset(num,0,sizeof(num));
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0;i<K;i++){
            scanf("%d%d",&r[i].x,&r[i].y);
        }
        sort(r,r+K);
        s=0;
        for(int i=K-1;i>=0;i--){
            s+=sum(r[i].y-1);
            update(r[i].y,1);
        }
        printf("Test case %d: %I64d\n",ca,s);
    }
  //  system("pause");
    return 0;
}
