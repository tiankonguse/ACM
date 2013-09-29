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
int prm[M];
int num;
ll twoAdd[N];
vector<ll> _twoAdd[N];
ll twoMul[N];
ll _twoMul[N];
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
                _twoAdd[tmp].push_back(prm[i]);

            }
            tmp = prm[i] * prm[j];

            if(tmp < 80001) {
                twoMul[tmp] = (twoMul[tmp] + 1) % MOD;
                _twoMul[tmp] = prm[i];
            }
        }

    }

}

int main() {
    init();
    int p,tmp,l,j;
    while(~scanf("%d",&p)) {
        if(ans[p] == -1) {
            ans[p] = is[p] + twoAdd[p] + twoMul[p];

            int tmp1,tmp2;
            for(int i=0; i<num; i++) {
                if(prm[i] > p) {
                    continue;
                }
                tmp = p - prm[i];
                l = _twoAdd[tmp].size();
                if(l) {
                    for(j=0; j<l; j++) {
                        if(prm[i] <= _twoAdd[tmp][j]) {
                            ans[p] ++;
                        }
                    }
                }
                if(twoMul[tmp]) {
                    ans[p]++;
                }

                if(p%prm[i] == 0) {
                    tmp = p / prm[i];
                    if(twoMul[tmp]) {
                        if(prm[i] <= _twoMul[tmp]) {
                            ans[p]++;
                        }
                    }

                }
                ans[p] = ans[p]  % MOD;
            }
        }
        printf("%lld\n",ans[p]);
    }

    return 0;
}
