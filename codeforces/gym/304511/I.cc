
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
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

vector<pair<ll, ll>> vec;
unordered_set<ll> s;

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    ll x, y;
    scanf("%lld%lld", &x, &y);
    vec.push_back({x, y});
  }
  sort(vec.begin(), vec.end(),
       [](auto& a, auto& b) { return a.second > b.second; });

  ll ans = 0;
  s.insert(0);
  for (auto& p : vec) {
    if (s.count(p.first)) {
      continue;
    }
    ans += p.second;

    unordered_set<ll> newData;
    for (auto v : s) {
      newData.insert(v ^ p.first);
    }
    s.insert(newData.begin(), newData.end());
  }
  printf("%lld\n", ans);

  return 0;
}