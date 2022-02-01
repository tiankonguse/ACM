#include"iostream"
#define MAXN 2001
using namespace std;
int parents[2001],v[2001];
bool flag;
int find(int x){
    if(parents[x]==x)return x;
    int a=find(parents[x]); //此处不能写成find(x) 
    v[x]=(v[x]+v[parents[x]])%2;
    parents[x]=a;
    return a;
}
void init(int N){
     for(int i=1;i<=N;i++){
         parents[i]=i;
         v[i]=0;
     }
     flag=true;
}
int main(){
    int T,N,K,a,b,ta,tb;
    scanf("%d",&T);
    for(int s=1;s<=T;s++){
         scanf("%d%d",&N,&K);
         init(N);
         while(K--){
             scanf("%d%d",&a,&b);
             if(flag){
                ta=find(a),tb=find(b);
                if(ta==tb){
                    if(v[a]==v[b])flag=false;
                }
                else{
                    parents[tb]=ta;
                    v[tb]=(v[a]-v[b]+3)%2;
                }
             }
         }
         printf("Scenario #%d:\n",s);
         if(flag)printf("No suspicious bugs found!\n\n");
         else printf("Suspicious bugs found!\n\n");
    }
   // system("pause");
    return 0;
}
