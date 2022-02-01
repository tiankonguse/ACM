#include"iostream"
using namespace std;
int main(){
    int T,N,tr=0;
    scanf("%d",&T);
    while(T--){
       tr=0;
       scanf("%d",&N);
       while(N){
          tr+=N/5;
          N/=5;
       }
       printf("%d\n",tr);
    }
    return 0;
}
