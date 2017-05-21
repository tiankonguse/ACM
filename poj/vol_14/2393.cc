#include"iostream"
using namespace std;
int main(){
    __int64 N,S,a,b,pa,pb,res=0;
    scanf("%I64d%I64d",&N,&S);
    if(N--)scanf("%I64d%I64d",&pa,&pb);
    res+=pa*pb;
    while(N--){
       scanf("%I64d%I64d",&a,&b);
       if(a>pa+S)a=pa+S;
       res+=a*b;
       pa=a;
       pb=b;
    }
    printf("%I64d\n",res);
 //   system("pause");
    return 0;
}
