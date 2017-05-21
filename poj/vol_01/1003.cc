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
typedef long long ll;

int main() {
    double a, t; int ret;
    while (~scanf("%lf", &a) && a > 1e-8) {
    	ret = 0; 
	for (int i = 2; a > 0; ++i) {
		t = 1.0 / i;
		a -= t;
		++ret;
	}
	printf("%d card(s)\n", ret);
    }
    return 0;
} 

