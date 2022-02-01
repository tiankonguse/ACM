#include"iostream"
using namespace std;
int main(){
    int T;
    __int64 n,m;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
       scanf("%I64d%I64d",&n,&m);
       printf("Scenario #%d:\n",i);
       printf("%I64d\n\n",(n+m)*(m-n+1)/2);
    }
 //   system("pause");
    return 0;
}
