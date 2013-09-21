//参考
//http://hi.baidu.com/nash635/blog/item/250a947fc9ad720c29388a00.html

#include <iostream>
#include <cmath>
using namespace std;

const double e = 2.7182818284590452354, pi = 3.141592653589793239;

int main()
{
    int n, m ;
    double Digits;
    cin>>n;
    while (n--) {
        cin>>m;
        Digits = 0.0;
        if (m < 100000) {
            for (int i = 1; i <= m; ++i)
                Digits += log10(i*1.0) ;
        }        
        else {        
            //1.整数位数求法(int)long10(n)+1
            //2.stirling公式---因为是一个近似公式,所以
            //  当输入m较小的时候,不能够使用公式直接计算
            // 把公式中的sqrt漏掉了,害我改了好久!!!!!!!
            Digits = log10(sqrt(2*pi*m)) + m*log10(m/e);
        }
        m = int(Digits);
        if(m <= Digits)
            ++m;
        cout<<m<<endl; 
    }
    return 0;
}

