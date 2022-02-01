#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define N 30000005
int n , ca;
long long f[N];
void work() {
    int i , j , x;
    long long res = 0;
    n = 3e7;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = i ; j <= n ; j += i) {
             x = i ^ j;
             if (x > j && x <= n && x % i == 0)
                ++ f[x];
        }
    }
    for (i = 2 ; i <= n ; ++ i)
        f[i] += f[i - 1];
    scanf("%d",&j);
    while (j --){
        scanf("%d",&x);
        printf("Case %d: %lld\n" , ++ ca , f[x]);
    }
}

int main(){
    work();
    return 0;
}
