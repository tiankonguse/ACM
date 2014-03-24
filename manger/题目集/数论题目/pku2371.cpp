#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long n,m, i, t;
    cin>>n;
    vector<int> a(n+1);

    a[0] = -1;
    for (i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    char str[128];
    getchar();
    cin.getline(str, 128);
    cin>>m;
    for (i = 1; i <= m; ++i ) {
        cin>>t;
        cout<<a[t]<<endl;
    }
    
    return 0;
}