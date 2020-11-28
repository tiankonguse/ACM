
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

/*
常用的 STL：
1、sort
2、优先队列：最大堆、最小堆
3、map 二分查找
4、vec 二分查找、逆向二分查找
*/

void SortDemo() {
  vector<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  sort(vec.begin(), vec.end(), [](auto& a, auto& b) { return a > b; });
  printf("sort: \n");
  for (int i = 0; i < 10; i++) {
    printf("i=%d v=%d\n", i, vec[i]);
  }
}

void HeapDemo() {
  min_queue<int> minque;
  for (int i = 0; i < 10; i++) {
    minque.push(10 - i);
  }
  printf("min head: \n");
  while (!minque.empty()) {
    printf("%d ", minque.top());
    minque.pop();
  }
  printf("\n");

  max_queue<int> maxque;
  for (int i = 0; i < 10; i++) {
    maxque.push(i);
  }
  printf("max head: \n");
  while (!maxque.empty()) {
    printf("%d ", maxque.top());
    maxque.pop();
  }
  printf("\n");
}

void mapFindDemo() {
  map<int, int> m;
  printf("map \n");
  for (int i = 0; i < 10; i++) {
    m[i * i] = i * i;
    printf("i=%d key=%d val=%d\n", i, i * i, i * i);
  }

  printf("lower: \n");
  for (int i = 0; i < 10; i++) {
    auto itl = m.lower_bound(i);
    if (itl == m.end()) {
      printf("i=%d nofind\n", i);
    } else {
      printf("i=%d key=%d val=%d\n", i, itl->first, itl->second);
    }
  }

  printf("upper: \n");
  for (int i = 0; i < 10; i++) {
    auto itl = m.upper_bound(i);
    if (itl == m.end()) {
      printf("i=%d nofind\n", i);
    } else {
      printf("i=%d key=%d val=%d\n", i, itl->first, itl->second);
    }
  }
}
void vecFindDemo() {
  vector<int> vec;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i * i);
  }

  sort(vec.begin(), vec.end(), [](auto& a, auto& b) { return a < b; });
  printf("vec: \n");
  for (int i = 0; i < 10; i++) {
    printf("i=%d v=%d\n", i, vec[i]);
  }
  printf("lower: \n");
  for (int i = 0; i < 10; i++) {
    auto itl = std::lower_bound(vec.begin(), vec.end(), i);
    if (itl == vec.end()) {
      printf("i=%d nofind\n", i);
    } else {
      printf("i=%d val=%d\n", i, *itl);
    }
  }

  printf("upper: \n");
  for (int i = 0; i < 10; i++) {
    auto itl = std::upper_bound(vec.begin(), vec.end(), i);
    if (itl == vec.end()) {
      printf("i=%d nofind\n", i);
    } else {
      printf("i=%d val=%d\n", i, *itl);
    }
  }

  sort(vec.begin(), vec.end(), [](auto& a, auto& b) { return a > b; });
  printf("rev vec: \n");
  for (int i = 0; i < 10; i++) {
    printf("i=%d v=%d\n", i, vec[i]);
  }
  printf("rev lower: \n");
  for (int i = 0; i < 10; i++) {
    auto itl = std::lower_bound(vec.rbegin(), vec.rend(), i);
    if (itl == vec.rend()) {
      printf("i=%d nofind\n", i);
    } else {
      printf("i=%d val=%d len = %d\n", i, *itl, itl - vec.rbegin());
    }
  }

  printf("rev upper: \n");
  for (int i = 0; i < 10; i++) {
    auto itl = std::upper_bound(vec.rbegin(), vec.rend(), i);
    if (itl == vec.rend()) {
      printf("i=%d nofind\n", i);
    } else {
      printf("i=%d val=%d len = %d\n", i, *itl, itl - vec.rbegin());
    }
  }
}

int main() {
  SortDemo();
  HeapDemo();
  mapFindDemo();
  vecFindDemo();

  return 0;
}