#include"iostream"
#include"algorithm"
using namespace std;
__int64 num[10001];
int main(){
    __int64 N,sum=0;
    scanf("%I64d",&N);
    for(int i=0;i<N;i++){
       scanf("%d",&num[i]);
    }
    sort(num,num+N);
    for(__int64 i=1;i<N;i++){
       sum+=i*(N-i)*(num[i]-num[i-1]);
    }
    printf("%I64d\n",sum*2);
   // system("pause");
    return 0;
}
