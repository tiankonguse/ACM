#include"iostream"
using namespace std;
int main(){
    int T,a,b,ra,rb;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d",&a,&b);
       ra=(a+b)/2;
       rb=(a-b)/2;
       if(ra<0 || rb<0 || ra+rb!=a || ra-rb!=b)printf("impossible\n");
       else printf("%d %d\n",ra,rb);
    }
    return 0;
}
