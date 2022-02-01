
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

// lower_bound 大于等于
// upper_bound 大于

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

vector<vector<pair<int, int>>> base_inut = {
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 0}},  // 1
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 1}},  // 2
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 2}},  // 3
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}},  // 4
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 2}},  // 5
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 1}},  // 6
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {1, 3}, {2, 1}},  // 7
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {1, 3}, {2, 2}},  // 8
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {1, 3}, {2, 3}},  // 9
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {2, 2}, {2, 3}},  // 10
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}},  // 11
};

struct St {
  int n, m;
  vector<pair<int, int>> unit;
  St() {}
  St(const vector<pair<int, int>>& vec) : unit(vec) {
    n = m = 0;
    for (auto& p : vec) {
      n = max(n, p.first + 1);
      m = max(m, p.second + 1);
    }
  }
  void Output() {
    for (auto& p : unit) {
      printf("[%d,%d] ", p.first, p.second);
    }
    printf("\n");
  }
};
vector<St> allUnit;

vector<string> unitToStr(const vector<pair<int, int>>& vec) {
  int n = 0, m = 0;
  for (auto& p : vec) {
    n = max(n, p.first + 1);
    m = max(m, p.second + 1);
  }
  vector<string> ret(n, string(m, '.'));

  for (auto& p : vec) {
    ret[p.first][p.second] = 'O';
  }

  return ret;
}

void Circle(vector<string>& in) {
  int n = in.size();
  int m = in[0].size();
  vector<string> out(m, string(n, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      out[j][n - 1 - i] = in[i][j];
    }
  }
  out.swap(in);
}

void Flip(vector<string>& in) {
  int n = in.size();
  int m = in[0].size();
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    swap(in[i], in[j]);
  }
}

vector<pair<int, int>> StrToUnit(vector<string>& in) {
  vector<pair<int, int>> vec;
  int n = in.size();
  int m = in[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (in[i][j] != '.') {
        vec.push_back({i, j});
      }
    }
  }
  return vec;
}

void init() {
  for (auto& vec : base_inut) {
    vector<string> str;
    str = unitToStr(vec);
    for (int i = 0; i < 4; i++) {
      Circle(str);
      for (int j = 0; j < 2; j++) {
        Flip(str);
        allUnit.push_back(St(StrToUnit(str)));
      }
    }
  }
}

char str[22][22];
int str2[22][22];
int n, m;

bool Ok(St& st, int x, int y, int index) {
  for (auto& p : st.unit) {
    int X = x + p.first;
    int Y = y + p.second;
    if (X >= n || Y >= m) return false;
    if (str2[X][Y] != index) return false;
  }
  return true;
}

void dfs(int x, int y, int index) {
  int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  str[x][y] = '.';
  str2[x][y] = index;
  for (int i = 0; i < 4; i++) {
    int X = x + dir[i][0];
    int Y = y + dir[i][1];
    if (X < 0 || X >= n || Y < 0 || Y >= m) continue;
    if (str[X][Y] == '.') continue;
    dfs(X, Y, index);
  }
}

int check(int x, int y, int index) {
  for (auto& unit : allUnit) {
    // 尝试放 unit
    if (Ok(unit, x, y, index)) {
      return 1;
    }
  }
  return 0;
}

int solver() {
  memset(str2, 0, sizeof(str2));
  int index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (str[i][j] == 'O') {
        index++;
        dfs(i, j, index);
      }
    }
  }

  int ans = 0;
  set<int> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < index; k++) {
        if (s.count(k)) continue;
        if (check(i, j, k)) {
          s.insert(k);
        }
      }
    }
  }
  return s.size();
}

int main() {
  init();
  //   int Case = 0;
  //   for (auto& p : allUnit) {
  //     printf("Case: %d ", Case++);
  //     p.Output();
  //   }

  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
    }

    printf("%d\n", solver());
  }

  return 0;
}