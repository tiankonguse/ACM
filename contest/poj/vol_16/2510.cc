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
#define maxn 11005
using namespace std;
struct caffeine{
    int type;
    double n, t;
    caffeine(int _type, double _n, double _t) { type = _type; n = _n; t = _t;}
    caffeine(){}
}data[maxn];
double calc(double t, int id){
    if(data[id].type == 1){
        return max(0.0, 8.0 * data[id].n - (t - data[id].t) / 12.0);
    }
    else{
        return max(0.0, 2.0 * data[id].n - (t - data[id].t) * (t - data[id].t) / 79.0);
    }
}
char str[20];
struct input{
    int type;
    double t, m;
    input(int _type, double _t, double _m){ type = _type, t = _t, m = _m;}
    input(){}
    friend bool operator<(input a, input b){
        if(a.t == b.t) return a.type > b.type;
        else return a.t < b.t;
    }
}inp[maxn];
int main(){
    int n = 0, cnt = 0;
    double m, t, res;
    while(~scanf("%s", str)){
        if(str[0] == 'Q'){
            scanf("%lf", &t);
            inp[cnt++] = input(0, t, 0);
        }
        else if(str[1] == 'h'){
            scanf("%lf%lf", &t, &m);
            inp[cnt++] = input(1, t, m);
        }
        else{
            scanf("%lf%lf", &t, &m);
            inp[cnt++] = input(2, t, m);
        }
    }

    sort(inp, inp + cnt);
    for(int z=0;z<cnt;z++){
        if(inp[z].type == 0){
            res = 0;
            for(int i=0;i<n;i++){
                res += calc(inp[z].t, i);
            }
            printf("%.0lf %.1lf\n", inp[z].t, max(1.0, res));
        }
        else{
            data[n++] = caffeine(inp[z].type, inp[z].m, inp[z].t);
        }
    }
    return 0;
}
