#include"iostream"
using namespace std;
int a[40001],dp[40001]={0};
int lds(int p){
    int len=0,low,high,mid;
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
    int N,p;
    scanf("%d",&N);
    while(N--){
       scanf("%d",&p);
       for(int i=0;i<p;i++){
           scanf("%d",&a[i]);
       }
       printf("%d\n",lds(p));       
    }
    //system("pause");
    return 0;
}
