#pragma warning(disable:4786)
#include <iostream>
#include <algorithm>
using namespace std;

int myPre(const char& a, const char& b)
{
    if (a == b|| a+32 == b || a == b+32)//只有大小写之分的字母比较
        return a < b;
    else//不同的字母比较
        return toupper(a) < toupper(b);
}

int main()
{
    int n, len;
    char str[15];
    cin>>n;
    while (n--) {
        scanf("%s", str);
        len = strlen(str);
        sort(str, str+len, myPre);

        printf("%s\n",str);
        while(next_permutation(str, str+len, myPre)){
            printf("%s\n", str);
        }
    }
    return 0;
}




