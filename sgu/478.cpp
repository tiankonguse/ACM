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
using namespace std;
typedef long long LL;
#define N 105
int a , b , n;
vector< pair<int , int> > res;

void work()
{
    int i , j , x , y , z;
    cin >> a >> b >> n;
    x = 0 , y = 0 , j = b;
    for (i = 0 ; i < n ; ++ i) {
        cin >> z;
        if (z < j) {
            y += j - z;
            res.push_back(make_pair(0 , j - z));
            if (y > b)
                break;
        } else {
            x += z - j;
            res.push_back(make_pair(z - j , 0));
            if (x > a)
                break;
        }
        j = b - y + x;
    }
    if (i < n)
        puts("ERROR");
    else {
        for (i = 0 ; i < res.size() ; ++ i) {
            printf("%d %d\n" , res[i].first , res[i].second);
        }
    }
}


int main()
{
    work();
    return 0;
}

