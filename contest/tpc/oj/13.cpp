#include <bits/stdc++.h>
#include <stdio.h>

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

// lower_bound 大于等于
// upper_bound 大于
// reserve vector预先分配内存
// reverse(v.begin(), v.end()) 反转
// sum = accumulate(a.begin(), a.end(), 0);

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

int main() {
#ifndef ONLINE_JUDGE
  // freopen("./in.txt", "r", stdin);
  // freopen("./out.txt", "w", stdout);
#endif
  int n, v;
  vector<int> vec;
  scanf("%d", &n);
  vec.reserve(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    vec.push_back(v);
  }
  sort(vec.begin(), vec.end());
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &v);
    auto it = upper_bound(vec.begin(), vec.end(), v);
    printf("%d\n", it - vec.begin());
  }

#ifndef ONLINE_JUDGE
  // freopen("./diff.txt", "w", stdout);
  // system("diff ./out_std.txt ./out.txt | wc -l");
  // system("diff ./out_std.txt ./out.txt");
#endif

  return 0;
}

/*
input 01
10
10 2 20 71 3 5 100 66 4 3
5
10
20
30
100
70
output 01
6
7
7
10
8
*/