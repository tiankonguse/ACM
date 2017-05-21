#include"iostream"
#include"cstdlib"
using namespace std;
int parents[100001];
int e[100001];
int find(int a){
    int x=a,tmp;
    while(parents[a]>=0)a=parents[a];
    while(parents[x]>=0 && parents[x]!=a){
       tmp=parents[x];
       parents[x]=a;
       x=tmp;
    }
    return a;
}
int Union(int a,int b){
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
    int T,N,M,a,b,r1,r2,ra,rb;
    char c;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d",&N,&M);
       memset(parents,0xff,(N+1)*sizeof(parents[0]));
       memset(e,0xff,(N+1)*sizeof(e[0]));
       while(M--){
          scanf(" %c %d %d",&c,&a,&b);
          if(c=='A'){
             r1=find(a);
             r2=find(b);
             if(r1==r2)printf("In the same gang.\n");
             else{
                if(r1==find(e[r2]))printf("In different gangs.\n");
                else printf("Not sure yet.\n");
             }
          }
          else{
            ra=find(a);
            rb=find(b);
            if(e[a]!=-1){
               r1=find(e[a]);
               if(r1!=rb)Union(r1,rb);
            }
            else e[a]=rb;
            if(e[b]!=-1){
               r2=find(e[b]);
               if(r2!=ra)Union(r2,ra);
            }
            else e[b]=ra; 
          }
       }
    }
   // system("pause");
    return 0;
}
