#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
int const maxn = 150050;
char s[maxn];
char str[maxn];
bool mark[maxn];

int fun(int n){
    int i = 0, j = 1, len = 0, x, y;
    while(i < n && j < n && len < n){
        x = i + len; if(x >= n) x -= n;
        y = j + len; if(y >= n) y -= n;
        if(str[x] == str[y]) len++;
        else if(str[x] >= str[y]){
            j += len + 1;
            len = 0;
        }
        else{
            i += len + 1;
            len = 0;
        }
  	if (i == j) ++j;
    }
    return min(i, j);
}

string tmp, res;
int main() {
	int n, k, snt;
	while (~scanf("%d%d", &n, &k)) {
		scanf(" %s", s);
		k %= n;
		memset(mark, 0, sizeof mark);
		int cc;
		snt = 0;
		res = "";
		for (int i = 0; i < n; ++i) {
			if (mark[i]) continue;
			cc = 0;
			for (int j = i; ; ) {
				mark[j] = true;
				str[cc++] = s[j];
				j += k; if (j >= n) j -= n;
				if (mark[j]) break;
			}
			int rc = fun(cc);
			tmp = "";
			for (int j = 0; j < cc; ++j) {
				tmp += str[(rc + j) % cc];
			}
			res = max(res, tmp);
			++snt;
		}
		int t = n / res.length();
		for (int i = 0; i < t; ++i) cout << res;
		cout << endl;
	}
    return 0;
}
 
