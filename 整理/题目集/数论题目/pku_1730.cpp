#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;

typedef __int64 i64;

i64 max0 = 4294967296, max1 = (i64)sqrt(1.0*max0), max2 = (i64)pow(1.0*max0, 1.0/3);

vector<vector<i64> > a(1628, vector<i64>(33,0));
vector<vector<i64> > a1(max1-max2+10, vector<i64>(3,0));

int main()
{
    i64 t;
    long x, p, i, j;
    
    for (i = 2; i <= 1627; ++i) {
        t = i;
        for (p = 1; p <= 32; ++p) {
            a[i][p] = t;
            t *= i;
            if (t*i > max0 ) break;
        }
        a[i][0] = p;
        //cout<<"p: "<<p<<"    ";
    }
    
    for (i = 0; i <= max1-max2; ++i) {
        a1[i][0] = 2;
        a1[i][1] = max2+i;
        a1[i][2] = (max2+i)*(max2+i);
    }
    
    bool flag;
    while (scanf("%d", &x) == 1 && x) {
        if (x > 0) {           
            flag = false;
            for (i = 2; i <= 1627 && flag == false; ++i) {
                for (j = 1; j <= a[i][0]; ++j) {
                    if (a[i][j] == x) {
                        printf("%d\n",j);
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == true) continue;
            for (i = 0; i < max1-max2+3; ++i) {
                if(a1[i][1] == x) {
                    printf("1\n");
                    flag = true;
                    break;
                }
                else if(a1[i][2] == x) {
                    printf("2\n");
                    flag = true;
                    break;
                }
            }
            if(flag == false) 
                printf("1\n");
        }
        else {     
            x = -x;
            flag = false;
            for (i = 2; i <= 1627 && flag == false; ++i) {
                for (j = 1; j <= a[i][0]; i+=2) {
                    if (a[i][j] == x) {
                        printf("%d\n",j);
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == true) continue;
            for (i = 0; i < max1-max2+3; ++i) {
                if(a1[i][1] == x) {
                    printf("1\n");
                    flag = true;
                    break;
                }
            }
            if(flag == false) 
                printf("1\n");
        }

    }
    return 0;
}
