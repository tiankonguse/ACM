#include <iostream>
#include <string>
using namespace std;
//           0123456789
string n1 = "- -- -----";
string n2 = "|   ||| ||";
string n3 = "|||||  |||";
string n4 = "  ----- --";
string n5 = "| |   | | ";
string n6 = "|| |||||||";
string n7 = "- -- -- --";

#define maxWidth 120
#define maxHeight 23
char a[maxHeight][maxWidth];

int main()
{
    int s;
    string sNum;
    bool bFirstCase = true;
    int y0, i, j, k, r, c;
    while (cin>>s>>sNum && s) {
        memset(a, ' ', maxWidth*maxHeight);
        k = sNum.size();
        if (bFirstCase == false) {
            cout<<endl;
        }
        bFirstCase = false;

        for (int kk = 0; kk < k; ++kk) {
            int nDigit = sNum[kk]-'0';
            if(kk == 0)
                y0 = 0;
            else
               y0 = kk*(s+2)+kk;

            for (j = y0+1; j <= y0+s; ++j) {
                a[0][j] = n1[nDigit];
                a[s+1][j] = n4[nDigit];
                a[2*s+2][j] = n7[nDigit];
            }
            for (i = 1; i <=  s; ++i){
                a[i][y0] = n2[nDigit];
                a[i+s+1][y0] = n5[nDigit];
                a[i][y0+s+1] = n3[nDigit];
                a[i+s+1][y0+s+1] = n6[nDigit];
            }
        }//for

        for (r = 0; r < 2*s+3; ++r) {
            for (c = 0; c < k*(s+3)-1; ++c) {
                cout<<a[r][c];
            }
            cout<<endl;
        }
    }    
    return 0;
}
