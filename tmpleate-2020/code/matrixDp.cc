
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

/*
矩阵类：相乘 与 幂
*/

const int N = 12;
const int MOD = 1000000007;
struct Matrix {
  ll a[N][N];
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

int main() {
  ll k = 2;

  // f(n) = f(n-1) + f(n-2) + ... + f(n-k)
  Matrix left;
  left.init(k, k);
  for (int i = 0; i < k - 1; i++) {
    left.a[i][i + 1] = 1;
  }
  for (int i = 0; i < k; i++) {
    left.a[k - 1][i] = 1;
  }

  Matrix right;
  right.init(k, 1);
  for (int i = 0; i < k; i++) {
    right.a[i][0] = 1;
    printf("i=%d v=%d\n", i + 1, 1);
  }
  for (int i = 3; i < 10; i++) {
    Matrix tmp = left.pow(i - k);
    Matrix ans = tmp * right;
    printf("i=%d v=%lld\n", i, ans.a[k - 1][0]);
  }

  return 0;
}