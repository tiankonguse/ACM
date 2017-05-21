#include"iostream"
using namespace std;
int fu[1001];
int main(){
    int T,a,b,c,d,e,f,g,h,k;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&k);
       fu[0]=a;
       fu[1]=b;
       fu[2]=c;
       for(int i=3;i<=k;i++){
           if(i&1){
              fu[i]=((d*fu[i-1]+e*fu[i-2]-f*fu[i-3])%g+g)%g;
           }
           else{
              fu[i]=((f*fu[i-1]-d*fu[i-2]+e*fu[i-3])%h+h)%h;
           }
       }
       printf("%d\n",fu[k]);
    }
    //system("pause");
    return 0;
}
