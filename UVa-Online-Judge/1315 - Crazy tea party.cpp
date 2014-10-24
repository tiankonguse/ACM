#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;
#define N 100005

int n , m;

void work()
{
    cin >> n , m = n >> 1;
    cout << (m * (m - 1) + (n - m) * (n - m - 1)) / 2 << endl;
}

void init()
{

}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //init();
        work();
    return 0;
}
