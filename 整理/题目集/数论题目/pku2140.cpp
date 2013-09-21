#include <iostream>
using namespace std;

int main()
{
    int n, count = 0;
    cin>>n;

    int i, j, sum;
    for (i = 1; i <= n; ++i) {
        for (j = i; j <= n; ++j) {
           sum =  (i+j)*(j-i+1)/2;
           if (sum >= n) {
               if (sum == n) {
                   ++count;   
               }
               break;               
           }
        }
    }
    cout<<count<<endl;
    return 0;
}
