#pragma warning (disable:4786)
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string sCommand, sURL, sCurrentPage;
    stack<string> forward;
    stack<string> backward;
    
    sCurrentPage = "http://www.acm.org/";
    
    while (cin>>sCommand) {
        if (sCommand == "QUIT") {
            break;
        }
        else if (sCommand == "VISIT") {
            backward.push(sCurrentPage);
            cin>>sCurrentPage;

            while (!forward.empty()) {
                forward.pop();
            }
        } 
        else if (sCommand == "BACK") {
            if (backward.empty()) {
                cout<<"Ignored"<<endl;
                continue;
            }
            else {
                forward.push(sCurrentPage);
                sCurrentPage = backward.top();
                backward.pop();
            }
        }
        else if (sCommand == "FORWARD") {
            if (forward.empty()) {
                cout<<"Ignored"<<endl;
                continue;
            }
            else {
                backward.push(sCurrentPage);
                sCurrentPage = forward.top();
                forward.pop();
            }
        }
        cout<<sCurrentPage<<endl;
    }
    return 0;
}
