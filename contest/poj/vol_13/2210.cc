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

using namespace std;
typedef __int64 ll;
const ll ds = 86400LL;
const ll ori = 63113904000LL;
ll leap_mc[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
ll mc[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
ll yc[50005];
int main(){
    int T;
    ll hour, minute, second, day, month, year, t;
    ll rh, rmi, rs, rd, rm, ry;
    bool leap;
    yc[0] = 0;
    for(int i=1;i<=50000;i++){
        leap = ((i - 1) % 4 == 0 && (i - 1) % 100 != 0) || ((i - 1) % 400 == 0);
        if(leap) yc[i] = yc[i - 1] + ds * 366;
        else yc[i] = yc[i - 1] + ds * 365;
    }
    for(scanf("%d", &T);T--;){
        scanf("%I64d:%I64d:%I64d %I64d.%I64d.%I64d", &hour, &minute, &second, &day, &month, &year);
        leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        t = hour * 3600 + minute * 60 + second + yc[year] + (day - 1) * ds;
        if(leap) t += leap_mc[month - 1] * ds;
        else t += mc[month - 1] * ds;
        t -= ori;
        //cout << t << endl;
        //cout<< t - (yc[2001] - yc[2000] )<< endl;
        t = (ll)(100000.0 * t / 86400.0);
        rs = t % 100; t /= 100;
        rmi = t % 100; t /= 100;
        rh = t % 10; t /= 10;
        rd = t % 100 + 1; t /= 100;
        rm = t % 10 + 1; t /= 10;
        ry = t;
        printf("%I64d:%I64d:%I64d %I64d.%I64d.%I64d\n", rh, rmi, rs, rd, rm, ry);
    }
    return 0;
}
