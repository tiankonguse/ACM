#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
int n , a[N];
set< pair<int , int> > hash;
void work()
{
    int i , K = 0 , B = 0;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    hash.clear();
    for (i = 1 ; i <= n ; ++ i) {
        hash.insert(make_pair(a[i] , i));
    }
    while (hash.begin() -> first - B > 0) {
        while (hash.begin() -> first * 2 <= (-- hash.end()) -> first + B) {
            pair<int , int> w = *hash.begin(); hash.erase(w);
            hash.insert(make_pair(w.first * 2 - B , w.second));
            ++ K;
        }
        i = hash.begin() -> first * 2 - (-- hash.end()) -> first - B;
        K += i , B += i;
    }
    printf("%d\n" , K);
    if (K > 1000)
        return;
    hash.clear() , K = B = 0;
    for (i = 1 ; i <= n ; ++ i)
        hash.insert(make_pair(a[i] , i));
    while (hash.begin() -> first - B > 0) {
        while (hash.begin() -> first * 2 <= (-- hash.end()) -> first + B) {
            pair<int , int> w = *hash.begin(); hash.erase(w);
            hash.insert(make_pair(w.first * 2 - B , w.second));
            printf("science mission to the planet %d\n" , w.second);
        }
        printf("flying mission\n") , ++ B;
    }



}

int main()
{
    work();
    return 0;
}
