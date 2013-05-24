#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
    string str;
    int nInversions;
}DNA;

int getInversions(const string& str)
{
    int count = 0, len = str.length();
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j)
            if (str[i] > str[j]) count++;
    }
    return count;
}

int main()
{
    int n, m, i, j;
    cin>>n>>m;
    vector<DNA> asDNA(m,DNA());
 
    for (i = 0; i < m; ++i) {
        cin>>asDNA[i].str;
        asDNA[i].nInversions = getInversions(asDNA[i].str);
    }
    
    for (i = 0; i < m; ++i) {
        int temp = 1000;
        int index = -1;
        for (j = 0; j < m; ++j) {
            if (asDNA[j].nInversions < temp) {
                temp = asDNA[j].nInversions;
                index = j;      
            }
        } 
        asDNA[index].nInversions = 2000;
        cout<<asDNA[index].str<<endl;
    }
    return 0;
}