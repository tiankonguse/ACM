const int maxn = 5000005;
const int mod = 1e9 + 7;
const int base = 31;
char s[maxn];
int mi[maxn];

struct BIT {
  int v[maxn], len;
  void init(int n) {
    len = n;
    for (int i = 0; i <= n; ++i) v[i] = 0;
  }
  void add(int p, int x) {
    while (p <= len) {
      (v[p] += x) %= mod;
      p += lowbit(p);
    }
  }
  int sum(int p) {
    int ret = 0;
    while (p > 0) {
      (ret += v[p]) %= mod;
      p -= lowbit(p);
    }
    return ret;
  }
} bit;
int n, m;

bool check(int len) {
  int fl = bit.sum(0), fr = bit.sum(len);
  int f = (fr - fl + mod) % mod;
  int sl = bit.sum(n - len), sr = bit.sum(n);
  int s = (sr - sl + mod) % mod;
  f = 1ll * f * mi[n - len] % mod;
  return f == s;
}

int main() {
  scanf("%d%d", &n, &m);
  mi[0] = 1;
  for (int i = 1; i <= 5000000; ++i) mi[i] = 1ll * mi[i - 1] * base % mod;
  scs(s + 1);
  bit.init(n);
  for (int i = 1; i <= n; ++i) {
    int c = s[i] - 'a' + 1;
    int v = 1ll * c * mi[i] % mod;
    bit.add(i, v);
  }
  while (m--) {
    int op, x;
    scanf("%d%d", &op, &x);
    if (op == 1) {
      char c = getchar();
      while (c < 'a' || c > 'z') c = getchar();
      int vminus = 1ll * (s[x] - 'a' + 1) * mi[x] % mod;
      bit.add(x, mod - vminus);
      int vadd = 1ll * (c - 'a' + 1) * mi[x] % mod;
      bit.add(x, vadd);
      s[x] = c;
      continue;
    }
    // op == 2
    x %= n;
    if (x == 0) {
      puts("1");
      continue;
    }
    if (check(n - x) && check(x))
      puts("1");
    else
      puts("0");
  }
  return 0;
}