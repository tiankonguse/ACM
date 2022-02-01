#include"iostream"
#include"cmath"
using namespace std;
__int64 N,i,a[32001],s[32001];
int bs(int n,__int64 a[]){
      int low=1,high=31267,mid;
      while(low<=high){
        mid=(low+high)/2;
        if(n>a[mid])low=mid+1;
        else high=mid-1;
      }
      return low;
}
int main(){
    for(i=1;i<=32000;i++){
         if(i<10)a[i]=a[i-1]+1;
         else if(i<100)a[i]=a[i-1]+2;
         else if(i<1000)a[i]=a[i-1]+3;
         else if(i<10000)a[i]=a[i-1]+4;
         else if(i<100000)a[i]=a[i-1]+5;
         s[i]=s[i-1]+a[i];
         if(s[i]>=2147483647)break;
    } 
    scanf("%d",&N);
   // for(i=1;i<=10;i++)cout<<s[i]<<endl;
   // cout<<endl;
    while(N--){
        scanf("%d",&i);
   //   cout<<a[i]<<endl<<s[i]<<endl<<endl;
   int t1=bs(i,s);
   int t2=i-s[t1-1];
   int t3=bs(t2,a);
   int t4=t2-a[t3-1];
  /*  cout<<t1<<endl;
    cout<<t2<<endl;
    cout<<t3<<endl;
    cout<<t4<<endl;*/
    int len=(int)log10((double)t3)+1;
    for(int j=0;j<len-t4;j++){
       t3/=10;
    }
    cout<<t3%10<<endl;        
     }
    return 0;
}
