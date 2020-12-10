#define N 10000005
int m , n;
bool f[N];
int prime[N] , tot;
int mu[N] , h[N] , sum[N];
void init()
{
    n = 10000000;
    int i , j , x;
    mu[1] = 1;
    for (i = 2 ; i <= n ; ++ i)
    {
        if (!f[i]) {
            prime[tot ++] = i ;
            //phi[i] = i - 1 ;
            h[i] = 1;
            mu[i] = -1;
        }
        for (j = 0 ; j < tot ; ++ j)
        {
            x = i * prime[j];
            if (x > n) break;
            f[x] = 1 ;
            if (i % prime[j] == 0) { // x isn't the square free number.
                //phi[x] = phi[i] * prime[j]; // ... i % prime[j] == 0 => x % (prime[j] ^ 2) => 0
                mu[x] = 0;
                h[x] = mu[i];
                break;
            }
            else { // x is updated by another prime.
                //phi[x] = phi[i] * (prime[j] - 1) ;
                mu[x] = -mu[i];
                h[x] = mu[i] - h[i];
            }
        }
    }
    for (i = 1 ; i <= n ; ++ i)
        sum[i] = sum[i - 1] + h[i];
}
// sum of 1 <= x <= n , 1 <= y <= m , gcd(x , y) == 1;
// O(sqrt(n) + sqrt(m))
LL solve(int n , int m)
{
    LL ans = 0;
    if (n > m) swap(n , m);
    for (int i = 1 , x ; i <= n ; i = x + 1) {
        x = min(n / (n / i) , m / (m / i));
        ans += (LL) (sum[x] - sum[i - 1]) * (n / i) * (m / i);
    }
    return ans;
}

void work()
{
    scanf("%d%d",&n,&m);
    printf("%lld\n" , solve(n , m));
}
