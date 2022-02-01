#include"iostream"
#include"algorithm"
#define MAXN 10001
using namespace std;
__int64 a[MAXN];
__int64 M;
int N;
int cmp(__int64 a,__int64 b){
    return a>b;
}
bool check(__int64 len){
   int sum=0;
   for(int i=0;i<N;i++){
       sum+=a[i]/len;
       if(sum>=M)return true;
   }
   return false;
}
__int64 binary(){
   __int64 low=1,high=10000000,mid;
   bool flag=false;
   while(low<=high){
       mid=(low+high)/2;
       if(flag=check(mid))low=mid+1;
       else high=mid-1;
   //   cout<<flag<<":"<<mid<<endl;
   }
   return low-1;
}
int main(){
    __int64 tmp1,tmp2,res;
    scanf("%d%I64d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%I64d.%I64d",&tmp1,&tmp2);
        a[i]=tmp1*100+tmp2;
    }
    sort(a,a+N,cmp);
    res=binary();
    tmp1=res%10;
    res/=10;
    tmp2=res%10; 
    res/=10;
    printf("%I64d.%I64d%I64d\n",res,tmp2,tmp1);
   // for(int i=0;i<N;i++)cout<<a[i]<<endl;
   // system("pause");
    return 0;
}
