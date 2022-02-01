#include"iostream"
using namespace std;
int main(){
    int x[100001],y[100001];
    int N,M,h=0,v=0,xt,yt;
    while(cin>>N){
        if(N==0)break;
        M=N/2;
        int c1=0,c2=0;
        for(int i=0;i<N;i++){
                if(i>M){
                         scanf("%d%d",&xt,&yt);
                           if(xt>v){
                           if(yt>h)c1++;
                           else if(yt<h)c2++;
                            }
                            else if(xt<v){
                                       if(yt>h)c2++;
                                       else if(yt<h)c1++;
                            }
                }
                else{
                scanf("%d%d",&x[i],&y[i]);
                if(i==M){
                         v=x[i];
                         h=y[i];
                }
                }
        }
        for(int i=0;i<M;i++){
                if(x[i]>v){
                           if(y[i]>h)c1++;
                           else if(y[i]<h)c2++;
                }
                else if(x[i]<v){
                           if(y[i]>h)c2++;
                           else if(y[i]<h)c1++;
                }
        }
        cout<<c1<<" "<<c2<<endl;
    }
    
    return 0;
}
