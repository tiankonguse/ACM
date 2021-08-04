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

const int N = 100;
ll str[N][N];
ll fun(int m, int n) {
  if (str[m][n] != -1) return str[m][n];
  if (m == n || n == 0) return str[m][n] = 1;
  if (m < n) return str[m][n] = 0;
  return str[m][n] = fun(m - 1, n - 1) + fun(m - 1, n);
}

ll A[20];

unordered_map<ll, pll> m;

bool LessPLL(const pll& a, const pll& b) {
  if (a.first + a.second == b.first + b.second) {
    return a.first < b.first;
  } else {
    return a.first + a.second < b.first + b.second;
  }
}

void Init() {
  memset(str, -1, sizeof(str));
  for (int i = 1; i < 42; i++) {
    for (int j = 1; j + j <= i; j++) {
      ll x = fun(i, j);
      pll tmp_ans = {i, j};
      if (m.count(x) == 0) {
        m[x] = tmp_ans;
      } else if (LessPLL(tmp_ans, m[x])) {
        m[x] = tmp_ans;
      }
    }
  }

  A[0] = 1;
  for (int i = 1; i < 12; i++) {
    A[i] = A[i - 1] * i;
    // printf("i=%d a=%lld\n", i, A[i]);
  }
}

int CheckEx(ll n, const ll k, const ll target) {
  double sum = 1.0;
  for (int i = 0; i < k; i++) {
    sum *= n;
    if (sum > target) {
      return 1;
    }
    n--;
  }
  return -1;
}

int Check(const ll n, const ll k, const ll target) {
  ll tmp_n = n;
  ll tmp_target = target;
  for (int i = 0; i < k; i++, tmp_n--) {
    if (tmp_target % tmp_n == 0) {
      tmp_target /= tmp_n;
      continue;
    } else {
      return CheckEx(n, k, target);
    }
  }
  if (tmp_target == 1) {
    return 0;
  } else {
    return -1;
  }
}

pll Cal(const ll x, const ll k) {
  ll target = x * A[k];

  ll l = k, r = pow(target, 1.0 / k) + k;
  // printf("x=%lld k=%lld l=%lld, r=%lld\n", x, k, l, r);
  while (l < r) {
    ll mid = (l + r) / 2;
    int ret = Check(mid, k, target);
    // printf("x=%lld k=%lld mid=%lld ret=%d\n", x, k, mid, ret);

    if (ret < 0) {
      l = mid + 1;
    } else if (ret > 0) {
      r = mid;
    } else {
      return {mid, k};
    }
  }

  return {x, 1};
}

void Solver() {
  ll x;
  scanf("%lld", &x);
  if (x == 1) {
    printf("0 0\n");
    return;
  }

  if (m.count(x)) {
    pll ans = m[x];
    printf("%lld %lld\n", ans.first, ans.second);
    return;
  }

  pll ans = {x, 1};

  for (int k = 2; k <= 11 && k <= x; k++) {
    pll ans_k = Cal(x, k);
    if (LessPLL(ans_k, ans)) {
      ans = ans_k;
    }
  }
  printf("%lld %lld\n", ans.first, ans.second);
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("./in.txt", "r", stdin);
  // freopen("./out.txt", "w", stdout);
#endif

  Init();

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