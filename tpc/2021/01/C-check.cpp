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

vector<int> str;
bool check_2_98(int n, int k) {
  if (n == 1) {
    // printf("No\n");
    return false;
  }
  int maxNum = n * (n - 1) / 2;
  if (k > maxNum) {
    // printf("No\n");
    return false;
  }

  for (int a = 0; a <= n; a++) {              // 2
    for (int b = 0; b + a <= n; b++) {        // 98
        int ans = a * (a - 1) / 2 + a * b + b * (b-1)/2;
        if (ans == k) {
          // printf("Yes\n");
          // int one = n - a - b - c;
          // str.clear();
          // while (one--) {
          //   str.push_back(1);
          // }
          // while (a--) {
          //   str.push_back(2);
          // }
          // while (b--) {
          //   str.push_back(7);
          // }
          // while (c--) {
          //   str.push_back(9);
          // }
          // bool flag = false;
          // for (int i = 0; i < n; i++) {
          //   printf("%d%c", str[i], i + 1 == n ? '\n' : ' ');
          // }

          return true;
        }
      }
  }
  // printf("No\n");
  return false;
}

bool check_2_7_98(int n, int k) {
  if (n == 1) {
    // printf("No\n");
    return false;
  }
  int maxNum = n * (n - 1) / 2;
  if (k > maxNum) {
    // printf("No\n");
    return false;
  }

  for (int a = 0; a <= n; a++) {              // 2
    for (int b = 0; b + a <= n; b++) {        // 7
      for (int c = 0; c + a + b <= n; c++) {  // 98
        int ans = a * (a - 1) / 2 + a * b + b * (b - 1)/2 + b * c;
        if (ans == k) {
          // printf("Yes\n");
          // int one = n - a - b - c;
          // str.clear();
          // while (one--) {
          //   str.push_back(1);
          // }
          // while (a--) {
          //   str.push_back(2);
          // }
          // while (b--) {
          //   str.push_back(7);
          // }
          // while (c--) {
          //   str.push_back(9);
          // }
          // bool flag = false;
          // for (int i = 0; i < n; i++) {
          //   printf("%d%c", str[i], i + 1 == n ? '\n' : ' ');
          // }

          return true;
        }
      }
    }
  }
  // printf("No\n");
  return false;
}

bool check_2_7_9(int n, int k) {
  if (n == 1) {
    printf("No\n");
    return false;
  }
  int maxNum = n * (n - 1) / 2;
  if (k > maxNum) {
    printf("No\n");
    return false;
  }

  for (int a = 0; a <= n; a++) {              // 2
    for (int b = 0; b + a <= n; b++) {        // 7
      for (int c = 0; c + a + b <= n; c++) {  // 9
        int ans = a * (a - 1) / 2 + a * b + b * c;
        if (ans == k) {
          // printf("Yes\n");
          // int one = n - a - b - c;
          // str.clear();
          // while (one--) {
          //   str.push_back(1);
          // }
          // while (a--) {
          //   str.push_back(2);
          // }
          // while (b--) {
          //   str.push_back(7);
          // }
          // while (c--) {
          //   str.push_back(9);
          // }
          // bool flag = false;
          // for (int i = 0; i < n; i++) {
          //   printf("%d%c", str[i], i + 1 == n ? '\n' : ' ');
          // }

          return true;
        }
      }
    }
  }
  // printf("No\n");
  return false;
}

void init() {
  set<int> s;
  for(int i=0;i<10000;i++){
    s.insert(i*i);
  }
  for(int i=2;i<3;i++){
    for(int j=i+1;j<1000;j++){
      for(int k=j+1;k<1000;k++){
        if(s.count(i+i) && s.count(j+j) == 0 && s.count(k+k) == 1 && s.count(i+j) && s.count(j+k) == 0 && s.count(k+i) == 1){
          printf("i=%d j=%d k=%d\n", i, j, k);
          return ;
        }
      }
    }
  }
  printf("begin\n");
  // for(int i=2;i<=10;i++){
  //   int k = i * (i-1)/2;
  //   for(int j=1;j<=k;j++){
  //     // if(i==5){
  //     //   printf("n=%d k=%d ans=%d\n", i, j, check_2_98(i, j));
  //     // }
  //     if(!check_2_7_98(i, j)){
  //       printf("n=%d k=%d\n", i, j);
  //     }
  //   }
  // }
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("./in.txt", "r", stdin);
  // freopen("./out.txt", "w", stdout);
#endif
  init();
  
  int t;
  // scanf("%d", &t);
  // while (t--) {
  //   int n, k;
  //   scanf("%d%d", &n, &k);
  //   check(n, k);
  // }

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