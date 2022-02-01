
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
const int max3 = 2100, max4 = 21100, max5 = 200100, max6 = 2000100;

int str[max5];

unordered_set<int> s;
map<int, int> m;

int main() {
  int t, n, v;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    s.clear();
    m.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &v);
      if (s.count(v)) continue;
      if (m.count(v)) {
        s.insert(v);
        m.erase(v);
      } else {
        m[v] = i;
      }
    }
    if (m.size() == 0) {
      printf("-1\n");
    } else {
      auto it = m.begin();
      printf("%d\n", it->second);
    }
  }
  return 0;
}