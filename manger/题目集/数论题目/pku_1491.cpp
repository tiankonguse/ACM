#include <iostream>
#include <cmath>
using namespace std;

int arr[55];
int gcd(int a, int b)
{
    if (b == 0) 
        return a;
    else
        return gcd(b, a%b);
}
int main()
{
    double pi;
    int n, i, j, pairs, pairs0;    

    while (cin>>n && n) {
        for (i = 1; i <= n; ++i) {
            cin>>arr[i];
        }
        pairs = 0;
        for (i = 1; i <= n-1; ++i) {
            for (j = i+1; j <= n; ++j) {
                if (gcd(arr[i], arr[j]) == 1) {
                    ++pairs;
                }
            }
        }
        if (pairs == 0) {
            cout<<"No estimate for this data set."<<endl;
                continue;
        }
        pairs0 = n*(n-1)/2;
        pi = sqrt(6.0*pairs0/pairs);
        printf("%.6lf\n", pi);
        
    }    
    return 0;
}
