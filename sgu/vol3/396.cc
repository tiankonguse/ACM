#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int const N = 1010;
char s[N];
int dp[N][4][4][2][2];
int pre[N][4][4][2][2][4];

char mp[5] = "LRUD";
int np[128];
vector <pair<int, int> > ans;

inline void upd(int idx, int pl, int pr, int plb, int prb, int l, int r, int lb, int rb, int val) {
  // illegal
  if (l == 1 && r == 0) {
    return;
  }
  if (val < dp[idx][l][r][lb][rb]) {
    dp[idx][l][r][lb][rb] = val;
    pre[idx][l][r][lb][rb][0] = pl;
    pre[idx][l][r][lb][rb][1] = pr;
    pre[idx][l][r][lb][rb][2] = plb;
    pre[idx][l][r][lb][rb][3] = prb;
  }
}

void update(int idx, int l, int r, int lb, int rb) {
  int v0 = dp[idx][l][r][lb][rb];
  // not to change legs position
  if (s[idx] == 'N') {
    upd(idx + 1, l, r, lb, rb, l, r, 0, 0, v0);
  }
  // not to change legs position and beat
  if (mp[l] == s[idx]) {
    upd(idx + 1, l, r, lb, rb, l, r, 1, 0, v0 + 1);
  }
  if (mp[r] == s[idx]) {
    upd(idx + 1, l, r, lb, rb, l, r, 0, 1, v0 + 1);
  }
  // Move the leg and beat
  if (s[idx] == 'N') {
    for (int i = 0; i < 4; ++i) {
      if (i == l || i == r) continue;
      upd(idx + 1, l, r, lb, rb, i, r, 1, 0, v0 + (lb ? 9 : 3));
      upd(idx + 1, l, r, lb, rb, l, i, 0, 1, v0 + (rb ? 9 : 3));
    }
  } else if (mp[l] != s[idx] && mp[r] != s[idx]) {
    upd(idx + 1, l, r, lb, rb, np[s[idx]], r, 1, 0, v0 + (lb ? 9 : 3));
    upd(idx + 1, l, r, lb, rb, l, np[s[idx]], 0, 1, v0 + (rb ? 9 : 3));
  }
  // Jump
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i == j) continue;
      if (i == l && j == r) continue;
      if (s[idx] != 'N' && mp[i] != s[idx] && mp[j] != s[idx]) continue;
      upd(idx + 1, l, r, lb, rb, i, j, 1, 1, v0 + 10); 
    }
  }
}

int main() {
  np['L'] = 0, np['R'] = 1, np['U'] = 2, np['D'] = 3;

  int n; scanf("%d %s", &n, s);
  memset(dp, 0x3f, sizeof dp);
  dp[0][0][1][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int l = 0; l < 4; ++l) {
      for (int r = 0; r < 4; ++r) {
        for (int lb = 0; lb < 2; ++lb) {
          for (int rb = 0; rb < 2; ++rb) {
            if (dp[i][l][r][lb][rb] != inf) {
              update(i, l, r, lb, rb);
            }
          }
        }
      }
    }
  }
  int ret = inf, rl, rr, rlb, rrb;
  for (int l = 0; l < 4; ++l) {
    for (int r = 0; r < 4; ++r) {
      for (int lb = 0; lb < 2; ++lb) {
        for (int rb = 0; rb < 2; ++rb) {
          if (dp[n][l][r][lb][rb] < ret) {
            ret = dp[n][l][r][lb][rb];
            rl = l, rr = r, rlb = lb, rrb = rb;
          }
        }
      }
    }
  }
  printf("%d\n", ret);
  for (int i = n; i > 0; --i) {
    ans.push_back(make_pair(rl, rr));
    int tl = pre[i][rl][rr][rlb][rrb][0];
    int tr = pre[i][rl][rr][rlb][rrb][1];
    int tlb = pre[i][rl][rr][rlb][rrb][2];
    int trb = pre[i][rl][rr][rlb][rrb][3];
    rl = tl, rr = tr, rlb = tlb, rrb = trb;
  }
  for (int i = n - 1; i >= 0; --i) {
    printf("%c%c\n", mp[ans[i].first], mp[ans[i].second]);
  }
  return 0;
}
