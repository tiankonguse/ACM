#include <iostream>
#include <cmath>
using namespace std;
// 奇怪,居然这么诡异的题目都有
// 只需要判断输入数据n是否是2的整数次幂就可以了

int main()
{
    double n;
    int exp;
    while (cin>>n) {
        if(frexp(n, &exp) == 0.5)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;   
    }//while
    return 0;
}
