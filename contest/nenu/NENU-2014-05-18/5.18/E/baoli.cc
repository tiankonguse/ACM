#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(!b) return a;
    return gcd(b,a%b);
}
int main(){
    int t;
    freopen("JACK AND JOHN.in","r",stdin);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        ll n,a,b;
        ll ans=0;
        scanf("%lld %lld %lld",&n,&a,&b);
        for(ll i=a;i<=b;i++) if(gcd(n,i)==1) ans++;
        printf("%d %lld\n",cas,ans);
    }
}
