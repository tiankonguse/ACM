#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll tmp[100],cnt;
int l;
void dfs(int idx,ll now,ll n,ll flag){
    if(now>n) return ;
    cnt+=flag*(n/now);
    for(int i=idx;i<l;i++){
        dfs(i+1,now*tmp[i],n,flag*-1);
    }
}
ll solve(ll a){
    cnt=0;
    dfs(0,1,a,1);
    return cnt;
}
int main(){
//    freopen("JACK AND JOHN.in","r",stdin);
//    freopen("JACK AND JOHN.out","w",stdout);
    ll a,b,n;
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%lld%lld%lld",&n,&a,&b);
        l=0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                tmp[l++]=i;
                while(n%i==0) n/=i;
            }
        }
        if(n>1) tmp[l++]=n;
        printf("%lld\n",solve(b)-solve(a-1));
    }
}
