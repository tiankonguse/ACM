#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 105

int n , a[N] ; LL res[N];
priority_queue< pair<int , LL> > Q;


void work(){
    int i , maxdep = 0 , x , y;
    memset(res , 0 , sizeof(res));
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
        maxdep = max(a[i] , maxdep);
    }
    res[maxdep] = -1;
    while (!Q.empty()) Q.pop();
    for (i = 1 ; i <= n ; ++ i) {
        if (a[i] == maxdep)
            Q.push(make_pair(a[i] , -1));
        else
            Q.push(make_pair(a[i] , 1));
    }
    while (Q.size() > 1) {
        pair<int , LL> A = Q.top(); Q.pop();
        pair<int , LL> B = Q.top(); Q.pop();
        if (A.second == 1) {
            A.second = res[A.first + 1];

        }
        res[A.first] = min(A.second , res[A.first]);
        res[B.first] = min(B.second , res[B.first]);
        if (B.second == 1) {
            B.second = res[B.first + 1];
        }
        assert(A.first == B.first);
        Q.push(make_pair(A.first - 1 , A.second + B.second));
    }
    printf("%lld\n" , -Q.top().second);
}

int main(){
    while (scanf("%d",&n)==1){
        work();
    }
}
