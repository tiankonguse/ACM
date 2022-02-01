
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

char op[10];

struct St {
  int op;  // 1: set. 2: if
  int y, v;
  int child, pre, next, last;
  St() {
    op = 0;
    y = v = 0;
    child = pre = next = last = 0;
  }
};

St nodes[max5];
int index = 0;

// if
//   child -> 第一个儿子
//   pre  -> 儿子之间的链表
//   next  -> 儿子之间的链表
//   last  -> 最后一个儿子
int AddNode(St* root) {
  int last = ++index;
  if (root->last == 0) {
    root->child = last;
  } else {
    nodes[root->last].next = last;
    nodes[last].pre = root->last;
  }
  root->last = last;
  return last;
}

void AddNext(St* root, int y, int v) {
  int last = AddNode(root);
  nodes[last].op = 1;
  nodes[last].y = y;
  nodes[last].v = v;
}
void AddIf(St* root, int y) {
  int last = AddNode(root);
  nodes[last].op = 2;
  nodes[last].y = y;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
  // diff out.txt out_std.txt
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, s;
    stack<int> sta;
    St* root = &nodes[0];
    root->op = 2;
    root->y = 0;
    root->next = root->child = 0;

    sta.push(0);
    for (int i = 1; i <= n; i++) {
      scanf("%s", op);

      int pos = sta.top();
      root = &nodes[pos];

      if (op[0] == 's') {  // set
        int y, v;
        scanf("%d%d", &y, &v);
        int now = AddNode(root);
        AddNext(root, y, v);
      } else if (op[0] == 'i') {  // if
        int y;
        scanf("%d", &y);
        AddIf(root, y);
        sta.push(root->last);
      } else if (op[0] == 'e') {  // end
        sta.pop();
      }
    }

  }
  return 0;
}