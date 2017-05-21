#include"iostream"
#include"algorithm"
using namespace std;
double a[1001];
int find(double x,int N){
   int low=0,high=N-1,mid;
   while(low<=high){
      mid=(low+high)>>1;
      if(a[mid]>x)high=mid-1;
      else low=mid+1;
   }
   return low;
}
int main(){
    int T,N,pos,r;
    double d;
    scanf("%d",&T);
    while(T--){
       scanf("%d",&N);
       d=0;
       for(int i=0;i<N;i++){
          scanf("%lf",&a[i]);
          d+=a[i];
       }
       d/=N;
       sort(a,a+N);
       r=N-find(d,N);
       printf("%.3lf%%\n",100*(double)r/N);
    }
   //system("pause");
    return 0;
}
