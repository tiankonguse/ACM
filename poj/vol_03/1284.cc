#include"iostream"
#include"cmath"
using namespace std;
unsigned euler(unsigned x)
{// 就是公式
    unsigned i, res=x;
    int m=(int)sqrt(x * 1.0) + 1;
    for (i = 2; i < m; i++)
    if(x%i==0) {
    res = res / i * (i - 1);
    while (x % i == 0) x /= i; // 保证i一定是素数
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
}
int main(){
    int p;
    while(~scanf("%d",&p)){
       printf("%d\n",euler(p-1));
    }
    return 0;
}
