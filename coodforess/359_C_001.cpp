#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 110000
#define eps 1e-7
using namespace std;
typedef long long LL;

LL a[maxn];

LL quickpow(LL m,LL n,LL k) {
    LL b=1;
    while(n>0) {
        if(n&1) b=(b%k*m%k)%k;
        n=n>>1;
        m=(m%k*m%k)%k;
    }
    return b;
} //m^n%k

int main(){
    int i,j,k;
    int n;
    LL x;
    while(cin>>n>>x){
        LL tmp = 0;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            tmp += a[i];
        }
        for(i=1;i<=n;i++){
            a[i] = tmp - a[i];
        }
        sort(a+1,a+1+n);
        LL ans = a[1];


        int pos = 1;
        int cnt = 0;

        while(1){
            for(i=pos;i<=n;i++){
                if(a[i]==ans)cnt++;
                else{
                    pos=i;
                    break;
                }
            }
            if(cnt%x==0){
                ans++;
                cnt=cnt/x;
            }else{
                break;
            }
        }
        ans=min(ans,tmp);
        LL mod = 1000000007;



        ans = quickpow(x,ans,mod);
        printf("%lld\n",ans);
    }
    return 0;
}
//582926302
//246336683
//8 3
//5 5 5 5 5 5 5 4
//8 3
//5 5 5 5 5 5 5 4


//7 3
//5 5 5 5 5 5 4
//391960236



