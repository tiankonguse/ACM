
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

int str[max5];
bool solver(int n, vector<int>& ans) {
  unordered_map<int, int> m;
  for (int i = 1; i <= n; i++) {
    m[str[i]] = i;
  }

  unordered_set<int> op;
  for (int i = n; i > 1; i--) {
    while (str[i] != i) {
      const int pos = m[i];
      if (op.count(pos)) return false;  //已经操作过了

      // swap(pos, pos+1)
      const int nextVal = str[pos + 1];
      swap(str[pos], str[pos + 1]);
      m[i] = pos + 1;
      m[nextVal] = pos;
      op.insert(pos);
      ans.push_back(pos);
    }
  }

  return op.size() == n - 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &str[i]);
    }
    vector<int> ans;
    if (solver(n, ans)) {
      for (auto v : ans) {
        printf("%d\n", v);
      }
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
