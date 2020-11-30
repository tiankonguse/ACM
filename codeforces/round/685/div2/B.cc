
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

char str[max3];
int n;
int pre[max3][2];
int sub[max3][2];

void init(){
    pre[0][0] = pre[0][1] = 0;
    for(int i=1;i<n;i++){
        pre[i][0] = pre[i-1][0];
        pre[i][1] = pre[i-1][1];
        if(str[i-1] == '0'){
            pre[i][0]++;
        }else{
            pre[i][1]++;
        }
    }

    sub[n-1][0] = sub[n-1][1] = 0;
    for(int i = n-2; i>=0;i--){
        sub[i][0] = sub[i+1][0];
        sub[i][1] = sub[i+1][1];
        if(str[i+1] == '0'){
            sub[i][0]++;
        }else{
            sub[i][1]++;
        }
    }
}

bool query(int l,int r){
    if(l != 0){
        int v = str[l] - '0';
        if(pre[l][v] > 0){
            return true;
        }
    }
    if(r != n-1){
        int v = str[r] - '0';
        if(sub[r][v] > 0){
            return true;
        }
    }
    return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int q;
    scanf("%d%d", &n, &q);
    scanf("%s", str);
    init();
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%s\n", query(l-1, r-1) ? "YES" : "NO");
    }
  }
  return 0;
}