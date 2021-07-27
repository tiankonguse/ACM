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

// int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
// int dir[8][2] = {{0,1},{1, 1},{1,0},{1,-1}, {0,-1}, {-1, -1}, {-1,0}, {-1,
// 1}}; lower_bound 大于等于 upper_bound 大于 vector/array:
// upper_bound(vec.begin(), vec.end(), v) map: m.upper_bound(v) reserve
// vector预先分配内存 reverse(v.begin(), v.end()) 反转 sum =
// accumulate(a.begin(), a.end(), 0); unordered_map / unordered_set
// 排序，小于是升序：[](auto&a, auto&b){ return a < b; })
// 优先队列 priority_queue<Node>：大于是升序
// __builtin_popcount 快速得到 1 的个数
// struct Node{
//     int t;
//     bool operator<(const Node & that)const { return this->t > that.t; }
// };

// mutex mtx;       // 互斥量，锁，定义一个即可
// condition_variable cv; // 条件变量
// cv.notify_one(); // 事件通知
// unique_lock<mutex> lck(mtx);
// cv.wait(lck); //等待事件

// atomic_int tick; // 原子计数
// this_thread::yield();  // 线程 sleep

// #include <semaphore.h> // 需要手动包含信号量头文件
// sem_t sem_done;
// sem_init(&bar_done, 0 , 1);
// sem_wait(&bar_done);
// sem_post(&foo_done);

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

vector<vector<pair<int, ll>>> vec;
struct Node {
  ll none = 0;  // 没有边，不能有边
  ll owen = 0;  // 没有边，内部有边
  ll zero = 0;  // 偶数个边，下去再回来
  ll one = 0;   // 奇数个边，不回来
  ll two = 0;   // 偶数个边，下来上来，再下去
  ll ans = 0;
};
vector<Node> dp;

void CalNone(int root, int pre) {  // 计算 none
  Node& node = dp[root];

  for (auto& p : vec[root]) {
    if (p.first == pre) continue;
    node.none += p.second + dp[p.first].none;
  }
}

void CalZero(int root, int pre) {  //偶数个边，下去再回来
  Node& node = dp[root];

  node.zero = node.none;
  ll sum_zero = 0;
  for (auto& p : vec[root]) {
    if (p.first == pre) continue;
    ll none = p.second + dp[p.first].none;

    ll zero = 0;
    if (p.second == 0) {
      zero = 2 + dp[p.first].zero;
    } else {
      zero = (p.second % 2) + dp[p.first].zero;
    }

    sum_zero += min(none, zero);
  }
  node.zero = node.zero;
}

void CalOne(int root, int pre) {  //奇数个边，不回来
  Node& node = dp[root];

  node.one = node.zero;
  vector<ll> dis;
  for (auto& p : vec[root]) {
    if (p.first == pre) continue;
    dis.push_back(dp[p.first].one - dp[p.first].zero);
  }
  sort(dis.begin(), dis.end());

  node.one = min(node.one, node.zero + dis[0]);
}

void Dfs(int root, int pre) {
  Node& node = dp[root];

  for (auto& p : vec[root]) {
    if (p.first == pre) continue;
    Dfs(p.first, root);
  }

  if (pre != 0 && vec[root].size() == 1) {  // 叶子节点
    return;
  }

  // 计算 none
  CalNone(root, pre);

  //偶数个边，下去再回来
  CalZero(root, pre);

  //奇数个边，不回来
  CalOne(root, pre);
}

void Solver() {
  int n;
  vec.clear();
  scanf("%d", &n);
  vec.resize(n + 1);

  for (int i = 1; i < n; i++) {
    int u, v;
    ll p;
    scanf("%d%d%lld", &u, &v, &p);
    vec[u].push_back({v, p});
    vec[v].push_back({u, p});
  }

  dp.resize(n + 1);

  if (n == 2) {
    dp[1].ans = 0;
  } else {
    Dfs(1, 0);
  }

  printf("%lld\n", dp[1].ans);
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("./in.txt", "r", stdin);
  // freopen("./out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    Solver();
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


output:
*/