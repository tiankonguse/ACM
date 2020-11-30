#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 24;
int n;
int a[N];
int where[N];
set < vector <PII> > se[N + 5];
vector <PII> mp;

void dfs(int);

void choose(int i, int j = 0, int s = 0, int used = 0) {
    if (s > a[i] - 1) return;
    if (j == mp.size()) {
        if ((s == a[i] - 1 && used >= 2) || a[i] == 1) {
            mp[where[i]].second++;
            dfs(i + 1);
            mp[where[i]].second--;
        }
    } else {
        rep (k, mp[j].second + 1) {
            if (s + mp[j].first * k > a[i] - 1) break;
            mp[j].second -= k;
            choose(i, j + 1, s + mp[j].first * k, used + k);
            mp[j].second += k;
        }
    }
}

void dfs(int i) {
    //printf("dfs %d\n", i);
    if (i == n) {
        throw 1;
    } else {
        if (se[i].count(mp)) return;
        se[i].insert(mp);
        choose(i);
    }
}

bool gao() {
    int sum = 0;
    rep (i, n) {
        if (sum < a[i] - 1) {
            return 0;        
        }
        sum++;
    }
    if (a[n - 1] != n) return 0;
    try {
        rep (i, n) {
            if (!mp.empty() && mp.back().first == a[i]) {
                mp.back().second++;
            } else {
                mp.push_back(make_pair(a[i], 1));
            }
            where[i] = mp.size() - 1;
        }
        rep (i, mp.size()) mp[i].second = 0;
        dfs(0);
    } catch (const int &res) {
        return res;
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", &a[i]);
    sort(a, a + n);
    puts(gao() ? "YES" : "NO");
}

