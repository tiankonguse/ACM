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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 100100
using namespace std;
struct node{
    double a, b, c;
    friend bool operator<(node x, node y){
        return x.c < y.c;
    }
}p[maxn];
int main(){
    int n;
    double s, res;
    while(~scanf("%d", &n)){
        s = res = 0;
        for(int i=0;i<n;i++){
            scanf("%lf%lf", &p[i].a, &p[i].b);
            p[i].c = p[i].a / p[i].b;
            s += p[i].b;
        }
        sort(p, p + n);
        for(int i=0;i<n;i++){
            s -= p[i].b;
            res += p[i].a * s;
        }
        printf("%.0lf\n", res * 2);
    }
    return 0;
}
