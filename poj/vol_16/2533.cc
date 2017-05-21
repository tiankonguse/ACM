#include"iostream"
using namespace std;
int a[1001],dp[1001];
int fun(int N){
   int len=0,low,high,mid;
   dp[0]=0;
   for(int i=0;i<N;i++){
      low=1,high=len;
      while(low<=high){
         mid=(low+high)/2;
         if(a[i]>dp[mid])low=mid+1;
         else high=mid-1;
      }
      dp[low]=a[i];
      if(low>len)len++;
   }
   return len;
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d",&a[i]);
    }
    printf("%d\n",fun(N));
    return 0;
}
