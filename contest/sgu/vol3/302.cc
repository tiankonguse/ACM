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
int const maxn = 1010;
typedef long long ll;
char str[maxn];
int s[maxn], top;
 
int main() {
	scanf(" %s", str);
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '<') {
			if (str[i + 1] == '/') --top;
			else {
				if (str[i + 1] == 'U') s[++top] = 1;
				else s[++top] = 2;
			}
			while (str[i] != '>') ++i;
		}
		else {
			if (s[top] == 1) putchar(toupper(str[i]));
			else if (s[top] == 2) putchar(tolower(str[i]));
			else putchar(str[i]);
		}
	}
	putchar(10);
	return 0;
}

