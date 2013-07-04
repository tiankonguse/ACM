/* 阶乘末尾有多少个0，实际上只与5的因子数量有关，
即求 n/5+n/25+n/125+...... */

#include<iostream>
using namespace std;

int main()
{
    unsigned int t , n, cnt; 
    cin>>t;
    while (t--) {
        scanf("%d", &n);
        cnt = 0;
        while (n) {
            n /= 5;
            cnt+=n;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
