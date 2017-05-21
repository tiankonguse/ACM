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

int main(){
    double mw, mi, tw, ti;
    double w_t0, i_t0, w_ti, i_tw;
    double t;
    while(~scanf("%lf%lf%lf%lf", &mw, &mi, &tw, &ti)){
        if(mw == 0 && mi == 0 && tw == 0 && ti == 0) break;
        ti = -ti;
        w_t0 = mw * tw * 4.19;
        i_t0 = mi * ti * 2.09;
        w_ti = mw * 335.0;
        i_tw = mi * 335.0;

        // all water
        if(w_t0 > i_t0 + i_tw){
            t = tw - (i_t0 + i_tw) / mw / 4.19;
            t = mw * t / (mw + mi);
            printf("0.0 g of ice and %.1lf g of water at %.1lf C\n", mw + mi, t);
        }
        // all ice
        else if(i_t0 > w_t0 + w_ti){
            t = ti - (w_t0 + w_ti) / mi / 2.09;
            t = mi * t / (mw + mi);
            printf("%.1lf g of ice and 0.0 g of water at %.1lf C\n", mw + mi, -t);
        }
        // water & ice & water firstly to zero
        else if(w_t0 < i_t0){
            t = i_t0 - w_t0;
            t /= 335.0;
            printf("%.1lf g of ice and %.1lf g of water at 0.0 C\n", mi + t, mw - t);
        }
        // water & ice & ice firstly to zero
        else{
            t = w_t0 - i_t0;
            t /= 335.0;
            printf("%.1lf g of ice and %.1lf g of water at 0.0 C\n", mi - t, mw + t);
        }
    }
    return 0;
}
 
