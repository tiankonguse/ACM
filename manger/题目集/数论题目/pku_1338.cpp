#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int a[2000];

int main()
{
//    cout<<log10(INT_MAX)/log10(2)<<endl;
//    cout<<log10(INT_MAX)/log10(3)<<endl;
//     cout<<log10(INT_MAX)/log10(5)<<endl;
    
    int i, j, k, nth, nIndex;
    double t = 0.0;
    nIndex = 0;
    for (i = 0; i <= 32; ++i) {
        for (j = 0; j < 21; ++j) {
            for (k = 0;k <= 14; ++k) {
                t = pow(2.0, i)*pow(3.0, j)*pow(5.0, k);
                if (t <= INT_MAX) {
                    a[++nIndex] = t;
                }
            }
        }
    }
//    cout<<nIndex<<endl;
    sort(a, a+nIndex);
    while(cin>>nth && nth) {    
        cout<<a[nth]<<endl;
    }
    return 0;
}


/*nclude <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int s=1,k,i=1;
    int a[1501];
    while(s<=1500) {
          k=i;
          int flag=0;
          while(k%2==0) k/=2;
          while(k%3==0) k/=3;
          while(k%5==0) k/=5;
          if(k==1)  {
            a[s]=i;
            s++;
          }
          i++;
    }
    int n;
    while(cin>>n)
    {
       if(n==0)  break;
       cout<<a[n]<<endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
*/