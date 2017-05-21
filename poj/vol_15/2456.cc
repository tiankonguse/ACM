#include"iostream"
#include"algorithm"
#define MAXN 100005
using namespace std;
int N,C,a[MAXN];
bool check(int m){
    int t=a[0],cnt=1;
    for(int i=1;i<N;i++){
        if(a[i]-t>=m){
            t=a[i];
            cnt++;
            if(cnt==C)return true;
        }
    }
    return false;
}
int main(){
    int l,r,mid;
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+N);
    l=0,r=a[N-1]-a[0];
    if(C==1)printf("%d\n",r);
    else{
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        printf("%d\n",l-1);
    }
   // system("pause");
    return 0;
}
