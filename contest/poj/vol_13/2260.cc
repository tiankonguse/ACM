#include"iostream"
#include"cstdlib"
using namespace std;
int in[101],jn[101];
int main(){
    int N,a,ci,cj,pi,pj;
    while(scanf("%d",&N)&&N){
        ci=cj=0;
        memset(in,0,sizeof(in));
        memset(jn,0,sizeof(jn));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
               scanf("%d",&a);
               in[i]+=a;
               jn[j]+=a;
            }
        }
        for(int i=1;i<=N;i++){
           if(in[i]&1){
              ci++;
              pi=i;
           }
           if(jn[i]&1){
              cj++;
              pj=i;
           }
        }
        if(ci==0 && cj==0)printf("OK\n");
        else if(ci==1 && cj==1)printf("Change bit (%d,%d)\n",pi,pj);
        else printf("Corrupt\n");
    }
    return 0;
}
