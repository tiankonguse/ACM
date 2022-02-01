#include<cstdio>
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif


int main(int argc, char* argv[]) {

    LL n,m,v,k,ans,t;
    scanf("%I64d",&t);
    while(t--) {
        scanf("%I64d%I64d%I64d%I64d",&n,&m,&v,&k);
        ans = 0;
        if(n <= m) {
            ans = 0;
        } else if(m <= v || k <= 1) {
            ans = -1;
        } else if((m-v)*k > m){
        	ans  = 0;
        	while(m < n){
				ans++;
				m = (m-v)*k;
        	}
        }else{
			ans = -1;
        }
        printf("%I64d\n",ans);

    }
    return 0;
}






