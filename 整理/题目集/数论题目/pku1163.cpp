#include <iostream>
using namespace std;

int main()
{
    long n;
    int i, j;
    long a[105][105] = {0}; //最多一百行

    cin>>n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= i; ++j) 
            cin>>a[i][j];

    for (i = n-1; i >= 1; --i) 
        for (j = 1; j <= i; ++j) 
            a[i][j] += (a[i+1][j] > a[i+1][j+1]) ? a[i+1][j] : a[i+1][j+1];

    cout<<a[1][1];    
    return 0;
}