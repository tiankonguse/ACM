#include"iostream"
#include"algorithm"
#define MAXN 100005
using namespace std;
struct cow{
    int idx,l,r;
    friend bool operator<(cow a,cow b){
        if(a.r==b.r)return a.l>b.l;
        else return a.r<b.r;
    }
}cow[MAXN];
int num[MAXN],cnt[MAXN];
int lowbit(int x){
     return x&(-x);
}
int sum(int n){
    int s=0;
    while(n>0){
       s+=num[n];
       n-=lowbit(n);
    }
    return s;
}
void update(int p,int a){
    while(p<=MAXN){
       num[p]+=a;
       p+=lowbit(p);
    }
} 
int main(){
    int N,a,b;
    while(scanf("%d",&N)&&N){
        memset(num,0,sizeof(num));
        for(int i=0;i<N;i++){
           scanf("%d%d",&cow[i].l,&cow[i].r);
           cow[i].idx=i;
           cow[i].l++;
           cow[i].r++;
        }
        sort(cow,cow+N);
        for(int i=N-1;i>=0;i--){
          //  printf("%d %d\n",cow[i].l,cow[i].r);
           if(i<N-1 && cow[i].l==cow[i+1].l && cow[i].r==cow[i+1].r){
               cnt[cow[i].idx]=cnt[cow[i+1].idx];
           }
           else cnt[cow[i].idx]=sum(cow[i].l);
           update(cow[i].l,1);
        }
        for(int i=0;i<N;i++){
           if(i==N-1)printf("%d\n",cnt[i]);
           else printf("%d ",cnt[i]);
        }
    }
    return 0;
}
