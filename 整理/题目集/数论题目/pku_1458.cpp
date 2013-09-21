#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<short> > aMaxLen;

int main()
{
    string x, y;
    int nLen1, nLen2, i, j;
    
    while (cin>>x>>y) {
        x = " " + x;
        y = " " + y;
        nLen1 = x.size();
        nLen2 = y.size();
        aMaxLen.assign(nLen1, vector<short>(nLen2,0));

        for (i = 1; i < nLen1; ++i) {
            for (j = 1; j < nLen2; ++j) {
                if (x[i] == y[j]) 
                    aMaxLen[i][j] = aMaxLen[i-1][j-1]+1;
                else {
                    if (aMaxLen[i][j-1] > aMaxLen[i-1][j]) 
                        aMaxLen[i][j] = aMaxLen[i][j-1];                    
                    else 
                        aMaxLen[i][j] = aMaxLen[i-1][j];                    
                }
            }
        }

        printf("%d\n",aMaxLen[nLen1-1][nLen2-1]);
    }
    return 0;
}
