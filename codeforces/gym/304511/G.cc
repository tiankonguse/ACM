
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

const int mod1 = 100000;

ll nums[max6];

struct Date {
  int y, m, d;
  void read() { scanf("%d-%d-%d", &y, &m, &d); }
};

bool isRunYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int day[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Next(Date& start) {
  // 1 3 5 7 8 10 12 => 31
  // 2 => 29|28
  // 4 6 9 11 => 30
  start.d++;
  if (start.d <= day[start.m]) {
    return;
  }

  if (start.m == 2 && isRunYear(start.y) && start.d == 29) {
    return;
  }

  start.d = 1;
  start.m++;

  if (start.m == 13) {
    start.m = 1;
    start.y++;
  }
}

int ans[9];

bool isFirst(const Date& now) {
  // [1-30 ~ 2-10]
  if (now.m == 1 && now.d >= 30) return true;
  if (now.m == 2 && now.d <= 10) return true;
  return false;
}

bool isSecond(const Date& now) {
  // [7-12 ~ 8-22]
  if (now.m == 7 && now.d >= 12) return true;
  if (now.m == 8 && now.d <= 22) return true;
  return false;
}

//周一吃麻辣香锅,情人节(2月14日),七夕节(8月25日)
//周二吃闷骚牛肉
//周三吃金陵香辣烤虾仁, 月初
//周四吃盒饭. , 月末
//周五吃咖喱小厨
//周六吃培根土豆金针菇
//周日吃排骨米饭。
void check(const Date& now, int weekday) {
  // 1-1 ~ 1-29
  // 2-11 ~ 7-11
  // 8-23 ~ 12-31
  if (isFirst(now) || isSecond(now)) {
    return;
  }

  if (now.m == 2 && now.d == 14) {
    ans[1]++;
    return;
  }
  if (now.m == 8 && now.d == 25) {
    ans[1]++;
    return;
  }

  if (now.d == 1) {
    ans[3]++;
    return;
  }
  if (now.m != 2 && now.d == day[now.m]) {
    ans[4]++;
    return;
  }
  if (now.m == 2 && isRunYear(now.y) && now.d == 29) {
    ans[4]++;
    return;
  }
  if (now.m == 2 && !isRunYear(now.y) && now.d == 28) {
    ans[4]++;
    return;
  }
  ans[weekday]++;
}

int main() {
  Date start, finish;
  start.read();
  finish.read();
  int weekday;
  scanf("%d", &weekday);

  memset(ans, 0, sizeof(ans));

  check(start, weekday);
  while (start.y != finish.y || start.m != finish.m || start.d != finish.d) {
    Next(start);
    weekday++;
    if (weekday == 8) {
      weekday = 1;
    }
    check(start, weekday);
  }

  for (int i = 1; i <= 7; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}