#include"iostream"
#include"cmath"
#include"algorithm"
#define MAXN 100005
using namespace std;
int N,a[MAXN];
double K;
bool check(int m){
    int cnt=0;
    for(int i=0;i<N;i++){
        if(a[i]>m){
            cnt+=ceil(1.0*(a[i]-m)/(K-1));
            if(cnt>m)return false;
        }
    }
    return true;
}
int main(){
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++){
            scanf("%d",&a[i]);
        }
        scanf("%lf",&K);
        sort(a,a+N);
        if(K==1)printf("%d\n",a[N-1]);
        else{
            int l=1,h=a[N-1],mid;
            while(l<=h){
                mid=(l+h)>>1;
                if(check(mid))h=mid-1;
                else l=mid+1;
            }
            printf("%d\n",l);
        }
    }
   // system("pause");
    return 0;
}
