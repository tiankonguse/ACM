#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
#define eps 1e-12
#define maxn 110000
#define maxm 11

#define inf 1000000000
#define PB push_back
#define MP make_pair
string buf, str;
int n, m;
map<string, int> mp; int idx;
int getID(string s) {
    if (mp.find(s) == mp.end()) mp[s] = idx++;
    return mp[s];
}
int mat[maxn][maxm];

struct HashMap {
    int p[maxn], next[maxn], idx;
    int dp[maxn];
    ll v[maxn];
    void init() {
        idx = 0;
        memset(p, 0xff, sizeof p);
    }
    int add(ll u, int val) {
        int x = u % maxn;
        for (int i = p[x]; i != -1; i = next[i]) {
            if (v[i] == u) {
                return dp[i];
            }
        }
        dp[idx] = val;
        v[idx] = u;
        next[idx] = p[x];
        p[x] = idx++;
        return -1;
    }
}hm;

int main() {
    while ( cin >> n >> m ) {
        mp.clear(); idx = 0;
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            getline(cin, buf);
            int len = buf.length();
            int k = 0;
            str = "";
            for (int j = 0; j < len; ++j) {
                if (buf[j] == ',') {
                    mat[i][k++] = getID(str);
                    str = "";
                }
                else {
                    str += buf[j];
                }
            }
            mat[i][k++] = getID(str);
        }

//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                cout << mat[i][j] << " ";
//            }
//            cout << endl;
//        }
        bool flag = false; int r1, r2, c1, c2;
        int ret; ll val;
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                hm.init();
                for (int k = 0; k < n; ++k) {
                    val = 1LL * mat[k][i] * 100010LL + mat[k][j];
                    ret = hm.add(val, k + 1);
                    if (ret != -1) {
                        r1 = ret;
                        r2 = k + 1;
                        c1 = i + 1;
                        c2 = j + 1;
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }

        if (!flag) puts("YES");
        else {
            puts("NO");
            printf("%d %d\n%d %d\n", r1, r2, c1, c2);
        }

    }
    return 0;
}
