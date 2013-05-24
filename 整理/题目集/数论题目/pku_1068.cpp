#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void get_w_sequence(string str) 
{
    int i, j, left, right;
    int len = str.length();
    stack<int> s;
    bool bIsFirst = true;
    for (i = 0; i < len; ++i) {
        if(str[i] == ')') {
            int nCount = 0;
            for (j = i; j >= 0; --j) {
                if ( str[j] == ')' ) {
                    s.push(j);
                    nCount++;
                }//if
                else { //'('
                    s.pop();  
                    if (s.size() == 0) {
                        if (bIsFirst == false) {
                            cout<<" ";
                        }
                        bIsFirst = false;
                        cout<<nCount;
                        break;
                    }                                     
                }//else
            }//for
        }//if        
    }//for
    return ;
}

int main()
{
    int t, n, p, i;
    string str;
    stack<int> s;
    cin>>t;
    while (t--) {
        cin>>n;
        str = "";
        vector<int> p(n+1, 0);
        for (i = 1; i <= n; ++i) {
            cin>>p[i];
            str = str + string(p[i]-p[i-1], '(') + ')';
        }
        get_w_sequence(str);
        cout<<endl;
    }
    return 0;
}
