#include"iostream"
#include"cmath"
#include"algorithm"
using namespace std;
int cmp(double a,double b){
    return a>b;
}
double a[10001];
double eps=1e-6;
double pi=acos(-1.0);
int main(){
    int T,N,F,cnt;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&F);
        F++;
        for(int i=0;i<N;i++){
           scanf("%lf",&a[i]);
           a[i]*=a[i];
        }
        sort(a,a+N,cmp);
        double low=0,high=a[0],mid; 
        while(high-low>eps){
             mid=(high+low)/2.0;
             cnt=0;
             for(int i=0;i<N;i++){
                 cnt+=(int)(a[i]/mid);
             }
             if(cnt>=F)low=mid;
             else high=mid;
        }
        printf("%.4lf\n",low*pi);
    }
    return 0;
}
