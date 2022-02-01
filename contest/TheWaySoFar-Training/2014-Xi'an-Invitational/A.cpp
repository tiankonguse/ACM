#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
//#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 1000005;


void work() {
    char c , t[5] = {};
    int res = 0;
    while (c = getchar() , ~c) {
        t[0] = t[1] , t[1] = t[2] , t[2] = t[3] , t[3] = tolower(c);
        if (strcmp(t , "doge") == 0)
            ++ res;
    }
    cout << res << endl;
}


int main()
{
    work();
    return 0;
}
