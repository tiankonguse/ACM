#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.1415926;

int main()
{
    int D, V;
    while (cin>>D>>V && !(D==0 && V==0)) {
        //圆台体积公式: 体积 = pi*h*(R^2+R*r+r^2)/3,其中,r和R分别为上下底半径,h为圆台高度
        printf("%.3lf\n", pow(D*D*D*1.0-6.0*V/pi,1.0/3));
    }
    return 0;
}
