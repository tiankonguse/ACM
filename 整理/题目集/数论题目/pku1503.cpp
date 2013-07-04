#include <iostream>
#include <string>
using namespace std;
string strs[110];
int main()
{
    char ch[105];
    int sum[110] = {0}, i;
    while (cin.getline(ch, 105) && ch != "0") {
        int len = strlen(ch);
        int j = 0;
        for (i = len-1; i >= 0; --i,++j) {
            sum[j] += (ch[i]-'0');
        }
    }
    for (i = 0; i < 110; ++i) {
        sum[i+1] += sum[i]/10;
        sum[i] %= 10;
    }
    i = 102;
    while (sum[i] == 0) {
        --i;
    }
    for (; i >= 0; --i) {
            cout<<sum[i];
    }
    return 0;
}