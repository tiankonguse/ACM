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

vector<vector<string>> vec;
vector<vector<pair<int, int>>> vec_up_down;  //预处理，每列上下边界1的个数

char str[max5];

void init(int pos, int m) {
  const auto& matrix = vec[pos];
  auto& up_down = vec_up_down[pos];
  int n = matrix.size();
  up_down.resize(m);

  for (int i = 0; i < m; i++) {
    int num = 0;
    for (int j = 0; j < n; j++) {
      if (matrix[j][i] == '0') {
        break;
      }
      num++;
    }
    up_down[i].first = num;  //上边界

    num = 0;
    for (int j = n - 1; j >= 0; j--) {
      if (matrix[j][i] == '0') {
        break;
      }
      num++;
    }
    up_down[i].second = num;  //下边界
  }
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("./in.txt", "r", stdin);
  // freopen("./out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d", &m, &k);
    vec.clear();
    vec.resize(k);
    vec_up_down.clear();
    vec_up_down.resize(k);
    for (int i = 0; i < k; i++) {
      scanf("%d", &n);
      vec[i].resize(n);
      for (int j = 0; j < n; j++) {
        scanf("%s", str);
        vec[i][j] = str;
      }

      init(i, m);
    }

    int ans = 0;

    for (int l = 0; l < m; l++) {        //枚举左边界
      unordered_set<int> full_pos;       // [l,r] 全 1 的矩阵
      unordered_map<int, int> up_pos;    // [l,r] 下边界全1的矩阵
      unordered_map<int, int> down_pos;  // [l,r] 上边界全1的矩阵

      map<int, unordered_set<int>> up_val;  // [l,r] 下边界全1的矩阵，倒排
      map<int, unordered_set<int>> down_val;  // [l,r] 下边界全1的矩阵，倒排

      for (int i = 0; i < k; i++) {
        full_pos.insert(i);

        if (up_down[l].first > 0) {
          up_pos[i] = up_down[l].first;
          up_val[up_down[l].first].insert(i);
        }
        if (up_down[l].second > 0) {
          down_pos[i] = up_down[l].second;
          down_val[up_down[l].second].insert(i);
        }
      }

      for (int r = l; r < m; r++) {  // 枚举右边界
        for (auto it = full_pos.begin(); it != full_pos.end();) {
          int i = *it;
          int n = vec[i].size();
          auto& up_down = vec_up_down[i];
          if (up_down[r].first == n) {
            it++;
            continue;
          }

          // 需要从 full_pos 删除
          it++;
          full_pos.erase(i);

          // i 可能需要加到
          tryAddUp(i, r);
          tryAddDown(i, r);
        }

        for (auto it = up_pos.begin(); it != up_pos.end();) {
          int i = it->first;
          int h = it->second;
          auto& up_down = vec_up_down[i];

          if (up_down[l].first == 0) {
            it++;
            tryDelUp(i);
            continue;
          }

          tryUpdateUp(i, r);
          it++;
        }

        for (auto it = down_pos.begin(); it != down_pos.end();) {
          int i = it->first;
          int h = it->second;
          auto& up_down = vec_up_down[i];

          if (up_down[l].second == 0) {
            it++;
            tryDelDown(i);
            continue;
          }

          tryUpdateDown(i, r);
          it++;
        }

        //

      }
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