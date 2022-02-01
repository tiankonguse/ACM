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
#define maxn 111
using namespace std;
const double eps = 1e-9;
char str0[maxn], str[maxn];
int main(){
    int l, p, q;
    double a, t, r, res;
    bool flag;
    while(~scanf("%d %lf", &l, &a)){
        a /= pow(10.0, l);
        sprintf(str0, "%.11lf", a);
        flag = false;
        for(double i=0;;i++){
            t = (i + a) * (i + a);
           // cout<<ceil(t)<<endl; system("pause");
            r = sqrt( ceil(t) );
            sprintf(str, "%.11lf", r);
            flag = true;
            p = q = 0;
            while(str0[p] != '.') p++;
            while(str[q] != '.') q++;
            for(int i=1;i<=l;i++){
                if(str0[i + p] != str[i + q]){
                    flag = false;
                    break;
                }
            }
            if(flag) res = ceil(t);

        if(flag) break;
        }
        printf("%.0I64lf\n", res);
    }
    return 0;
}
