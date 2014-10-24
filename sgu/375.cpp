#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define N 505
int n ;

void work()
{
    cin >> n;
    vector<int> res;
    if (~n & 1) {
        puts("No solution");
        return;
    }
    while (n > 1) {
        int x = n + 1 >> 1 , y = n - 1 >> 1;
        if (x & 1)
            res.push_back(1) , n = x;
        else
            res.push_back(2) , n = y;
    }
    reverse(res.begin() , res.end());
    printf("%d\n" , res.size());
    for (int i = 0 ; i < res.size() ; ++ i) {
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
    }

}

int main()
{
    work();
    return 0;
}

