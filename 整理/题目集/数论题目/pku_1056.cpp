#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool stringCompare(const string& a, const string& b)
{
    return a.size()<b.size();
}

int main()
{
    vector<string> a;
    string str;
    int nCounter = 1;
    while (cin>>str) {
        if(str != "9"){
            a.push_back(str);
        }
        else {
            sort(a.begin(), a.end(), stringCompare);

            bool flag = true;
            int strNums = a.size();
            for (int i = 0; i < strNums && flag == true; ++i) {
                int len = a[i].size();
                for (int j = i+1; j < strNums && flag == true; ++j) {
                    if (a[i] == a[j].substr(0,len)) {
                        flag = false;
                    }
                }
            }
            if (flag == true) {
                printf("Set %d is immediately decodable\n", nCounter++);
            }
            else {
                printf("Set %d is not immediately decodable\n", nCounter++);
            }
            a.clear();
        }    
    }
    
    return 0;
}
