#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
int H , h , m , s;

int main(){
    //freopen("1.txt" , "r" , stdin);
    while (scanf("%d%d%d%d" , &H,&h,&m,&s) , H || h || m || s ) {

        LL T = h * 3600 + m * 60 + s;
        for (int k = 0 ; k < (119 * H - 1) * 2 ; ++ k) {
            double t = 3.6e3 * k * H / (119 * H - 1);
            if (t < T - 1e-6) continue;
            double x = 1 / (10.0 * H) * t;
            double y = 0.1 * t;
            double z = 6 * t;
            x -= floor(x / 360.0) * 360.0;
            y -= floor(y / 360.0) * 360.0;
            z -= floor(z / 360.0) * 360.0;
            if (fabs(x - y) < 1e-6 || fabs(x - z) < 1e-6 || fabs(z - y) < 1e-6)
                continue;
            LL a = (LL)3600 * k * H;
            LL b = 119 * H - 1;
            LL c = __gcd(a , b);
            a /= c , b /= c;
            //printf("%lld %lld\n" , a , b);
            LL d = a / b;
            //printf("%lld\n" , d);
            a = a % b + (d % 60) * b , d /= 60;
            printf("%lld %lld " , (d / 60) % H , d % 60);
            printf("%lld %lld\n" , a , b);
            break;
        }


    }

}
