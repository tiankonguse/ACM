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
char buf[111];

int main() {
    double hh1, mm1, ss1, hh2, mm2, ss2, v, vp;
    double diff, ret = 0;
    hh1 = mm1 = ss1 = vp = 0;
    while ( gets(buf) ){
        if (strlen(buf) > 8) {
            sscanf(buf, "%lf:%lf:%lf %lf", &hh2, &mm2, &ss2, &v);
            diff = (hh2 - hh1) * 3600.0 + (mm2 - mm1) * 60.0 + (ss2 - ss1);
            ret += vp * diff / 3600.0;
            vp = v;
        }
        else {
            sscanf(buf, "%lf:%lf:%lf", &hh2, &mm2, &ss2);
            diff = (hh2 - hh1) * 3600.0 + (mm2 - mm1) * 60.0 + (ss2 - ss1);
            ret += vp * diff / 3600.0;
            printf("%02.0lf:%02.0lf:%02.0lf %.2lf km\n", hh2, mm2, ss2, ret);
        }
        swap(hh1, hh2);
        swap(mm1, mm2);
        swap(ss1, ss2);
    }
    return 0;
}
