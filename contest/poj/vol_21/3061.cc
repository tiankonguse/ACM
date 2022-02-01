#include"iostream"
#define MAXN 100005
using namespace std;
int q[MAXN];
int main(){
    int T,N,S,l,h,t,sum,res;
    scanf("%d",&T);
    while(T--){
         scanf("%d%d",&N,&S);
         l=h=sum=0;
         res=MAXN;
         for(int i=0;i<N;i++){
             scanf("%d",&t);
             sum+=t;
             q[h++]=t;
             while(sum-q[l]>=S){
                 sum-=q[l++];
             }
           //  printf("i=%d,sum=%d,l=%d,h=%d\n",i,sum,l,h);
             if(sum>=S && h-l<res)res=h-l;
         }
         if(res==MAXN)printf("0\n");
         else printf("%d\n",res);
    }
   // system("pause");
    return 0;
}
