//输出大于平均数的元素所占百分比，保留三位小数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, i;
    cin>>n;
    vector<double> a;
    while (n--) {
        double sum = 0.0;
        cin>>m;
        
        a.assign(m,0);
        for ( i = 0;i < m; ++i) {
            cin>>a[i];
            sum += a[i];
        }
        sum /= m;
        sort(a.begin(), a.end());
        for ( i = 0;i < m; ++i) {
            if (sum < a[i]) {
                break;
            }
        }
        printf("%.3lf%c\n",(m*1.0-i)/m*100.0,'%');
    }
    return 0;
}