
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

ll str[max5];
ll sum[max5];
std::set<ll> s;

void dfs(int l, int r) {
  if(l > r){
    return;
  }
  s.insert(sum[r] - sum[l - 1]);
  if (str[l] == str[r]) {
    return;
  }

  ll val = (str[r] + str[l]) / 2;
  ll* pmid = std::upper_bound(str + l, str + r + 1, val);
  int mid = pmid - str;
  // printf("l=%d r=%d mid=%d val=%lld\n", l, r, mid, val);
  dfs(l, mid - 1);
  dfs(mid, r);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &str[i]);
    }

    s.clear();
    sort(str + 1, str + 1 + n);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      // printf("i=%d val=%lld\n", i, str[i]);
      sum[i] = sum[i - 1] + str[i];
    }
    dfs(1, n);
    while (q--) {
      ll p;
      scanf("%lld", &p);
      printf("%s\n", s.count(p) > 0 ? "Yes" : "No");
    }
  }
  return 0;
}