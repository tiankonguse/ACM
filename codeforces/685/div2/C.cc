
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

char a[max6];
char b[max6];
int n, k;

bool check() {
  int ma[256], mb[256];
  memset(ma, 0, sizeof(ma));
  memset(mb, 0, sizeof(mb));
  for (int i = 0; i < n; i++) {
    ma[a[i]]++;
    mb[b[i]]++;
  }

  for (int i = 'a'; i <= 'z'; i++) {
    if (ma[i] == mb[i]) {
      continue;
    }
    if (ma[i] < mb[i]) {
      return false;
    }

    int left = ma[i] - mb[i];
    if (left % k != 0) {
      return false;
    }
    ma[i + 1] += left;
  }

  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    scanf("%s%s", a, b);
    printf("%s\n", check() ? "Yes" : "No");
  }
  return 0;
}