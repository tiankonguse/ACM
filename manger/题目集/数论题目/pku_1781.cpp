//约瑟夫斯问题 --  算法有改进
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int  n, xy, z;
    while (scanf("%de%d", &xy, &z) == 2 && xy+z != 0) {
        n = xy * pow(10.0, z);
        frexp(1.0*n, &z);
        cout<<setprecision(10)<<(n - pow(2.0, z-1))*2+1<<endl;        
    }   
    return 0;
}
