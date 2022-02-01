#include"iostream"
using namespace std;
int main(){
    int N,t,a;
    while(~scanf("%d",&N)){
       t=0;
       while(N--){
          scanf("%d",&a);
          t^=a;
       }
       if(t)printf("Yes\n");
       else printf("No\n");
    }
    return 0;
}
