#include"iostream"
#include"cstdlib"
using namespace std;
int dice[1001],pnow[11];
int cl[101];
bool lt[101],et[101],go[11];
void init(){
     memset(cl,0,sizeof(cl));
     memset(lt,0,sizeof(lt));
     memset(et,0,sizeof(et));
     memset(pnow,0,sizeof(pnow));
     memset(go,true,sizeof(go));
}
int main(){
    int N=0,M,a,b,p,pos;
    while(scanf("%d",&a)&&a){
        dice[N++]=a;
    }
    while(scanf("%d",&M)&&M){
       init();
       while(scanf("%d%d",&a,&b)){
          if(a==0 && b==0)break;
          cl[a]=b;
       }
       while(scanf("%d",&a)&&a){
          if(a<0)lt[-a]=true;
          else et[a]=true;
       }
       //solve
       p=pos=0;
       while(1){
          if(!go[p])go[p]=true;
          else if(pnow[p]+dice[pos]<=100){
             pnow[p]+=dice[pos++];
             if(pnow[p]==100)break;
             if(cl[pnow[p]])pnow[p]=cl[pnow[p]];
             if(lt[pnow[p]])go[p]=false;
             else if(et[pnow[p]])continue;
          }
          p=(p+1)%M;
       }
       printf("%d\n",p+1);
    }
    return 0;
}
