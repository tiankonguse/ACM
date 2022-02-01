#include"iostream"
using namespace std;
int main(){
    int N,a,b,w,h,wn,hn;
    while(scanf("%d",&N)&&N){
         w=h=wn=hn=0;
         while(scanf("%d%d",&a,&b)){
            if(a==-1 && b==-1)break;
            if(wn+a<=N){
                wn+=a;
                if(wn>w)w=wn;
                if(b>hn)hn=b;
            }
            else{
                wn=a;
                h+=hn;
                hn=0;
                if(wn>w)w=wn;
                if(b>hn)hn=b;
            }
         }
         if(wn>w)w=wn;
         h+=hn;
         printf("%d x %d\n",w,h);
    }    
    return 0;
}
