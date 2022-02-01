/*************************************************************************
    > File Name: b.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 300010;
int m,n;
LL r;
double _x[N];
double _c[N];
int x[N];
int c[N];

int main() {
    int pos;
    LL tmp;
    LL ans = 0;
    int h = 10;
    while(~scanf("%d%d%lld",&m,&n,&r)) {
        r = r * h;
        r = r*r;

        for(int i=0; i<m; i++) {
            scanf("%lf",&_c[i]);
            _c[i] = _c[i] * h;
            c[i] = (int)(_c[i]);
        }
//        for(int i=0; i<m; i++) {
//            printf("%.1f %d\n",_c[i],c[i]);
//        }

        for(int i=0; i<n; i++) {
            scanf("%lf",&_x[i]);
            _x[i] = _x[i] * 10;
            x[i] = (int)(_x[i]);
        }
//        for(int i=0; i<n; i++) {
//            printf("%.1f %d\n",_x[i],x[i]);
//
//        }
        ans = 0;

        pos = 0;
        for(int i=1; i<n;) {
            tmp = c[pos] - x[i];
            if(tmp < 0 ){
                tmp = -tmp;
            }
//            printf("%d %d\n",tmp * tmp+h,r);
            if(tmp < 1000 &&  tmp * tmp +h*h <= r) {
                i++;
            } else {
                if(c[pos] < x[i]) {
                    ans += c[pos+1] - c[pos];
                    pos++;
                } else {
                    ans += c[pos] - c[pos-1];
                    pos--;
                }
            }
//            getchar();
        }

        printf("%lld.%lld\n",ans/10,ans%10);

    }
    return 0;
}
