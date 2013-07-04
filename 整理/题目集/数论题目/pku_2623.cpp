#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    unsigned long n, i;
    
    cin>>n;
    vector<unsigned long> a(n+1);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());

    if (n%2 == 1) {
        printf("%d.0\n", a[(n+1)/2]);
    }
    else {
        double x = (a[n*0.5]+ a[n*0.5+1])*0.5;
        printf("%.1lf\n", x);
    }
    return 0;
}
