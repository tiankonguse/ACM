#include"iostream"
#define Min(a,b) (a<b?a:b)
using namespace std;
__int64 a[100000]={1};
int main(){
    __int64 p1,p2,p3,n;
    int c1=0,c2=0,c3=0;
    scanf("%I64d%I64d%I64d%I64d",&p1,&p2,&p3,&n);
    for(int i=1;i<=n;i++){
        a[i]=Min(a[c1]*p1,Min(a[c2]*p2,a[c3]*p3));
        if(a[i]==a[c1]*p1)c1++;
        if(a[i]==a[c2]*p2)c2++;
        if(a[i]==a[c3]*p3)c3++;
    }
    printf("%I64d\n",a[n]);
    //system("pause");
    return 0;
}
