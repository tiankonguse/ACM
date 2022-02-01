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
// vector/array: upper_bound(vec.begin(), vec.end(), v)
// map: m.upper_bound(v)
// reserve vector预先分配内存
// reverse(v.begin(), v.end()) 反转
// sum = accumulate(a.begin(), a.end(), 0);
// unordered_map / unordered_set
// 排序，小于是升序：[](auto&a, auto&b){ return a < b; })
// 优先队列 priority_queue<Node>：大于是升序
// struct Node{
//     int t;
//     bool operator<(const Node & that)const { return this->t > that.t; }
// };

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

vector<int> vec;
unordered_map<int, int> m;

bool OK(int v) {
  if (m.count(v)) return true;

  for (auto& p : m) {
    int u = p.first;
    if (u % v == 0 || v % u == 0) {
      continue;
    }
    return false;
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("./in.txt", "r", stdin);
  // freopen("./out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vec.clear();
    vec.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &vec[i]);
    }

    int ans = 1;

    int l = 0, r = 1;
    int num = 1;
    m.clear();
    m[vec[0]]++;

    while (l < n && r <= n) {
      while (r < n && OK(vec[r])) {
        num++;
        m[vec[r]]++;
        r++;
        ans = max(ans, num);
      }
      if (r == n) {
        break;
      }

      while (l < r && !OK(vec[r])) {
        num--;
        m[vec[l]]--;
        if (m[vec[l]] == 0) {
          m.erase(vec[l]);
        }
        l++;
      }


      num++;
      m[vec[r]]++;
      r++;
    }

    printf("%d\n", ans);
  }

  // #ifndef ONLINE_JUDGE
  //   freopen("./diff.txt", "w", stdout);
  //   system("diff ./out_std.txt ./out.txt | wc -l");
  //   system("diff ./out_std.txt ./out.txt");
  // #endif

  return 0;
}

/*
input:
3
1
0
20

output:
You are the future of Tencent!
Good luck and Enjoy TPC!
You are the future of Tencent!
*/