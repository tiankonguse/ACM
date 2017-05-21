#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
char s[100100]; int n;
int readComment(int i) {
	i += 2;
	while (i < n && !(s[i] == '*' && s[i + 1] == ')')) ++i;
	if (i >= n) throw 0;
	return i + 1;
}
inline bool check(char c) {
	return isdigit(c) || c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '\n';
}
int main() {
	int top = 0;
	while ((s[n++] = getchar()) != EOF);
	try {
		rep(i, n) {
			if (s[i] == '(' && s[i + 1] == '*') { i = readComment(i); }
			else if (s[i] == '(') {
				++top;
				while (top) {
					++i;
					if (i >= n) throw 0;
					if (s[i] == ')') { if (--top == 0) break; }
					else if (s[i] == '(' && s[i + 1] == '*') i = readComment(i);
					else if (s[i] == '(') ++top;
					else if (!check(s[i])) throw 0;
				}
			}
			else if (s[i] == ')') throw 0;
		}
	}
	catch (int) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}
