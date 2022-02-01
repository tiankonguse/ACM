#include"iostream"
using namespace std;
int main(){
    int T,N,a,ans,tmp;
    bool state;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        if(N){
            scanf("%d",&tmp);
            ans=1;
            state=false; //false:up, true:down
            for(int i=0;i<N-1;i++){
                scanf("%d",&a);
                if(!state){
                    if(a<tmp){ans++;state=true;}
                    tmp=a;
                }
                else{
                    if(a>tmp){ans++;state=false;}
                    tmp=a;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
