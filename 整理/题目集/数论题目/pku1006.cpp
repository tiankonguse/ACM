/*
该问题可参考“中国同余定理”来求解
因为只有三个数23 28 33 且三个数两两互为质数，所以“中国剩余定理”可知
对于每一组输入数据p e i d，所求结果为
n = (R1*p + R2*e + R3*i)%21252-d
其中R1%p=1, R2%e=1, R3%i=1;
R1 =  5544 = 28*33* 6; //28 33 的公倍数中能被23除余1的最小整数
R2 = 14221 = 23*33*19; //23 33 的公倍数中能被28除余1的最小整数
R3 = 1288  = 23*28* 2; //23 28 的公倍数中能被33除余1的最小整数
为了保证结果大于等于1且小于等于21252，结果修正为：
n = (R1*p + R2*e + R3*i - d + 21252)%21252
如果n为0，则n = 21252为所求。
*/

//pku1006.cpp
//朱磊 2008-03-28

#include <iostream>
using namespace std;

int main()
{
    int p, e, i, d;
    int res, n = 1, max = 21252;
    
    while (cin>>p>>e>>i>>d && p != -1) {
        res = ((5544*p + 14421*e + 1288*i)%max - d + max)%max;
        if (res == 0) {
            res = max;
        }
        cout<<"Case "<<n++<<": the next triple peak occurs in "<<res<<" days."<<endl;
    }
    return 0;
}
