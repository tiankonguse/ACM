#include <iostream>
#include <algorithm>
using namespace std;

int aNums[1005];
int aMaxLen[1005];
int main()
{
    int n, i, j;
    cin>>n;
    for (i = 1; i <= n; ++i) {
        cin>>aNums[i];
    }

    aMaxLen[1] = 1;
    for (i = 2; i <= n; ++i) {
        int nTemp = 0;
        for (j = 1; j < i; ++j) {
            if (aNums[j] < aNums[i] && nTemp < aMaxLen[j]  ) {
                    nTemp = aMaxLen[j];
            }
        }
        aMaxLen[i] = nTemp+1;
    }

    cout<<*max_element(aMaxLen+1, aMaxLen+1+n)<<endl;
    return 0;
}
