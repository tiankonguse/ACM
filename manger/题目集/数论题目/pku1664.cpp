#include <iostream>
using namespace std;

/*m-苹果数;n-盘子数*/
int place(int m, int n)
{
    if(m == 1 || n == 1) {
        return 1;  
    }
    
    if(m < n) {   
        return place(m, m);
    }
    else if (m == n) {
        return 1 + place(m, n-1);
    }
    else {
        return place(m-n, n) + place(m, n-1); //没有空盘+至少有一个空盘
    }
}


int main()
{
    int t, m, n;
    cin>>t;
    while (t--) {
        cin>>m>>n;
        cout<<place(m,n)<<endl;
    }   
    return 0;
}