#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;

int n, m, f[1005];
int num[26];
int val[26];
string a[26];
char buf[10005];

int main() {
	gets(buf);
	sscanf(buf, "%d%d", &n, &m);
	rep (i, n) {
		gets(buf);
		a[i] = buf;
		int len = strlen(buf);
	}
	
}
