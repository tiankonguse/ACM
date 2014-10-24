#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;

const double pi=acos(-1) , eps = 1e-6;


LL cal(int r , int d , double S) {
    LL sum = 0;
    double R = pi * r * r;
    double W = 4 * (r + d), H = (r + d) * 2;
    double A = (LL)S * W - 2 * R;
    double B = (LL)W * H - 2 * R;
    //cout << (LL)(A / B) << endl;
    //return max((LL)((S * W - W * H) / (W * H / 2 - 2 * R)) , 0LL);
    return max((LL)(A / B) << 1 , 0LL);
    while (1) {
        LL i = (LL)(S / H);
        if (!i) break;
        sum += i * 2;
        S -= i * H;
        S += (i * 2 * R) / W;
    }
    return sum;
}

int main(){
    //freopen("1.txt","r",stdin);
    int rmin,rmax,dmin,dmax,S;
    while (scanf("%d%d%d%d%d",&rmin,&rmax,&dmin,&dmax,&S) , S) {
    LL ans=0;
    for (int i=rmin; i<=rmax; ++i)
    for (int j=dmin; j<=dmax; ++j){
        ans += cal(i , j , S);
    }
    printf("%lld\n",ans);
    }
}
