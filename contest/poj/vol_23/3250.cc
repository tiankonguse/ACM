#include"iostream"
#define inf 0x3f3f3f3f
using namespace std;
int st[80005];
int main(){
    int N,a,p=0;
    __int64 r=0;
    st[0]=inf;
    scanf("%d",&N);
    while(N--){
       scanf("%d",&a);
       while(a>=st[p]){
            p--;
       }
       r+=p;
       st[++p]=a;
    }
    printf("%I64d\n",r);
   // system("pause");
    return 0;
}
