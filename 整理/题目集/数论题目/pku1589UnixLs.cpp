#pragma  warning (disable:4786)
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n, i, j;
    while (cin>>n) {
        int maxLen = 0;
        vector<string> v(n);
        for (i = 0; i < n; ++i) {
            cin>>v[i];
            if ( v[i].length() > maxLen) 
                maxLen = v[i].length();
        }
        sort(v.begin(), v.end());
        int nRows, nColums;
        nColums = (60+2)/(maxLen+2);
        if (n%nColums == 0)
            nRows = n/nColums;
        else 
            nRows = n/nColums + 1;
        
        cout<<string(60,'-')<<endl;
        for (i = 0; i < nRows ; ++i) {
            for (j = 0; j < nColums-1; ++j) {
                if (j*nRows+i < n) 
                    cout<<left<<setw(maxLen+2)<<v[j*nRows+i];
            }
            if (j*nRows+i < n)
                cout<<left<<v[j*nRows+i];
            cout<<endl;
        }        
    }
    return 0;
}