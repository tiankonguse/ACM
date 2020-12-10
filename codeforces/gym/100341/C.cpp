#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int N = 65536 * 2;
const int Mod = 786433;

const int p=786433,g=10;
ll pm(ll a,int n,int m=p) {
    ll r=1;
    for(;n;n>>=1,a=a*a%p)
    if(n&1) r = r * a %p;
    return r;
}
int rb(int x,int m) {
    int r=0;
    for(;m>1;m>>=1,x>>=1)r=r<<1|x&1;
    return r;
}
void ntt(int *a,int len){
    for(int i=0,j;i<len;++i)
    if(i<(j=rb(i,len)))swap(a[i],a[j]);
    for(int m=1; m < len ; m<<=1) {
        ll w=1;int w0 = pm(g, (p-1)/m>>1);
        for(int k = 0; k<len; k+=(m<<1), w=1)
        for(int j=0;j<m; ++j , w=w*w0 %p) {
            int t= w*a[k+j+m]%p;
            a[k+j+m] = (a[k+j]+p-t) %p;
            a[k+j] = (a[k+j]+t)%p;
        }
    }
}

void conv(int *a, int *b, int *c, int len) {
    static int wa[N], wb[N];
    rep (i, len) wa[i] = a[i], wb[i] = b[i];
    ntt(wa, len);
    ntt(wb, len);
    int inv = pm(len, p - 2);
    rep (i, len) c[i] = wa[i] * (ll)wb[i] % p * inv % p;
    reverse(c + 1, c + len);
    ntt(c, len);
}

int maxIdx(int *a) {
    for (int i = N + 2; i >= 0; i--)
        if (a[i]) {
            return i;
        }
    return 0;
}

void add(int &t, int x) {
    t += x;
    if (t >= Mod) t -= Mod;
}

void FFT(int *a, int *b, int *c) {
    int maxidx = max(maxIdx(a), maxIdx(b));
    int len = 1, inv;
    while (len <= maxidx) len <<= 1;
    len *= 2;
    static int wc[N + 5];
    conv(a, b, wc, len);
    rep (i, len) add(c[i], (ll)(wc[i]) * 2 % Mod);
    conv(a, a, wc, len);
    rep (i, len) add(c[i], (ll)(wc[i]) % Mod);
}

int n, h;
int f[18][N + 5];

int main() {
    freopen("avl.in", "r", stdin);
    freopen("avl.out", "w", stdout);
    cin >> n >> h;
    if (h == 0) {
        puts(n == 1 ? "1" : "0");
    } else {
        h++;
        f[0][0] = 1;
        f[1][1] = 1;
        for (int i = 2; i <= h; i++) {
            FFT(f[i - 1], f[i - 2], f[i]);
//          for (int j = 1; j <= n; j++) printf("%d ", f[i][j]); puts("");
            for (int j = n; j >= 1; j--) f[i][j] = f[i][j - 1];
            for (int j = n + 1; j < N + 5; j++) f[i][j] = 0;
        }
        cout << f[h][n] << "\n";
    }
}