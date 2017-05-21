#include"string.h"
#include"cstdio"
#include"queue"
#include"iostream"
#include"algorithm"
#define MAXN 10001
using namespace std;
int parents[MAXN];
struct ar{
   int d,s;
   bool operator <(const ar &a) const
   {
      if(a.s==s)return d>a.d;
      else return s>a.s;
   }
}a[MAXN],tmp;
int cmp(ar a,ar b){
    return a<b;
}
int find(int x){
    if(parents[x]!=x)parents[x]=find(parents[x]);
    return parents[x];
}    
int main(){
    int M,N,sum,d,s;
    while(~scanf("%d",&N)){
        M=sum=s=0;
        for(int i=1;i<=N;i++){
                scanf("%d%d",&a[i].s,&a[i].d);
                s+=a[i].s;
                if(a[i].d>M)M=a[i].d;
        }
        for(int i=0;i<=M;i++)parents[i]=i;
        sort(a+1,a+N+1,cmp);
        for(int i=1;i<=N;i++){
            d=find(a[i].d);
            if(d==0)sum+=a[i].s;
            else parents[d]=find(d-1);
        }
        printf("%d\n",s-sum);
    }
    return 0;
}
