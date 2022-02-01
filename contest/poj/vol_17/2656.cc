#include"iostream"
using namespace std;
int main(){
    int N,a,b;
    bool flag;
    while(scanf("%d",&N)&&N){
       flag=false;
       for(int i=1;i<=N;i++){
          scanf("%d%d",&a,&b);
          if(!flag && a+b>8){
             flag=true;
             printf("%d\n",i);
          }
       }
       if(!flag)printf("%d\n",0);
    }
    return 0;
}
