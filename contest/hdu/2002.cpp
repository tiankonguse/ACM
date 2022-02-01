#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;
const double PI = 3.1415927;
//4/3* π r ^3
int main() {
	double r;
	while(~scanf("%lf",&r)){
		printf("%.3f\n",4*PI*r*r*r/3);
	}

    return 0;
}
