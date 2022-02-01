
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// const int mod = 1e9 + 7;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

const int N = 7;
const int MOD = 100;
struct Matrix {
  int a[N][N];
  int n, m;
  Matrix() { memset(a, 0, sizeof(a)); }
  void init(int n_, int m_) { n = n_, m = m_; }
  void _union() {
    for (int i = 0; i < n; i++) {
      a[i][i] = 1;
    }
  }
  Matrix operator*(Matrix& B);
  Matrix pow(ll k);
  void output() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  }
};
Matrix Matrix::operator*(Matrix& B) {
  Matrix ret;
  ret.init(B.n, B.m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < B.m; j++)
      for (int k = 0; k < n; k++) {
        ret.a[i][j] = (ret.a[i][j] + a[i][k] * B.a[k][j]) % MOD;
      }
  return ret;
}
Matrix Matrix::pow(ll k) {
  Matrix ret;
  ret.init(n, m);
  Matrix A = *this;
  ret._union();
  while (k) {
    if (k & 1) ret = ret * A;
    A = A * A;
    k >>= 1;
  }
  return ret;
}

ll S0[max5];
ll S1[max5];
ll S2[max5];

void init() {
  S0[0] = S1[0] = S2[0] = 0;
  S0[1] = S1[1] = S2[1] = 1;

  for (int i = 2; i < 1000; i++) {
    S0[i] = (S0[i - 1] + S0[i - 2]) % MOD;
    S1[i] = (S1[i - 1] + S0[i]) % MOD;
    S2[i] = (S2[i - 1] + S1[i]) % MOD;
  }
}

int main() {
  // #ifndef ONLINE_JUDGE
  //   freopen("in.txt", "r", stdin);
  //   freopen("out.txt", "w", stdout);
  //   // freopen("out_std.txt", "w", stdout);
  // #endif
  // init();

  ll k = 6, n;
  Matrix left;
  left.init(k, k);
  memset(left.a, 0, sizeof(left.a));
  left.a[0][1] = 1;
  left.a[1][0] = left.a[1][1] = 1;
  left.a[2][3] = 1;
  left.a[3][0] = left.a[3][1] = left.a[3][3] = 1;
  left.a[4][5] = 1;
  left.a[5][0] = left.a[5][1] = left.a[5][3] = left.a[5][5] = 1;

  Matrix right;
  right.init(k, 1);
  memset(right.a, 0, sizeof(right.a));
  right.a[1][0] = right.a[3][0] = right.a[5][0] = 1;

  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    if (n == 1) {
      printf("1\n");
      continue;
    }
    // printf("force: %lld\n", S2[n % 900]);
    Matrix ans = left.pow(n - 1) * right;

    printf("%d\n", ans.a[k - 1][0]);
  }

  return 0;
}