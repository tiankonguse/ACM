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

map<int, int> m;

bool check(int val) {
  for (int i = 1; i < val; i++) {
    if (m.count(i) == 0 && m.count(val - i) == 0 && i != val - i) {
      return true;
    }
  }
  return false;
}

int solver() {
  int num = 0;
  int pos = 0;

  for (auto& p : m) {
    if (p.second >= 3) {
      return 0; // 相同数字大于 2 次，肯定没答案
    }
    if (p.second == 2) {
      num++;
      pos = p.first;
    }
  }

  if (num > 1) {
    return 0; // 相同数字出现多次，肯定没答案
  }

  int ans = 0;
  if (num == 1) {
    // printf("num=%d\n", num);
    // pos 有两个，必须尝试拆分 pos，判断是否存在答案
    if (check(pos)) {
      ans = 2;
    }
  } else {
    //都是一个数字
    for (auto& p : m) {
      if (check(p.first)) {
        ans++;
      }
    }
  }
  return ans;
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
    m.clear();
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      m[v]++;
    }
    // for(auto&p: m){
    //   printf("k=%d v=%d\n", p.first, p.second);
    // }

    printf("%d\n", solver());
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