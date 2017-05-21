#include"iostream"
#define MAXN 100001
#define inf 0x7FFFFFFFFFFFFFFFLL
using namespace std;
__int64 a[MAXN];
__int64 dp[MAXN];
int lis(int p){
    int len=0,low,high,mid;
    dp[0]=-inf;
    for(int i=0;i<p;i++){
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
    int N,low,high,mid,len;
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++)scanf("%I64d",&a[i]);
        printf("%d\n",lis(N));
    }
    return 0;
}
