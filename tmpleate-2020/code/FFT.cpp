//g是p的原根。需要保证p为素数且p = k * 2^len + 1(k为正整数)
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

//实数版本
void FFT(complex <REAL> *a, int len, int inv) { //eps = 1e-12
    for (int i=0, n1=0, n2=0; i < len; ++i, n2 ^= (len/(i&-i)>>1), n1^=(i&-i))
        if (n1 > n2)
            swap(a[n1], a[n2]);
    for (int m = 1; m <= len >> 1; m <<= 1) {
        complex <REAL> w0(cos(PI / m), sin(PI / (inv * m))), w = 1, t;
        for (int k = 0; k < len; k += (m << 1), w = 1)
            for (int j = 0; j < m; ++j, w *= w0) {
                t = w * a[k + j + m];
                a[k + j + m] = a[k + j] - t;
                a[k + j] += t;
            }
    }
    if (inv == -1)
        for (int i = 0; i < len; ++i)
            a[i] /= len;
}