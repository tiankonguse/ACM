#include <bits/stdc++.h>
int const inf = 0x3f3f3f3f;
using namespace std;
int h, w;
int const dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
int calRect(int x1, int y1, int x2, int y2) {
  int t1 = x1 - 2 + y1 - 2;
  int t2 = x2 - 1 + y2 - 1;
  int lt = t1 - t2;
  return t1 + t1 + 2;
}
int calOneline(int x1, int x2, int s) {
  if (x1 > x2) {
    x1 = s - x1 + 1;
    x2 = s - x2 + 1;
  }
  if (x2 == 2) return 1;
  int t3 = (x2 - 3) * 2;
  int t4 = (x2 - 3) - (x1 - 1);
  if (t4 % 2 == 0) {
    return t3 + 2;
  } else {
    return t3 + 3;
  }
}
int calThief(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) return 0;
  if (h == 1) return calOneline(y2, y1, w);
  else if (w == 1) return calOneline(x2, x1, h);
  int diff = abs(x1 - x2) + abs(y1 - y2);
  if (diff & 1) return -1;
  if (x2 < x1) {
    x1 = h - x1 + 1;
    x2 = h - x2 + 1;
  }
  if (y2 < y1) {
    y1 = w - y1 + 1;
    y2 = w - y2 + 1;
  }
  int ret = calRect(h - x1 + 1, w - y1 + 1, h - x2 + 1, w - y2 + 1);
  int dx = x2 - x1, dy = y2 - y1, tx, ty;
  if (dx < dy) ret = min(ret, calRect(x1, w - y1 + 1, x2, w - y2 + 1));
  else if (dx > dy) ret = min(ret, calRect(h - x1 + 1, y1, h - x2 + 1, y2)); 
  return ret;
}

int main() {
  int x1, y1, x2, y2; char fm[2];
  scanf("%d%d%d%d%d%d %s", &h, &w, &x1, &y1, &x2, &y2, fm);
  if (fm[0] == 'T') {
    int r = calThief(x1, y1, x2, y2);
    if (r == -1) r = 0;
    printf("%d\n", r);
  } else {
    int ret = inf;   
    for (int i = 0; i < 4; ++i) {
      int tx = x1 + dir[i][0];
      int ty = y1 + dir[i][1];
      if (tx >= 1 && tx <= h && ty >= 1 && ty <= w) {
        int r = calThief(tx, ty, x2, y2);
        ret = min(ret, r + 1);
      }
    }
    if (ret == inf) puts("0");
    else printf("%d\n", ret);
  }
  return 0;
}
