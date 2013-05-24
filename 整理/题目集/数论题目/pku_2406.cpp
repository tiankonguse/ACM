#include <iostream>
#include <cstring>
using namespace std;

char str[1000005];

int main()
{
    int i, j, nSegs;
    while (scanf("%s", str) == 1 && strcmp(str,".")) {
        int strLen = strlen(str);
        for(i = 1; i <= strLen; ++i) {
            if(strLen%i == 0) {                
                nSegs = strLen/i; //刚好可以分为 strLen/i段,每段i个字母
                for (j = 1; j < nSegs; ++j) {
                    if(memcmp(str, str+j*i, i) < 0)
                        break;
                }
                if(j == nSegs) {
                    printf("%d\n", nSegs);
                    break;
                }
            }//if
        }
    }
    return 0;
}
