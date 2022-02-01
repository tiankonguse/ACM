#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;

int Tc;
ll n;

vector <ll> solve(ll n) {
    vector <int> a;
    rep (i, 63) {
        if (n & 1LL << i) {
            a.push_back(i);
        }
    }
    vector < pair <int, int> > res;
    rep (i, a.size()) {
        if (!res.empty() && res.back().first + 1 == a[i]) {
            res.back().second++;
        } else {
            res.push_back(make_pair(a[i], 1));
        }
    }
    vector <ll> ans;
    rep (i, res.size()) {
        ans.push_back(1LL << res[i].first);
        ans.push_back(1LL << res[i].first + res[i].second);
    }
    return ans;
}

int main() {
    cin >> Tc;
    rep (ri, Tc) {
        cin >> n;
        cout << "Case " << ri + 1 << ":";
        vector <ll> res = solve(n);
        //cout << res.size() << endl;
        if (res.size() < 3) {
            cout << " no solution\n";
        } else {
            rep (i, res.size()) {
                cout << " " << res[res.size() - i - 1];
            }
            cout << "\n";
        }
    }   
}

