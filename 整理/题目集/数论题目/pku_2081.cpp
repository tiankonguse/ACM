#include <iostream>
using namespace std;

const int maxNum = 2600005;
bool bUsed[maxNum];//标记数组
int ans[500001];//已经算出的值

int main()
{
    long n, a, t;

    memset(ans, 0, 500001*sizeof(int) );
    memset(bUsed, false, maxNum*sizeof(bool));
    
    a = 0;  bUsed[a] = true;
    for (long m = 1; m <= 500000; ++m) {
        t = a-m;
        if (t >= 0 && bUsed[t] == false) 
            a = t;
        else
            a = a+m;
        bUsed[a] = true;
        ans[m] = a;
    }

    while (scanf("%d", &n) == 1 && n != -1) {
        cout<<ans[n]<<endl;
    }
    return 0;
}