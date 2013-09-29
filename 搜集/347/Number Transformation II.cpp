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
    using namespace std;
    typedef long long  LL;

    const int N = 1000010;
    int str[N];
    int a,b,n;


    int solve() {
        int ans = 0,_a,tmp,i;
        while(a != b) {
            ans++;
            _a = a-1;
            for(i=n-1; i>=0; i--) {
                tmp = a - a % str[i];
                if(tmp >= b && tmp < _a) {
                    _a = tmp;
                }
            }
            a = _a;
            for(; n>0 && (a - a%str[n-1] == 0) ; n--);
        }
        return ans;
    }

    int main() {
        while(~scanf("%d",&n)) {
            for(int i=0; i<n; i++) {
                scanf("%d",&str[i]);
            }
            scanf("%d%d",&a,&b);
//            printf("%d\n",n);
            n = unique(str,str+n) - str;
//            printf("%d\n",n);
            sort(str,str+n);

            printf("%d\n",solve());
        }


        return 0;
    }
