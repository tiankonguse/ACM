#include"iostream"
#include"algorithm"
using namespace std;
__int64 a[250001];
int main(){
    int N;
    __int64 sum;
    while(~scanf("%d",&N)){
    for(int i=0;i<N;i++)scanf("%I64d",a+i);
    sort(a,a+N);
    if(N&1)printf("%I64d.0\n",a[N/2]);
    else{
       //  printf("%.1lf\n",a[N/2-1]/2.0+a[N/2]/2.0);
        sum=a[N/2-1]+a[N/2];
        if(sum&1)printf("%I64d.5\n",sum/2);
        else printf("%I64d.0\n",sum/2);
    }
    }
   // system("pause");
    return 0;
}
