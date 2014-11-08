#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;

vector<int> calcZ(const char* s, int n){
    vector<int> Z(n);
    for(int i=1,x=0,y=0;i<n;i++){
        if(i<=y) Z[i]=min(y-i,Z[i-x]);
        while(i+Z[i]<n && s[i+Z[i]]==s[Z[i]]) Z[i]++;
        if(y<=i+Z[i]) x=i,y=i+Z[i];
    }
    return Z;
}

vector <int> getZ(string s, int idx, int o) {
    if (o) {
        reverse(s.begin(), s.end());
        idx = s.size() - idx - 1;
        vector <int> v = getZ(s, idx, 0);
        reverse(v.begin(), v.end());
        return v;
    } else {
        string t = s.substr(idx) + s;
        vector <int> v = calcZ(t.c_str(), t.size());
        vector <int> res(s.size());
        for (int i = idx, j = 0; j < (int)s.size(); i = (i + 1 == s.size() ? 0 : i + 1), j++) {
            res[i] = v[j];    
        }
        rep (i, s.size()) {
            res[i] = min(res[i], (int)s.size() - i);
            res[i] = min(res[i], (int)s.size() - idx);
        }
        return res;
    }
}

int gao(const string &s) {
    int n = s.size();
    if (n <= 1) return 0;
    int ans = 0;
    int mid = s.size() / 2;
    vector <int> z = getZ(s, mid, 0), zr = getZ(s, mid, 1);
    rep (i, s.size()) {
        if (i == mid) continue;
        if (s[i] != s[mid]) continue;
        int len = z[i] + zr[i] - 1;
        int m = abs(mid - i);
        if (len >= m) ans = max(ans, m);
    }
    ans = max(ans, gao(s.substr(0, mid)));
    ans = max(ans, gao(s.substr(mid)));
    return ans;
}

int main() {
    static char buf[1000005];
    int Tc;
    scanf("%d", &Tc);
    rep (ri, Tc) {
        scanf("%s", buf);
        printf("%d\n", gao(string(buf)));
    }
}

