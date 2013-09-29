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
typedef long long  ll;
const int N=80010;
const int M=80010;
bool is[N];
ll prm[M];
int num;
ll twoAdd[N];
ll twoMul[N];
ll ans[N];

const int MOD = 1000000007;
int getprm() {
    int e = (int)(sqrt(0.0 + N) + 1),k=0,i;
    memset(is, 1, sizeof(is));
    prm[k++] = 2;
    is[0] = is[1] = 0;
    for (i = 4; i < N; i += 2) is[i] = 0;
    for(i=3; i<e; i+=2) {
        if(is[i]) {
            prm[k++]=i;
            for(int s=i+i,j=i*i; j<N; j+=s)is[j]=0;
        }
    }
    for (; i < N; i += 2)
        if (is[i])prm[k++] = i;
    return k;
}

void init() {
    memset(twoAdd,0,sizeof(twoAdd));
    memset(twoMul,0,sizeof(twoMul));
    memset(ans,-1,sizeof(ans));

    num = getprm();
    int tmp;
    for(int i=0; i<num; i++) {
        for(int j=i; j<num; j++) {
            tmp = prm[i] + prm[j];
            if(tmp >= 80001) {
                break;
            }
            if(tmp < 80001) {
                twoAdd[tmp] = (twoAdd[tmp] + 1) % MOD;

            }
            tmp = prm[i] * prm[j];

            if(tmp < 80001) {
                twoMul[tmp] = (twoMul[tmp] + 1) % MOD;
            }
        }

    }

}

int main() {
    init();
    int p,l,j,i,p1,p2;
    ll tmp1,tmp2;
    while(~scanf("%d",&p)) {
        if(ans[p] == -1) {
            ans[p] = is[p] + twoAdd[p] + twoMul[p];
            p1 = p/2;
            for(i=0; i<num; i++) {
                if(prm[i] >= p1) {
                    break;
                }
                for(j=i; j<num; j++) {
                    if(prm[i] >= p1) {
                        break;
                    }
                    tmp1 = prm[i] + prm[j];
                    tmp2 = p - tmp1;
                    if(tmp2 >1 && is[tmp2]) {

                        if(tmp2 <= prm[i]) {
//                            printf("%d\n",1);
                            ans[p]++;
                        }
                    }


                    tmp1 = prm[i] * prm[j];

                    if(tmp1 < 80001 && p%tmp1 == 0) {

                        tmp2 = p/tmp1;
                        if(is[tmp2]) {
                            if(tmp2 <= prm[i]) {
//                                printf("%d\n",2);
                                ans[p]++;
                            }
                        }
                    }

                    tmp2 = p - tmp1;
                    if(tmp2 > 1 && is[tmp2]) {
//                        printf("%d\n",3);
                        ans[p]++;
                    }
                    ans[p] = ans[p]  % MOD;

                }
            }
        }
        printf("%lld\n",ans[p]);
    }

    return 0;
}
