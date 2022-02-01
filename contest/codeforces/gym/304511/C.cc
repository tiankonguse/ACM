
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

const int mod1 = 100000;

ll nums1[max5];
ll nums2[max5];

vector<vector<int>> edges;

bool flag[max5];
ll sum1, sum2;

void dfs(int now, int pre) {
  if (flag[now]) return;
  flag[now] = true;
  sum1 += nums1[now];
  sum2 += nums2[now];
  for (auto v : edges[now]) {
    if (v == pre) {
      continue;
    }
    dfs(v, now);
  }
}

bool check(int n, int now) {
  sum1 = 0;
  sum2 = 0;

  dfs(now, -1);
//   printf("sum1=%lld sum2=%lld\n", sum1, sum2);
  return sum1 == sum2;
}

bool check(int n) {
  memset(flag, false, sizeof(flag));
  for (int i = 0; i < n; i++) {
    if (flag[i]) {
      continue;
    }
    if (!check(n, i)) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, m;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &nums1[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &nums2[i]);
  }
  edges.resize(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  printf("%s\n", check(n) ? "yingyingying" : "azhe");

  return 0;
}