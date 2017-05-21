#include"iostream"
#include"cmath"
#include"algorithm"
#define MAXN 100005
using namespace std;
int N,a[MAXN];
__int64 K,M,mm;
bool check(int m){
    mm=M*m;
    __int64 cnt=0,max_cnt=0;
    for(int i=0;i<N;i++){
        if(a[i]-m>0){
            cnt=(a[i]-m)/(K-1);
            if((a[i]-m)%(K-1))cnt++;
            if(cnt>m)return false;
            max_cnt+=cnt;
            if(max_cnt>mm)return false;
        }
    }
    return true;
}
int main(){
    int T,l,h,mid;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d%d",&M,&K);
        sort(a,a+N);
        if(K==1)printf("%d\n",a[N-1]);
        else{
            l=1,h=a[N-1];
            while(l<=h){
                mid=(l+h)>>1;
                if(check(mid))h=mid-1;
                else l=mid+1;
            }
            printf("%d\n",l);
        }
    }
//    system("pause");
    return 0;
}
