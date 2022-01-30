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
// __builtin_popcount 一的个数
// size_t found=str.find(char/char*/string); std::string::npos
// 排序，小于是升序：[](auto&a, auto&b){ return a < b; })
// 优先队列 priority_queue<Node>：大于是升序
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

ll a, b, c, d, k;

ll Cal() {
  if (k == 1 && (c == 1 || c == 2) && c + d < 3) {
    return 0;
  }

  if (k == 1 && (c == 1 || c == 2) && c + d >= 3) {
    ll tmp = 3 - c;
    c += tmp;
    d -= tmp;
    return Cal();  // 此时 c = 3
  }

  // 黑色的没法利用上
  if (k > 1 && (c == 1 || c == 2) && c + d < 3) {
    k--;
    c = 0;
    return Cal();  // 此时 c = 0
  }

  // c == 1 || c == 2 时， c+ d >= 3
  // c == 0 || c == 3 时，没任何限制

  ll bmod5 = b % 5;
  ll bleft5 = 5 - bmod5;
  ll cmod3 = c % 3;
  ll cleft3 = 3 - cmod3;

  if (c / 3 >= k) {  // c 满了
    c = 3 * k;       // 多余的删除

    // b 可能需要补齐
    if (bmod5 > 0 && bleft5 <= d) {
      b += bleft5;
      d -= bleft5;
    }

    a += d;  // 剩余的都给 a
    d -= 0;
    return a * 3 + (b / 5) * 15 + (b % 5) + c / 3 * 10;
  }

  if (bmod5 == 0) {  // 不需要考虑 b
    // 优先把 c 填充满
    if (cmod3 > 0 && cleft3 <= d) {
      c += cleft3;
      d -= cleft3;
    }

    if (k - c / 3 <= d / 3) {  // 可以填充满
      ll addk = k - c / 3;

      c += addk * 3;
      d -= addk * 3;
    } else {  // 无法填充满
      ll addk = d / 3;

      c += addk * 3;
      d -= addk * 3;
    }

    // 剩余的都给 a
    a += d;
    return a * 3 + (b / 5) * 15 + (b % 5) + c / 3 * 10;
  }

  if (cmod3 == 0) {
    if (bmod5 > 0 && bleft5 <= d) {
      b += bleft5;
      d -= bleft5;
      return Cal();
    }

    b -= bmod5;  // 剩余的按 1 块钱处理
    return bmod5 + Cal();
  }

  if (bleft5 + cleft3 <= d) {  // c 未填充满 K，且可以补齐 b 和 c
    b += bleft5;
    d -= bleft5;

    c += cleft3;
    d -= cleft3;
    return Cal();
  }

  // 此时 d 不能补齐 b 和 c
  if ((bmod5 == 1 && cmod3 == 1) || (bmod5 < 4 && cmod3 == 2)) {  // 3 更优
    if (cleft3 <= d) {
      c += cleft3;
      d -= cleft3;
    } else {
      c -= cmod3;  // 不要了
    }
    return Cal();
  }

  // 5 更优
  if (bleft5 <= d) {
    b += bleft5;
    d -= bleft5;
    return Cal();
  }
  b -= bmod5;  // 剩余的按 1 块钱处理
  return bmod5 + Cal();
}

void Solver() {
  scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k);
  printf("%lld\n", Cal());
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