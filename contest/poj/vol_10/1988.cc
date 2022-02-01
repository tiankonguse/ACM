#include"iostream"
#define MAXN 30001
using namespace std;
int parents[MAXN],v[MAXN],cnt[MAXN];
void init(){
     for(int i=1;i<MAXN;i++){
        parents[i]=i;
        cnt[i]=1;
     }
}
int find(int x){
     if(parents[x]==x)return x;
     int a=find(parents[x]);
     v[x]+=v[parents[x]];
     parents[x]=a;
     return a;
}
int main(){
    int P,a,b,ta,tb;
    char c;
    init();
    scanf("%d",&P);
    while(P--){
       scanf(" %c",&c);
       if(c=='M'){
           scanf("%d%d",&a,&b);
           ta=find(a),tb=find(b);
           parents[ta]=tb;
           v[ta]=cnt[tb];
           cnt[tb]+=cnt[ta];
       }
       else{
           scanf("%d",&a);
           find(a);
           printf("%d\n",v[a]);
       }
    }    
  //  system("pause");
    return 0;
}
