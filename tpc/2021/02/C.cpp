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

vector<unordered_map<int, int>> tree;
unordered_set<int> specialNode;

struct Edge {
  int from, to, val;
  bool operator<(const Edge& e) const { return val < e.val; }
} edges[max5];

int pre[max5];
int rankex[max5];

void init(int n) {
  for (int i = 0; i < n; i++) {
    pre[i] = i;
    rankex[i] = 0;
  }
}

int find_pre(int node) {
  if (pre[node] != node) {
    pre[node] = find_pre(pre[node]);
  }
  return pre[node];
}
void merge_pre(int from, int to) {
  from = find_pre(from);
  to = find_pre(to);
  if (from != to) {
    if (rankex[from] > rankex[to]) {
      pre[to] = from;
    } else {
      pre[from] = to;
      if (rankex[from] == rankex[to]) {
        ++rankex[to];
      }
    }
  }
}

ll solver(int n) {
  if (n == 2) {
    // 特殊情况，两个特殊点互连
    if (tree[0].size() > 0) {
      return tree[0][1];
    } else {
      return -1;
    }
  }

  int find_edge = 0;
  ll sum = 0;

  //缩点
  for (int u : specialNode) {
    int minPos = -1;
    int minVal = 0;
    for (const auto& p : tree[u]) {
      int v = p.first;
      int w = p.second;

      if (specialNode.count(v)) continue;  // 叶子不能连叶子

      if (minPos == -1) {
        minPos = v, minVal = w;
        continue;
      }

      if (minVal > w) {
        minPos = v, minVal = w;
      }
    }

    if (minPos == -1) {
      return -1;  // 这个节点找不到合适的边
    }

    sum += minVal;  //增加一条边
    find_edge++;
  }

  if (n == find_edge + 1) {
    return sum;  //已经找到答案
  }

  // 对于剩下的非特殊点，求最小生成树
  init(n);

  int index = 0;
  for (int u = 0; u < n; u++) {
    if (specialNode.count(u)) continue;
    for (const auto& p : tree[u]) {
      int v = p.first;
      int w = p.second;
      if (specialNode.count(v)) continue;
      edges[index++] = {u, v, w};
      // printf("add : u=%d v=%d w=%d\n", u, v, w);
    }
  }
  // printf("sum=%lld find_edge=%d\n", sum, find_edge);

  sort(edges, edges + index);
  for (int i = 0; i < index; i++) {
    int pre_from = find_pre(edges[i].from);
    int pre_to = find_pre(edges[i].to);
    if (pre_from == pre_to) {
      continue;
    }
    merge_pre(pre_from, pre_to);
    sum += edges[i].val;
    find_edge++;
    if (find_edge + 1 == n) {
      return sum;
    }
  }

  return -1;
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
    int u, v, w;

    scanf("%d%d", &n, &m);
    tree.clear();
    specialNode.clear();
    tree.resize(n);

    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &w);
      if (u == v) {
        continue;
      }
      u--, v--;
      if (u > v) {
        swap(u, v);
      }

      if (tree[u].count(v) && tree[u][v] <= w) {
        continue;  // 没有更优
      }

      tree[u][v] = w;
      tree[v][u] = w;
    }
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &u);
      u--;
      specialNode.insert(u);
    }

    ll ans = solver(n);
    if (ans == -1) {
      printf("Impossible\n");
    } else {
      printf("%lld\n", ans);
    }
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