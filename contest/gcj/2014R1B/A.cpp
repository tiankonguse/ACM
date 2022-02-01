#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 105;
int n;
string s[N];
string base;
vector <int> a[N];

string getBase(const string &s) {
    base = "";
    for (char c : s) {
        if (base.empty() || base.back() != c) {
            base += c;
        }
    }
    return base;
}

bool match(const string &base, const string &s) {
    return getBase(s) == base;
}

vector <int> getVec(const string &s) {
    vector <int> res;
    base = "";
    for (char c : s) {
        if (base.empty() || base.back() != c) {
            base += c;
            res.push_back(1);
        } else {
            res.back()++;
        }
    }
    return res;
}

int getAns(vector <int> v) {
    assert((int)v.size() == n);
    int ans = 0x7FFFFFFF;
    int maxv = *max_element(v.begin(), v.end());
    rep (k, maxv + 2) {
        int tmp = 0;
        for (int x : v) {
            tmp += abs(x - k);
        }
        if (tmp < ans) ans = tmp;
    }
    return ans;
}

int main() {
    int Tc;
    cin >> Tc;
    rep (ri, Tc) {
        printf("Case #%d: ", ri + 1);
        cin >> n;
        rep (i, n) {
            cin >> s[i];
        }
        string base = getBase(s[0]);
        bool bad = 0;
        rep (i, n) if (!match(base, s[i])) {
            bad = 1;
        }
        //cout << base << endl;
        if (bad) {
            puts("Fegla Won");
            continue;
        }
        rep (i, n) {
            a[i] = getVec(s[i]);
            assert(a[i].size() == base.size());
        }
        int ans = 0;
        rep (k, base.size()) {
            vector <int> vec;
            rep (i, n) {
                vec.push_back(a[i][k]);
            }
            ans += getAns(vec);
        }
        cout << ans << endl;
    }
}

